/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 用向量装载图 
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

#define maxn 1001
vector<int> g[maxn];//图 
bool isvisited[maxn]; //bfs不递归，但也要判断是否访问过，因为是无向图 

int bfs( int i )
{
	queue<int> q;
	q.push( i );
	isvisited[i] = true;
	int cnt = 1, level = 0, last = i, tail =i;
	while( !q.empty() ){
		int d = q.front();
		q.pop();	
//		cout << d << "--" ;
		for ( int j = 0; j < g[d].size(); j++ )
			if( !isvisited[g[d][j]] ){
				isvisited[g[d][j]] = true;
//				cout << g[d][j] << ' ';
				q.push( g[d][j] );
				cnt++;//每次入队时计数 
				tail = g[d][j];//tail标记当前队列中最后一个，
							   //在循环结束时可用来标记一层（level）中最后一个该出队的元素（即last） 
			}	
//		cout << endl;
		if( d == last ) { //level更新看的是层数 
			level++; 
			last = tail;
		}
		if( level == 6 ) break; // 因为是从0开始计数的 
	}
	return cnt;
}

int main()
{
	int n,m,a,b;
	cin >> n >> m;
	rep( i,0,m ) {
		cin >> a >> b;
		g[a].pb( b );
		g[b].pb( a );//双向图 
	}
	ret( i,1,n ) {
		memset( isvisited,0,maxn );//必做 
		cout << i << ": " << pcsn(2) << double(100*bfs( i ))/n << '%' << endl; 
	}
}

