/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:     
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

struct node{
	int Index;
	node * Next;
};
typedef node * Ptr;

int main()
{
	int n,k,v[2];
	cin >> n >> k;
	node* p[n+1];
	for ( int i = 0; i <= n; i++ ) {
		p[i] = (Ptr)malloc( sizeof( node ) );
		p[i]->Next = NULL;
	}
	while ( k-- ){
		cin >> v[0] >> v[1];
		Ptr tag = p[v[1]];
		while ( tag->Next ) tag = tag->Next;
		tag->Next = p[v[0]]->Next;
		p[v[0]]->Next = p[v[1]]->Next;
	}
	for ( int i = 1; i <= n; i++ ){
		
	}
}
