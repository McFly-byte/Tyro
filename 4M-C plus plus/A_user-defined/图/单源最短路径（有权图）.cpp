/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 有权图，单源最短路径 
 *			   将dist存入最小堆（priority_queue）中会出现 
 *             两个问题：1）dist同时实现更新和弹出最小值	2）不连通图 
 *			   于是用傻瓜做法O(V^2+E)的遍历找最小，不连通就输出预置的INF 
 *							    
**/
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef unsigned int uint;
typedef uint Vertex;
typedef uint Distance;
#define MAXN 500005
#define INF 0x7FFFFFFF

/*
struct DNode{
	Distance distance;
	Vertex vertex;
	bool operator<( const DNode &n ) const { 
		if( distance == n.distance ) return vertex > n.vertex; 
		return distance > n.distance;
	}
};
DNode d;//be used to inputing 
priority_queue<DNode> heap;//用堆来获得distance最小的结点 
*/
Distance dist[MAXN];//s到v的最短路径长度（经过的点都已被收录） 
Vertex path[MAXN];//路径 
bool isCollected[MAXN];//是否已确定了最短路径 

typedef struct ENode{
	Vertex V2;
	Distance Weight;
	ENode * Next_Edge;
} *edge;
edge e; //be used to inputing

typedef struct GHead{
	Vertex V1;
	ENode * Next_Edge;
} G[MAXN],graph;
G g;//邻接表存储连通图 

Vertex n,m,s,head,rear,weight;//require inputing

void Dijkstra();

int main()
{ 
	cin >> n >> m >> s;
	//建图 
	for ( int i = 1; i <= n; i++ ){
		g[i].V1 = i;
		g[i].Next_Edge = NULL;
		isCollected[i] = false; 
		path[i] = -1;
//		d.vertex = i;
		dist[i] = INF;
	}
	dist[s] = 0;
	for ( int i = 1; i <= m; i++ ){
		cin >> head >> rear >> weight; //有权图 
		e = (edge)malloc(sizeof(struct ENode));
		e->V2 = rear;
		e->Weight = weight;
		e->Next_Edge = g[head].Next_Edge;
		g[head].Next_Edge = e;
	}
	Dijkstra();
	for ( int i = 1; i <= n; i++ ) cout << dist[i] << ' ';
	cout << endl; 
} 

void Dijkstra()
{
	Vertex v,i;
	Distance d; 
	while( 1 ){
/*
		if( heap.empty() ) break;
		d = heap.top(); //cout << d.vertex << ' ' << d.distance << endl; 
		heap.pop();
		v = d.vertex;
*/
		//找到dist值最小的点v 
		for ( v=d=-1,i=1; i <= n; i++ ) 
			if( dist[i] < d && !isCollected[i]) {
				d = dist[i];
				v = i;
			}
		//找不到则退出循环 
		if( v==-1 ) break;
		//对此V遍历其周围的点 
		isCollected[v] = true;
		e = g[v].Next_Edge;
		while( e ){
			if( isCollected[e->V2] == false )
				if( dist[v]+e->Weight < dist[e->V2] ){
//					cout << e->V2 << ' ' << e->Weight << endl;
//					cout << '	' << dist[e->V2] << endl; 
					dist[e->V2] = dist[v]+e->Weight;
					path[e->V2] = v; 
//					cout << '	' << dist[e->V2] << endl;;
				}
			e = e->Next_Edge;
		}
	}
}
