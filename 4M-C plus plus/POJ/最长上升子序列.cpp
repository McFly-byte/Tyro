#include <bits/stdc++.h>
using namespace std;

#define Maxn 10000

int main()
{
	int MaxLen[Maxn];
	int N ;
	cin >> N;
	int a[N];
	for( int i = 0 ; i < N ; i++ ){
		cin >> a[i];
		MaxLen[i] = 1;
	}
	for( int i = 1 ; i < N ; i++ ){
		for( int j = 0 ; j < i ; j++ ){
			if( a[j] < a[i] ) {
				MaxLen[i] =  max( MaxLen[i] , MaxLen[j] + 1 );
			}
		}
	}
	sort( MaxLen , MaxLen+N , greater<int>() );
	cout << MaxLen[0] << endl;
 } 
