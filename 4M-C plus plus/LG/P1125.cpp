#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define lw "Lucky Word"

bool isP( int n ){
	if( n <= 1 ) return false;
	if( n == 2 || n == 3 || n == 5 || n == 7 ) return true;
	ret( i, 2, n/2 ){
		if( n%i == 0 ) return false;
	}
	return true;
}
short int al[27] = {0};

int main()
{
	int mx,mn;
	string str;
	cin >> str;
	int len = str.length();
	rep( i, 0, len ){
		al[str[i]-'a'+1]++;
	}
	sort( &al[1], &al[27], greater<int>() );
	for( int i = len-1; i >= 1; i-- ) if( al[i] != 0 ) {
		mn = al[i]; break;
	}
	mx = al[1]; 
	if( isP( mx-mn ) ) cout << lw << endl << mx-mn << endl;
	else cout << "No Answer" << endl << 0 << endl;
}
