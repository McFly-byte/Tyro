/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ:     A
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
	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		string s , ans(n,'0');
		cin >> s;
		ans[0] = '1';
		bool flag = false;
		for ( int i = 1; i < n; i++ ){
			if( s[i]-'0'+1 == ans[i-1]-'0' + s[i-1]-'0' )
				ans[i] = '0';		
			else ans[i] = '1';
		}
		cout << ans << endl; 
		
	}
}
