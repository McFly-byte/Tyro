/**
 *    author:  McFly
 *    created: 25.12.2020  
 *	  describ: 有多少数是其他数的和，而不是任意两个数的和在数组中有几组 
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
	int T, n, cnt = 0;
	vector<int> v,t;
	cin >> T;
	while ( T-- ){
		cin >> n;
		v.pb( n ); 
	}
	sort( all(v) );
	rep( i, 0, v.size()-1 ){
		rep( j, i+1, v.size() ){
			n = v[i] + v[j];
			if( find( all(v) , n ) != v.end() && find(all(t), n) == t.end() ){
				cnt++;
				t.pb( n );
			}
		}
	}
	cout << cnt << endl;
}
