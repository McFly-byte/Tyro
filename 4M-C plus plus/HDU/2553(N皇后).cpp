#include <bits/stdc++.h>
using namespace std;

#define maxn 20
int n , ans;
int q[maxn], show[maxn];
void NQueen( int k );

int main()
{
	for ( n = 1; n <= 10; n++ ){
		ans = 0;
		NQueen( 0 );
		show[n] = ans;
	}
	while ( cin >> n && n ){
		cout << show[n] << endl;
	}
}

void NQueen( int k )
{
	if( k == n ){
		ans++;
		return ;
	}
	for ( int i = 0; i < n; i++ ){
		int j;
		for ( j = 0; j < k; j++ ){
			if( i == q[j] || abs(k-j) == abs(i-q[j]) ) break;
		}
		if( j == k ){
			q[k] = i;
			NQueen( k+1 );
		}
	}
}
