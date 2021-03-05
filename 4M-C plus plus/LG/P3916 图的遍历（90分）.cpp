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
#define PI 3.1415926535897932385
#define MOD 1000000007LL
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define mp make_pair
#define pb push_back
#define rt insert
#define it iterator
typedef long long ll;

#define maxn 100001
vector<int> g[maxn];
int r[maxn];
bool isvstd[maxn];

void dfs( int i , int x ){
	if( isvstd[x] ) {
		if( r[x] > r[i] ) r[i] = r[x];
		return ;
	}
	isvstd[x] = true;
	if( x > r[i] ) r[i] = x;
	rep( j,0,g[x].size() ) dfs( i,g[x][j] );
}

int main()
{
	int n,m,a,b;
	cin >> n >> m;
	rep( i,0,m ) {
		cin >> a >> b;
		g[a].pb(b);
	}
	ret( i,1,n ){
		memset(isvstd,0,n+1);
		dfs( i, i );
	}
	ret( i,1,n ) cout << r[i] << ' ';
}
