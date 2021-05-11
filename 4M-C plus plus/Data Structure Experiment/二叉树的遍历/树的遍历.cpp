/**
 *    author:  McFly
 *    created: 04.2021 
 *	  describ:  �������ı���
 *				���ֱ����������������򡢺���ǵݹ�����Լ��������	
**/
#include <iostream>
#include <malloc.h>
#include <queue>
#include <stack> 

using namespace std;

#define ElementType char

typedef struct TreeNode *BinTree; //�� 
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreTra( BinTree bt ) //���� 
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

void MidTra( BinTree bt )	//���� ������Ĳ�ͬ�������������λ�� 
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
	cout << "����һ�����ĸ���㣺" << endl; 
	cin >> mid;
	T->Data = mid;T->Left = NULL;T->Right = NULL;
	cout << "�������������Ϣ��" << endl; 
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
		//��ʱtmp->Data == mid
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
	cout << "�������:" << endl;
	PreTra( T );
	cout << endl;
	cout << "�������:" << endl;
	MidTra( T );
	cout << endl;
	cout << "�������:" << endl;
	LastTra( T ); 
 } 
