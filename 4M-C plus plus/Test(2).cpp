#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;

#define maxn 100000003
int prime[maxn];//���prime�� 
bool a[maxn];//Ҳ������int���� 
int tot = 0;

bool hw(int n) {//�ж����ģ�������ο����ַ�ת 
	int rn = 0;
	int num = n;
	while(n!=0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	if( rn == num )//�ж��Ƿ���� 
		return true;
	return false;
}


int main() {
	int i,n,m;
	cin >> n >> m;  //���������� 

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
