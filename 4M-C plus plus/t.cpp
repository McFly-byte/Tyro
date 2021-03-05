/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:  	递推较于搜索，省时费地			
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 1005
#define MOD 100003
int n,m,s,t;
int a[MAXN][MAXN];

//void dfs( int i, int j )
//{
////	cout << i << '	' << j << endl;
//	visited[i][j] = 1;
//	if( i == n && j == n ){
//		ans++;
//		ans %= MOD;
//		visited[i][j] = 0;
//		return ;
//	}
//	if( i+1 <= n && a[i+1][j]>=0 ) dfs( i+1,j );
//	if( j+1 <= n && a[i][j+1]>=0 ) dfs( i,j+1 );
//	visited[i][j] = 0;
//}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	while( m-- ){
		cin >> s >> t;
		a[s][t] = -1;
	} 
	for ( int i = 1; i <= n; i++ ){
		for ( int j = 1; j <= n; j++ ){
			if( a[i][j] < 0 ) continue; 
			if( i == 1 && j == 1 ) a[i][j] = 1;
			else if( i == 1 ){ 
				if( a[i][j-1] >= 0 ) a[i][j] = a[i][j-1];
			} 
			else if( j == 1 ) {
				if( a[i-1][j] >= 0 ) a[i][j] = a[i-1][j];
			} 
			else {
				if( a[i][j-1] >= 0 && a[i-1][j] >= 0 ) a[i][j] = a[i][j-1] + a[i-1][j];
				else if( a[i][j-1] >= 0 ) a[i][j] = a[i][j-1];
				else if( a[i-1][j] >= 0 ) a[i][j] = a[i-1][j];
			}
			a[i][j] %= MOD; 
		}
	}
	cout << a[n][n] << endl;
}

