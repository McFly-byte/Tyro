/**
 *    author:  919106840423 刘明承 
 *    created: 04.2021 
 *	  describ:  哈夫曼编码 
**/
#include <bits/stdc++.h>
using namespace std;

struct node {
	char data;
	int weight;
	node * left;
	node * right;
	node * parent;
	bool operator < ( const node & n ) const{
		return weight > n.weight;
	}
} ;

struct cmp {
	bool operator()( node* & a, node* & b ){
		return a->weight > b->weight;
	}
};

void PreTraversal( node * bt )//先序_递归(中后序一样) 
{
	if( bt ){
		cout << bt->weight << endl;
		PreTraversal( bt->left );
		PreTraversal( bt->right );
	}
} 

int main()
{
	int n;
	cin >> n;
	priority_queue<node*,vector<node*>,cmp> q;
	vector<node*> v(n);
	for ( int i = 0; i < n; i++ ){
		v[i] = (node*)malloc( sizeof( struct node ) );
		cin >> v[i]->data >> v[i]->weight;
		v[i]->parent = NULL;
		v[i]->left = v[i]->right = NULL;
		q.push( v[i] );
	} 
	node *tmp, *tmp2;
	while( !q.empty() ){
		tmp = q.top();
		q.pop();
		if( q.empty() )
			break;
		tmp2 = q.top();
		q.pop();
		node * huff = (node*)malloc( sizeof( struct node ) );
		huff->left = tmp;
		huff->right = tmp2;
		huff->parent = NULL;	//很重要，与上面for循环中的不重合 
		huff->weight = tmp->weight + tmp2->weight;
		tmp->parent = tmp2->parent = huff;
		q.push( huff );
	} 

	node * fg;
	for ( int i = 0; i < v.size(); i++ ){
		fg = v[i];
		cout << fg->data << ": ";
		string s = "";
		while( fg->parent!=NULL ){
			if( fg->parent->left == fg ) s += '0';
			else if( fg->parent->right == fg ) s += '1';
			else break;
			fg = fg->parent;
		}
		reverse( s.begin(), s.end() );
		cout << s << endl;
	}
} 
