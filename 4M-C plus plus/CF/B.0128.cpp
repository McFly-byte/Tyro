/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ:     
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define pause system("pause")
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

bool isL( int n , int d ){
	int e = d*10;
//	cout << e << 'e' << endl;
	if( n >= e ) return true;
	else {
		while ( n >= d ){
//			cout << ' ' << n  << ' ';
			
//			cout << n << endl;
			if( n == d ) 
				return true;
			n -= d;
			if( n%10==0 ) 
				return true;
		}
		return false;
	}
}

int main(){
	int t,q,d,n;
	cin >> t;
	while ( t-- ) {
		cin >> q >> d;
		for ( int i = 0; i < q; i++ ){
			cin >> n;
			if( isL(n,d) ) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
