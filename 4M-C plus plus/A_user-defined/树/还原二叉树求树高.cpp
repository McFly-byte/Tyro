#include <bits/stdc++.h>//根据前/中序遍历求树高 

using namespace std;

#define ERROR -1

typedef struct TreeNode * tree;
struct TreeNode{
	char Data;
	tree Left , Right ;
	int Height;
};

tree FindRoot( tree T , char * a , int ah , int ar , char * b , int bh , int br );
int FindNode( char ch , char * array , int head , int rear );
int GetHeight( tree T );

int main()
{
	int N;
	cin >> N;
	char Pre[N+1] , Mid[N+1];
	cin >> Pre >> Mid;
	tree T = NULL;
	T = FindRoot( T , Pre , 0 , N-1, Mid , 0 , N-1 );
	cout << T->Height << endl;
}

tree FindRoot( tree T , char * pre , int ph , int pr , char * mid , int mh , int mr )
{
	if( pr < ph || mr < mh )
		return NULL;
	T = ( tree )malloc( sizeof( TreeNode ) );
	T->Data = pre[ph];
	int locate = FindNode( pre[ph] , mid , mh , mr );
	T->Left = FindRoot( T->Left , pre , ph+1 , ph+locate-mh , mid , mh , locate-1 );
	T->Right = FindRoot( T->Right , pre , ph+locate-mh+1 , pr , mid , locate+1 , mr );
	T->Height = GetHeight( T );
	return T;
}

int FindNode( char ch , char * array , int head , int rear )
{
	for( int  i = head ; i <= rear ; i++ )
		if ( array[i] == ch )
			return i;
	return ERROR; 
}

int GetHeight( tree T )
{
	if( !T->Left && !T->Right )
		T->Height = 1;
	else if( !T->Left )
		T->Height = T->Right->Height + 1; 
	else if( !T->Right )
		T->Height = T->Left->Height + 1; 
	else
		T->Height = max( T->Left->Height , T->Right->Height ) + 1;
	return T->Height;
}
