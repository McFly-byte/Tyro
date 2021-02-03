// 线性筛 O(N) 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int prime[maxn];//存放prime数 
bool a[maxn];//也可以是int数组 

void isPrime( int n ){
	memset( a , 1 , n*sizeof(int) );
	int tot = 0;
	for ( int i = 2; i <= n; i++ ){
		if( a[i] ) prime[tot++] = i;//只有质数才添加到prime[]，
									//但每个数都要进入下面循环 
		for ( int j = 0; j < tot && i*prime[j] <= n; j++ ){
			a[i*prime[j]] = 0;
			if( i % prime[j] == 0 ) break;//把prime[j]当作当前要筛掉数的最小因子
			//若 prime[j] | i 则说明其后（此时i*prime[j]已被筛）的i*prime[j+1...]
			//都起码有一个比prime[j+1...]更小的因子prime[j]，则可退出本循环 
		}
	}
	//简单输出 
	for ( int k = 0; k < tot; k++ ) cout << prime[k] << endl;
}

int main(){
	int n;
	cin >> n;
	isPrime( n );
}
