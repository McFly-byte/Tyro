/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: ��Ȩͼ����Դ���·�� 
 *			   ��dist������С�ѣ�priority_queue���л���� 
 *             �������⣺1��distͬʱʵ�ָ��º͵�����Сֵ	2������ͨͼ 
 *			   ������ɵ������O(V^2+E)�ı�������С������ͨ�����Ԥ�õ�INF 
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
priority_queue<DNode> heap;//�ö������distance��С�Ľ�� 
*/
Distance dist[MAXN];//s��v�����·�����ȣ������ĵ㶼�ѱ���¼�� 
Vertex path[MAXN];//·�� 
bool isCollected[MAXN];//�Ƿ���ȷ�������·�� 

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
G g;//�ڽӱ�洢��ͨͼ 

Vertex n,m,s,head,rear,weight;//require inputing

void Dijkstra();

int main()
{ 
	cin >> n >> m >> s;
	//��ͼ 
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
		cin >> head >> rear >> weight; //��Ȩͼ 
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
		//�ҵ�distֵ��С�ĵ�v 
		for ( v=d=-1,i=1; i <= n; i++ ) 
			if( dist[i] < d && !isCollected[i]) {
				d = dist[i];
				v = i;
			}
		//�Ҳ������˳�ѭ�� 
		if( v==-1 ) break;
		//�Դ�V��������Χ�ĵ� 
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
