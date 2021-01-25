/**
 *    author:  McFly
 *    created: 30.12.2020  
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
 
int main()
{
	int T;
	cin >> T;
	int n;
	while ( T-- ){
		cin >> n;
		int a[n];
		rep( i, 0, n ) cin >> a[i];
		vector<int> v;
		rep( i, 0, n ){
			rep( j, i+1, n ){
					v.pb( a[j]-a[i] );
			}
		}
		sort( all(v) );
		v.erase( unique( all(v) ), v.end() );
		cout << v.size() << endl;
	}
} 
