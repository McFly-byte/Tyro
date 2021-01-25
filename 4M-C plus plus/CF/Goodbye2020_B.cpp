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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, num;
	cin >> T;
	while ( T-- ){
		cin >> n;
		vector<int> v;
		rep( i, 0, n ){
			cin >> num;
			v.pb( num );
		}
//		rep( i, 0, n ) cout << v[i];
//		cout << endl;
		rep( i, 1, n ){
			if( v[i] < v[i-1] ) v[i] = v[i-1];
			else if( v[i] == v[i-1] ) v[i]++;
//			cout << i << endl;
		}
//		rep( i, 0, n ) cout << v[i];
//		cout << endl << endl;
		sort( all(v) );
		v.erase( unique( all(v) ), v.end() );
		cout << v.size() << endl;
	}
}
