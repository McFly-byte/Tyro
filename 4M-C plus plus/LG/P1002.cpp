#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll bd[22][22];
int pos[2][9] = {-1,-2,-2,-1,1,2,2,1,0,-2,-1,1,2,-2,-1,1,2,0};
int n,m;

#define ERROR -1

int main()
{
	int a,b;
	cin >> n >> m >> a >> b;
	for ( int i = 0; i <= 8; i++ ){
		if( a+pos[0][i] <= n && b+pos[1][i] <= m 
			&& a+pos[0][i] >= 0 && b+pos[1][i] >= 0 )   
			bd[a+pos[0][i]][b+pos[1][i]] = ERROR;
	}
	for ( int j = 0; j <= m; j++ ) 
		if( bd[0][j] != ERROR ) bd[0][j] = 1;
		else break;
	for ( int i = 0; i <= n; i++ )
		if( bd[i][0] == ERROR ) break;
		else bd[i][0] = 1;
	for ( int i = 1; i <= n; i++ ){
		for ( int j = 1; j <= m; j++ ) {
			if( bd[i][j] < 0 ) continue;
			bd[i][j] = max(bd[i-1][j],(ll)0) + max(bd[i][j-1],(ll)0);
		}
	} 
//	for ( int i = 0; i <= n; i++ ){
//		for ( int j = 0; j <= m; j++ ) 
//			cout << setw(3) << bd[i][j] ;
//			cout << endl;
//	}
	cout << bd[n][m] << endl;
}
