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
	int T, n, w, sum, even;
	cin >> T;
	while ( T-- ){
		even = 0;
		sum = 0;
		cin >> n;
	//	vector<int> v;
		rep( i, 0, n ) {
			cin >> w;
			sum += w;
			if( w % 2 == 0 ) even++;
		}
		if( sum % 2 == 0 && even % 2 == 0 || sum %2==0 && n-even>=2) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
 } 
