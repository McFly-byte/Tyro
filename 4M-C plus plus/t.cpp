#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f //1061109567
int n,diff=INF;
vector<int> s(10), b(10);

void dfs( int i , int ss, int bb )
{
	if( i >= n ){
		if( ss == 1 && bb == 0 ) return ;
		diff = min( abs(ss-bb) , diff );
		return ;
	}
	dfs( i+1,ss*s[i],bb+b[i] );
	dfs( i+1,ss,bb );
}

int main()
{	
	cin >> n;
	
	for( int i = 0; i < n; i++ ) {
		cin >> s[i] >> b[i];
		if( s[i] == b[i] ) {
			cout << 0 << endl;
			return 0;
		}
	}
	dfs( 0,1,0 );	
	cout << diff << endl;
}
