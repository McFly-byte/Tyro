//二叉树 构造 遍历 
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int Value;
	TreeNode * Left;
	TreeNode * Right;	
}; 
typedef TreeNode *tree;

#define ROOTMARK -1

tree CreateTree( int n );//完全二叉树的构造 
void Level( tree Root );
void Pre( tree Root );
void Mid( tree Root );
void Post( tree Root );

int main()
{
	int n;
	cin >> n;
	tree T = CreateTree( n );
	Level( T );
	Pre( T ); cout << endl;
	Mid( T );cout << endl;
	Post( T );cout << endl;
}

tree CreateTree( int n )
{
	tree T = (tree)malloc( sizeof( struct TreeNode ) );	
	cin >> T->Value; n--;
	T->Left = T->Right = NULL;
	queue<tree> Q;
	Q.push( T );
	tree flag, son; 
	int v;//0为左子，1为右子 
	while( n ){
		flag = Q.front();
//		cout << "create: " << flag->Value << endl;
		Q.pop();
		for ( int i = 0; i < 2 && n > 0; i++ ){ //坑死了，&&写成了','，
												//就值判断','后面的部分 
			cin >> v;
			if( i == 1 ){		
				flag->Right = (tree)malloc( sizeof( struct TreeNode ) );
				son = flag->Right;
				son->Value = v;
				son->Left = son->Right = NULL;
				Q.push( son ) ;
			}
			else {
				flag->Left = (tree)malloc(sizeof( struct TreeNode ) );
				son = flag->Left;
				son->Value = v;
				son->Left = son->Right = NULL;
				Q.push( son ) ;
			}
			n--;
		}	
	}
	return T;
}

void Level( tree Root )
{
	queue<tree> Q;
	tree T = Root, fg;
	Q.push( T );
	while( !Q.empty() ){
		fg = Q.front();
		Q.pop();
		cout << fg->Value << ' ';
		if( fg->Left!=NULL ){
			Q.push( fg->Left );
//			cout << "left" << fg->Left->Value << endl;
		}
		
		if( fg->Right!=NULL ) {
			Q.push( fg->Right );
//			cout << "right" << fg->Right->Value << endl;
		}
	}
	cout << endl;
}
void Pre( tree Root )
{
	cout << Root->Value << ' ';
	if( Root->Left ) Pre( Root->Left );
	if( Root->Right ) Pre( Root->Right );
}
void Mid( tree Root )
{
	if( Root->Left ) Mid( Root->Left );
	cout << Root->Value << ' ';
	if( Root->Right ) Mid( Root->Right );	
}
void Post( tree Root )
{
	if( Root->Left ) Post( Root->Left );
	 if( Root->Right ) Post( Root->Right );
	cout << Root->Value << ' ';
}


