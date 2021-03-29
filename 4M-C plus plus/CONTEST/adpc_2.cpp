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

bool igWord( string a );
bool igSent( string a );  

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	while( getline(cin,s) != NULL ){ //认为一行一句 
		if( igSent( s ) ){
			
		}
		else cout << s;
	}
}

bool igWord( string src )
{
	if( src.length() == 1 ) return false;
	string dst;
	transform(src.begin(), src.end(), back_inserter(dst), ::tolower);
	dst[0] = dst[0]-('a'-'A');
	if( dst == src ) return true;
	return false;
}

bool igSent( string src )
{
	string sub,abbr;
	int i=0,j=0,len = src.length(),cnt=0;
	bool fg = true;
	while( j<len ){
		if( i<=j && s[j] == ' ' || s[j] == ',' || s[j] == '.' ){
			sub = src.substr(i,j-i);
//			cout << i << '	' << src << ' ' << sub << endl;
			if( igWord(sub) ){
				cnt++;
			}	
			if( s[j] == ',' || s[j] == '.' ) cnt = 0;
			i = ++j;
			while( s[i] == ' ' || s[i] == ',' || s[i] == '.' ) i++;
			
		}
		j++;cout << j << endl;
	}
	if( fg && cnt >= 2 ) return true;
}

