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

int main(){
	int t , n , k;
	cin >> t;
	while ( t-- ){
		cin >> n >> k;
		if( n <= k ){
			int i = 0;
			if( k % n == 0 ) cout << k/n << endl;
			else cout << k/n+1 << endl;
		}
		else {
			if( n % k == 0 ) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}
