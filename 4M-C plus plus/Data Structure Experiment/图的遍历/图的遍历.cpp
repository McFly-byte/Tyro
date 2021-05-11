/**
 *    author:  McFly
 *    created: 05.2021 
 *	  describ:  	ͼ�ı���
 *					������һ�������ڽӱ�����ڽӾ���洢������ͼ
 * 					Ŀ�꣺1���÷ǵݹ��㷨ʵ����Ⱥ��߹�ȱ���һ������ͼ����������������ע�������ͼ����ͨ��������Ҫ��α�����
 *           			  2���÷ǵݹ��㷨ʵ��Kruskal�㷨��Prim�㷨		
 *					���� 100\%100% �����ݣ�1<=N<=5000  1��M��2*10^5.
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
int Map[MAXN][MAXN];//�ڽӾ���ʵ��ͼ 
priority_queue<Edge> Heap; 
int N,M;//����\����Ŀ
bool vis[MAXN];
int dist[MAXN]; 
int parent[MAXN];
int root[MAXN];

void InitMap();
void DFS();	//�ǵݹ�ʵ�� 
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
	cout << "\nPrim��С��������Ȩֵ��: ";
	Prim();
	cout << "Kruskal��С��������Ȩֵ��: ";
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
		if( e.z < Map[e.x][e.y] ) { //���������д����ظ� 
			Map[e.x][e.y] = Map[e.y][e.x] = e.z;
			Heap.push( e );//kruskal�㷨
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

inline void Prim() // ��Ҫ��Ȩ 
{
	int tot = 0, mn,mid,sum = 0;
	ret( i,1,N ) dist[i] = INF;
	dist[1] = 1; //dits[1]����Ϊ1���Ա��һ������Сdist�������ټ������ɡ� 
	parent[1] = -1;
	while( 1 )
	{
		//�ҵ�����mst����ĵ� (����)
		mn = INF;
		ret( i,1,N )
		{
			if( dist[i] && dist[i] < mn ) mn = dist[i], mid = i;
		} 
		if( tot && mn == INF ) break;  
		tot++;
		sum += dist[mid];
		dist[mid] = 0;
		//����dist��parent 
		ret( i,1,N ) if( dist[i] && Map[mid][i] < dist[i] ) 
		{
			dist[i] = Map[mid][i];
			parent[i] = mid;
		} 
	} 
	if( tot != N ) printf("orz\n"); //������ͨ 
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
	if( tot != N-1 ) printf("orz\n"); //������ͨ 
	else printf("%d\n",sum);
} 
