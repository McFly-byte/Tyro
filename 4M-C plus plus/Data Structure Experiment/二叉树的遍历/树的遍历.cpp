/**
 *    author:  McFly
 *    created: 04.2021 
 *	  describ:  二叉树的遍历
 *				三种遍历方法：先序、中序、后序非递归遍历以及层序遍历	
**/
#include <iostream>
#include <malloc.h>
#include <queue>
#include <stack> 

using namespace std;

#define ElementType char

typedef struct TreeNode *BinTree; //树 
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreTra( BinTree bt ) //先序 
{
	BinTree T = bt;
	stack<BinTree> S;
	while( T || !S.empty() ){
		while( T ){
			cout << T->Data << ' ' ;
			S.push( T );
			T = T->Left;
		}
		if( !S.empty() ){
			T = S.top();
			S.pop();
			T = T->Right;
		}
	}
 } 

void MidTra( BinTree bt )	//中序 与先序的不同在于数据输出的位置 
{
	BinTree T = bt;
	stack<BinTree> S;
	while( T || !S.empty() ){
		while( T ){
			S.push( T );
			T = T->Left;
		}
		if( !S.empty() ){
			T = S.top();
			S.pop();
			cout << T->Data << ' ';
			T = T->Right;
		}
	}
}

void LastTra( BinTree bt )
{
	BinTree T = bt;
	BinTree LastVisited = NULL;
	stack<BinTree> S;
	while( T || !S.empty() ){
		while( T ){
			S.push( T );
			T = T->Left;
		}
		if( !S.empty() ){
			T = S.top();
			S.pop();
			if( T->Right == NULL || T->Right == LastVisited ){
				cout << T->Data << ' ';
				LastVisited = T;
				T = NULL;
			}
			else {
				S.push( T );
				T = T->Right;
			}
		}
	}
}

BinTree BuildTree()
{
	BinTree T = (BinTree)malloc( sizeof( struct TreeNode ) );
	ElementType left,right,mid;
	cout << "输入一棵树的根结点：" << endl; 
	cin >> mid;
	T->Data = mid;T->Left = NULL;T->Right = NULL;
	cout << "输入这棵树的信息：" << endl; 
	while( cin >> mid >> left >> right )
	{
		BinTree tmp;
		queue<BinTree> Q;
		Q.push(T); 
		do {
			tmp = Q.front();
			Q.pop();
			if( tmp->Left ) 
			{
				Q.push( tmp->Left );
			}
			if( tmp->Right )
			{
				Q.push( tmp->Right );
			}
		} while( tmp->Data != mid );
		//此时tmp->Data == mid
		if( left != '*' ) 
		{
			BinTree L = (BinTree)malloc( sizeof( struct TreeNode ) );
			L->Left = NULL;L->Right = NULL;
			L->Data = left;
			tmp->Left = L;
		} 
		if( right != '*' )
		{
			BinTree R = (BinTree)malloc( sizeof( struct TreeNode ) );
			R->Left = NULL;R->Right = NULL;
			R->Data = right;
			tmp->Right = R;
		}
	} 
	return T;
}

int main()
{
	BinTree T = BuildTree();
	cout << "先序遍历:" << endl;
	PreTra( T );
	cout << endl;
	cout << "中序遍历:" << endl;
	MidTra( T );
	cout << endl;
	cout << "后序遍历:" << endl;
	LastTra( T ); 
 } 
