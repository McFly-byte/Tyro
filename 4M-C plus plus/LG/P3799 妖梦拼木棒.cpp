#include <bits/stdc++.h>
using namespace std; 

#define sync; ios::sync_with_stdio(NULL),cin.tie(0);
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define MOD 1000000007LL
typedef long long ll;

int a[5050];

int main()
{
	sync;
	int n,m,max=0;
	cin >> n;
	rep( i, 0, n ) {
		cin >> m;
		if( m > max ) max = m;
		a[m]++;
	}
	ll cnt = 0;
	rep( i,0,max+1 ){
		if( !a[i] ) continue;
		rep( j,i,max+1 ){
			if( !a[j] ) continue;
			if( i+j > max ) break;
			if( a[i+j] >= 2 ) {
				if( i == j ) cnt += ( a[i]*(a[i]-1)/2 )*( a[i+j]*(a[i+j]-1)/2 );
				else cnt += ( a[i]*a[j] )*( a[i+j]*(a[i+j]-1)/2 );
				cnt %= MOD; 
			}
		}
	}
	cout << cnt << endl;
}
