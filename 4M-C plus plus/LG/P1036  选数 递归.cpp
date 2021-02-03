#include<bits/stdc++.h>
using namespace std;

const int maxn = 21;
int C[maxn][maxn];

void init( int n )
{
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ){
			if( i == j ) C[i][j] = 1;
			else 
				C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}
}

bool isPrime(long long n) {//ÅÐ¶¨ËØÊý 
	if( n <= 1 ) return false;
	long long i;
	long long maxn = sqrt(n);
	for( i = 2; i <= maxn; i++ ) {
		if( n%i == 0 )
			return false;
	}
	return true;
}

int main(){
	int n,k;
	cin >> n >> k;
	init( n );
	vector<int> v(n);
	int a[n];
	for ( long long i = 0; i < n;i ++ ) {
		cin >> v[i];
		a[i] = i;
	}
	long long num, count=0;
	do{
		num = 0;
		for ( int i = 0; i < k; i++ ) num += v[a[i]];
//		cout << num << endl;
		if( isPrime( num ) ) count++; 
	}while ( next_permutation( a , a+n ) );
	for ( long long j = 1; j <= k ; j++ ) count /= j;
	for ( long long j = 1; j <= n-k ; j++ ) count /= j; 
	cout << count << endl;
}
