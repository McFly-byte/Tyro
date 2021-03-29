//¶þ²æËÑË÷Ê÷ 
#include <bits/stdc++.h>
using namespace std;

typedef int Position;
typedef int ElementType;

struct TNode{
	int Value;
	TNode * Left;
	TNode * Right;
};
typedef TNode *bst;

bst CreateBinarySearchTree( int n );
bst Insert( bst BST, ElementType X );
bst Delete( bst BST, ElementType X );
bst Find( bst BST, ElementType X );
bst FindMin( bst BST );
bst FindMax( bst BST );
void Level( bst Root );

int main()
{
	int n,v;
	bst T = NULL;
	cin >> n;
	while( n-- ) {
		cin >> v;
		T = Insert(T,v);
	}
	Level( T );
}

bst Insert( bst T, ElementType v )
{
	if( !T ){
		T = (bst)malloc(sizeof(struct TNode));
		T->Value = v;
		T->Right = T->Left = NULL;
	}
	else{
		if( v < T->Value ) T->Left = Insert(T->Left,v);
		else T->Right = Insert(T->Right,v);
	}
			return T;
}
bst Delete( bst BST, ElementType X ){
	bst T = Find( BST,X );
	if( !T ) return BST;
	else {
		if( T->Left && T->Right ){
			bst tmp = FindMax( T->Left );
			T->Value = tmp->Value;
			T->Left = Delete( T->Left,X );
		} 
		else{
			bst tmp = T;
			if( !T->Left ) T = T->Right;
			else T = T->Left;
			free( tmp );
		}
	}  
	return T;
}
bst Find( bst BST, ElementType X ){
	bst T = BST;
	while( T ){
		if( X < T->Value ) T = T->Left;
		else if( X > T->Value ) T = T->Right;
		else return T;
	}
	return NULL;
}
bst FindMin( bst BST ){
	bst T = BST;
	while( T->Left ) T = T->Left;
	return T;
}
bst FindMax( bst BST ){
	bst T = BST;
	while( T->Right ) T = T->Right;
	return T;
}
void Level( bst Root )
{
	queue<bst> Q;
	bst T = Root, fg;
	Q.push( T );
	while( !Q.empty() ){
		fg = Q.front();
		Q.pop();
		cout << fg->Value << ' ';
		if( fg->Left!=NULL ){
			Q.push( fg->Left );
			cout << "left" << fg->Left->Value << endl;
		}
		
		if( fg->Right!=NULL ) {
			Q.push( fg->Right );
			cout << "right" << fg->Right->Value << endl;
		}
	}
	cout << endl;
}
