// ����ɸ O(N) 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int prime[maxn];//���prime�� 
bool a[maxn];//Ҳ������int���� 

void isPrime( int n ){
	memset( a , 1 , n*sizeof(int) );
	int tot = 0;
	for ( int i = 2; i <= n; i++ ){
		if( a[i] ) prime[tot++] = i;//ֻ����������ӵ�prime[]��
									//��ÿ������Ҫ��������ѭ�� 
		for ( int j = 0; j < tot && i*prime[j] <= n; j++ ){
			a[i*prime[j]] = 0;
			if( i % prime[j] == 0 ) break;//��prime[j]������ǰҪɸ��������С����
			//�� prime[j] | i ��˵����󣨴�ʱi*prime[j]�ѱ�ɸ����i*prime[j+1...]
			//��������һ����prime[j+1...]��С������prime[j]������˳���ѭ�� 
		}
	}
	//����� 
	for ( int k = 0; k < tot; k++ ) cout << prime[k] << endl;
}

int main(){
	int n;
	cin >> n;
	isPrime( n );
}
