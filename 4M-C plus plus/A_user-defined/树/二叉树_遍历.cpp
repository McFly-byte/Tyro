#include <iostream>
#include <malloc.h>

using namespace std;

#define ElementType int

typedef struct TreeNode *BinTree;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};//直接改写成类 

void PreTraversal( BinTree bt )//先序_递归(中后序一样) 
{
	if( bt ){
		cout << bt->Data << endl;
		PreTraversal( bt->Left );
		PreTraversal( bt->Right );
	}
} 

void Tra( BinTree bt )	//中序_Stack 非递归 
{
	BinTree T = bt;
	Stack S = ( Stack )malloc( sizeof( sNode ) );
	//这个Stack也得自己写... 
	while( T || !isEmpty(S) ){
		while( T ){
			push( S, T );
			T = T->Left;
		}
		if( !isEmpty(S) ){
			T = pop( S );
			cout << T->Data << endl ;
			T = T->Right;
		}
	}
}

void Level( BinTree bt )	//层序遍历_队列 
{
	queue Q;
	BinTree T;
	if( !bt ) return ;//判断非空
	AddQ( Q, bt );
	while( !isEmpty( Q ) ){
		T = deleteQ( Q );
		cout << T->Data << endl;
		if( T->Left ) AddQ( Q, T->Left );
		if( T->Left ) AddQ( Q, T->Right );
	} 
}

/*
int main()
{
	BinTree bt[10];
	for( int i = 0; i < 10; i++ ){
		bt[i] = ( BinTree )malloc( sizeof( TreeNode ) );
		bt[i]->Data = i;
		bt[i]->Left = bt[i]->Right = NULL;
	} 
	bt[4]->Left = bt[1];
	bt[4]->Right = bt[7];
	bt[1]->Left = bt[0];
	bt[1]->Right = bt[2];
	bt[2]->Right = bt[3];
	bt[7]->Left = bt[5];
	bt[5]->Right = bt[6];
	bt[7]->Right = bt[8];
	bt[8]->Right = bt[9]; 
	
	PreTraversal( bt[4] );
	printf( "\n" ); 
	MidTraversal( bt[4] );
	return 0;
}
*/
