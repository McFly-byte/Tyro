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

string s;

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	ll n,one=0,two=0,ans=0;
	cin >> n >> s;
	int len = s.length();
	rep( i,0,len ){
		if( one == n ) {
			ans+=one;
			continue;
		}
		if( one + two*2 == n ){
			if( s[i] != '2' ){
				if( two != 0 ){
					two--;
					one++;
				}
			}
		}
		else{
			if( s[i] == '1' )
				one++;
			else{
				if( one + (two+1)*2 <= n ) two++;
			}
		}
		ans += (one+two);
	}
	cout << ans << endl;
}	

