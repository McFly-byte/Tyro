/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 应该往抵消方向去想，暴力会导致有些不能互删   
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

int main()
{
	int a[2][2] = {1,1,3,1};
	int b[4][2] = {1,3,2,3,3,3,4,3};
	int l=0,v=0;
	string s;
	cin >> s;
	rep( i,0,s.length() ){
		if( s[i] == '0' ){
			cout << a[l][0] <<' ' << a[l][1] << endl;
			l++;
		}
		else{
			cout << b[v][0] << ' ' << b[v][1] << endl;
			v++;
		}
		if( l == 2 ) l = 0;
		if( v== 4 ) v = 0;
	}
 } 
