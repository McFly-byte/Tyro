/**
 *    author:  McFly
 *    created: 05.2021 
 *	  describ:  	图的遍历
 *					输入是一个基于邻接表或者邻接矩阵存储的无向图
 * 					目标：1）用非递归算法实现深度和者广度遍历一个无向图，并输出遍历结果，注意如果该图不连通，可能需要多次遍历。
 *           			  2）用非递归算法实现Kruskal算法和Prim算法		
 *					对于 100\%100% 的数据：1<=N<=5000  1≤M≤2*10^5.
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

struct Edge{
	int x,y;
	int z;
	bool operator < ( const Edge & x ) const
	{
		return z > x.z;
	}
}e;

#define MAXN 5005 
int Map[MAXN][MAXN];//邻接矩阵实现图 
priority_queue<Edge> Heap; 
int N,M;//顶点\边数目
bool vis[MAXN];
int dist[MAXN]; 
int parent[MAXN];
int root[MAXN];

void InitMap();
void DFS();	//非递归实现 
void BFS();
void Prim();
int getRoot( int );
void Kruskal();

int main()
{
//	ios_base::sync_with_stdio(false),cin.tie(0);
	InitMap();
	cout << "BFS: ";
	BFS();
	cout << "DFS: ";
	DFS(); 
	cout << "\nPrim最小生成树边权值和: ";
	Prim();
	cout << "Kruskal最小生成树边权值和: ";
	Kruskal();
}

void InitMap()
{
	scanf("%d %d",&N,&M);
	ret( i,1,N )
	{
		ret( j,1,N )
		{
			if( i == j ) Map[i][j] = 0;
			else Map[i][j] = INF;
		}
	 } 
	ret ( i,1,M )
	{
		scanf("%d %d %d",&e.x,&e.y,&e.z); 
		if( e.z < Map[e.x][e.y] ) { //输入数据有大量重复 
			Map[e.x][e.y] = Map[e.y][e.x] = e.z;
			Heap.push( e );//kruskal算法
		}
	}
}

void DFS()
{
	memset(vis,0,sizeof( vis ) );
	stack<int> S;
	S.push( 1 );
	vis[1] = 1;
	int v;
	while( !S.empty() )
	{
		v = S.top();
		S.pop();
		printf("%d ",v);
		for ( int i = N; i > 0 ; i-- ) 
			if( Map[v][i] > 0 && Map[v][i] < INF && !vis[i] ) 
				S.push( i ), vis[i] = 1;
	 } 
}

void BFS()
{
	queue<int> Q;
	memset(vis,0,sizeof(vis));
	Q.push( 1 );
	vis[1] = 1;
	int v;
 	while( !Q.empty() )
	{
		v = Q.front();
		Q.pop();
		printf("%d ",v);
		ret( i,1,N )
			if( Map[v][i] > 0 && Map[v][i] < INF && !vis[i] ) 
				Q.push(i),vis[i] = 1;
	} 
	cout << endl;
}

inline void Prim() // 不要负权 
{
	int tot = 0, mn,mid,sum = 0;
	ret( i,1,N ) dist[i] = INF;
	dist[1] = 1; //dits[1]先置为1，以便第一次找最小dist。后面再减掉即可。 
	parent[1] = -1;
	while( 1 )
	{
		//找到距离mst最近的点 (暴力)
		mn = INF;
		ret( i,1,N )
		{
			if( dist[i] && dist[i] < mn ) mn = dist[i], mid = i;
		} 
		if( tot && mn == INF ) break;  
		tot++;
		sum += dist[mid];
		dist[mid] = 0;
		//更新dist及parent 
		ret( i,1,N ) if( dist[i] && Map[mid][i] < dist[i] ) 
		{
			dist[i] = Map[mid][i];
			parent[i] = mid;
		} 
	} 
	if( tot != N ) printf("orz\n"); //若不连通 
	else printf("%d\n",sum-1);
}

int getRoot( int x )
{
	if( root[x] == x ) return x;
	return getRoot( root[x] );
}

inline void Kruskal()
{
	int tot = 0,a,b,sum = 0;
	ret( i,1,N ) root[i] = i; 
	while( tot < N-1 && !Heap.empty() ) 
	{
		e = Heap.top();
		Heap.pop();
		a = getRoot( e.x ), b = getRoot( e.y );
		if( a == b ) continue;
		root[b] = a;
		tot++;
		sum += e.z;
	}
	if( tot != N-1 ) printf("orz\n"); //若不连通 
	else printf("%d\n",sum);
} 
