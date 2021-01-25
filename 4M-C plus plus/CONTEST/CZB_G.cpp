#include <bits/stdc++.h>
using namespace std;

#define eps 10e-6
#define _rep(k,l,r) for( int k = l; k <= r; k++ )
#define _for(k,l,r) for( int k = l; k < r; k++ )

struct node{
	int id;
	int val;
	node* Next;
};
typedef node * ptr;

int main()
{
	int n,m;
	cin >> n >> m;
	ptr a,rear;
	a = (ptr)malloc( sizeof( node ) );
	a->Next = NULL;
	rear = a;
	for( int i = 1 ; i <= n; i++ ){
		ptr tmp = (ptr)malloc( sizeof( node ) );
		tmp->id = i;
		cin >> tmp->val;
		tmp->Next = rear->Next;
		rear->Next = tmp;
		rear = rear->Next; 
	}
	while ( m-- ){
		
	}
}
