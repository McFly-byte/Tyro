#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define EPS 10e-6
#define PI 3.1415926535897932385
#define pause system("pause");
#define rint register int //明确要求CPU把变量始终保存在寄存器里面，直至它消亡。 
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define mp make_pair
#define pb push_back
#define it iterator
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = str.length();
	ret( i, 0, len )
		if( isalpha( str[i] ) )
			if( islower( str[i] ) )
				str[i] = toupper( str[i] );
	cout << str << endl;
}
