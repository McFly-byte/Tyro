#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;

#define maxn 100000003
int prime[maxn];//存放prime数 
bool a[maxn];//也可以是int数组 
int tot = 0;

bool hw(int n) {//判定回文，不懂请参考数字反转 
	int rn = 0;
	int num = n;
	while(n!=0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	if( rn == num )//判断是否回文 
		return true;
	return false;
}


int main() {
	int i,n,m;
	cin >> n >> m;  //读入两个数 

	for ( i = 2; i <= m; i++ ){	
		
		if( !a[i] ) {
			prime[tot++] = i;
		}
		for ( int j = 0; j < tot && i*prime[j] <= m; j++ ){
			a[i*prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
		
	}
	
	for ( i = n; i <= m; i++ ) {
		if( a[i]==0 && hw(i) ) cout << i << endl;
	}

}
