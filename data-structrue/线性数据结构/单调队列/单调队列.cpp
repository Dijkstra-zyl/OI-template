#include <iostream>//P1886
#include <deque>
/*
单调:指的是元素的规律——递增或递减
队列:指的是元素只能从队头和队尾进行操作
*/
using namespace std;
const int N = 1e6+10;
int n,k;
int a[N];
void getmin(){
    deque<int> d;//存储下标 放在内部的原因是要清空(否则 WA on #11)
	for(int i = 1;i <= n;i++){
		while(!d.empty() && a[d.back()] >= a[i]) d.pop_back();//维护单调性
		d.push_back(i);//加入窗口
		while(!d.empty() && d.front() <= i-k) d.pop_front();//已经到了窗口外了
		if(i >= k) cout << a[d.front()] << " ";//i<k不输出
	}
}
void getmax(){
    deque<int> d;
	for(int i = 1;i <= n;i++){
		while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
		d.push_back(i);
		while(!d.empty() && d.front() <= i-k) d.pop_front();
		if(i >= k) cout << a[d.front()] << " ";
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	getmin();
	cout << endl;
	getmax();
	cout << endl;
	return 0;
}/*
设有以下序列且k=3(k是k个连续的序列(窗口大小))
1 3 -1 -3 5 3 6 7(所有元素:all,入队:push,出队:pop,清空队列:reset) 
维护递增 
1.1 push              {1}
2.3>1,push            {3}
3.-1<all reset & push {-1}
4.-3<all reset & push {-3}
5.5>-3 push           {-3,5}
6.-3>3<5,5 pop,3 push {-3,3}
7.-3已经在窗体外 pop 
& 6>3 push           {3,6} 
8.7>6 push            {3,6,7}
*/
