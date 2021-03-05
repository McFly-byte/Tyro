/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 无权图，单源最短路径 
**/
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef unsigned int uint;
typedef uint Vertex;
typedef uint Distance;
#define MAXN 500005

Vertex path[MAXN];
Distance dist[MAXN];

typedef struct ENode{
	Vertex V2;
	Distance Weight;
	ENode * Next_Edge;
} *edge;

typedef struct GHead{
	Vertex V1;
	ENode * Next_Edge;
} G[MAXN],graph;
G g;
queue<Vertex> q;
Vertex n,m,s,head,rear,weight;

void bfs()
{
	Vertex v;
	edge e;
	q.push( s );
	while( !q.empty() ){
		v = q.front();
		q.pop();
		e = g[v].Next_Edge;
//		cout << v << endl;
		while( e != NULL ){
			if( dist[e->V2] == -1 ){
//				cout << '	' << e->V2 << endl;
				dist[e->V2] = dist[v] + 1;//无权图，加1 
				path[e->V2] = v;
				q.push(e->V2);
			}
			e = e->Next_Edge;
		}
	}
}

int main()
{
	cin >> n >> m >> s;
	edge tmp;
	for ( int i = 1; i <= n; i++ ){
		g[i].V1 = i;
		g[i].Next_Edge = NULL;
		path[i] = -1;
		if( i != s ) dist[i] = -1;
		else dist[i] = 0;
	}
	for ( int i = 1; i <= m; i++ ){
		cin >> head >> rear; 
//		cin >> weight; //无权图 
		tmp = (edge)malloc(sizeof(struct ENode));
		tmp->V2 = rear;
		tmp->Weight = weight;
		tmp->Next_Edge = g[head].Next_Edge;
		g[head].Next_Edge = tmp;
	}
	bfs();
	for ( int i = 1; i <= n; i++ ) cout << dist[i] << ' ';
 } 
