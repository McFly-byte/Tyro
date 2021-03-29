/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:  				
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int t , n, k, ans,sum;
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		ans = n>k?n-k+k/2:min(k/2,n);
		cout << ans << endl;
		if( n > k ) ret( i,k+1,n ) cout << i << ' ';
		int x = 1;
		if( k/2 <= n )
			while( x <= k/2 ) {
				cout << k-x << ' ';
				x++;
			}	
		else 
			ret( i,1,n ) cout << i << ' ';
		if( ans ) cout << endl;
//		n>k?ans=k/2+n-k:ans=min(k/2,n);
//		cout << ans << endl;
//		ret(i,1,min(k/2,n)) cout << i << ' ';
//		ret(i,k+1,n) cout << i << ' ';
//		if( ans )
//			cout << endl;
	} 
}

