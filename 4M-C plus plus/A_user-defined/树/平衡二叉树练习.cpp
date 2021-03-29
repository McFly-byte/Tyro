#include <iostream>   //平衡二叉树练习
#include <malloc.h>

using namespace std;

typedef struct AVLNode *AVLTree;
struct AVLNode{
	int value;
	AVLTree left;
	AVLTree right;
	int height;
};

int max( int a, int b );

int GetHeight( AVLTree T );

AVLTree L_Rotation( AVLTree A );
AVLTree R_Rotation( AVLTree A );

AVLTree LR_Rotation( AVLTree A );
AVLTree RL_Rotation( AVLTree A );

AVLTree Insert( AVLTree T, int aim );

void print( AVLTree T );


int main()
{
	int n;
	
	AVLTree AVLT = NULL;
	
	while( cin>>n ){
		AVLT = Insert( AVLT, n ); //勿忘T=func(T),否则什么也出不来┗|｀O′|┛ 嗷~~ 
	}
	print( AVLT );
	return 0;
}

/*
______________________________________________________________
*/

int max( int a, int b )
{
	return a > b ? a : b;
}

int GetHeight( AVLTree T )
{
	if( !T ) return -1;
	return T->height;
}

AVLTree L_Rotation( AVLTree A )
{
	AVLTree B =  A->left;
	A->left = B->right;
	B->right = A;
	
	A->height = max( GetHeight( A->left ), GetHeight( A->right ) ) + 1;
	B->height = max( GetHeight( B->left ), A->height ) + 1;

	return B;
}

AVLTree R_Rotation( AVLTree A )
{
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	
	A->height = max( GetHeight( A->left ), GetHeight( A->right ) ) + 1;
	B->height = max( GetHeight( B->left ), A->height ) + 1;

	return B;
}

AVLTree LR_Rotation( AVLTree A )//先右旋后左旋 
{
	A->left = R_Rotation( A->left );
	return L_Rotation( A );
} 

AVLTree RL_Rotation( AVLTree A )
{
	A->right = L_Rotation( A->right );
	return R_Rotation( A );
} 

AVLTree Insert( AVLTree T, int aim )
{
	if( !T ){
		T = ( AVLTree )malloc( sizeof( AVLNode ) );
		T->value = aim;
		T->height = 0;
		T->right = T->left = NULL;	
	}
	
	else if( aim > T->value ){
		
		T->right = Insert( T->right, aim );
		
		if( GetHeight( T->left ) - GetHeight( T->right ) == -2 ){
			if( aim > T->right->value )
				T = R_Rotation( T );
			else
				T = RL_Rotation( T );
		}
	}
	
	else if( aim < T->value ){
		 T->left = Insert( T->left, aim );
		 
		 if( GetHeight( T->left ) - GetHeight( T->right ) == 2 )
		 {
			if( aim < T->left->value )//第一次括号里写成了T->left->value,白费我半天时间 马的 赣！ 
		 		T = L_Rotation( T );
			else
				T = LR_Rotation( T );	
		}
	}
	
	T->height = max( GetHeight( T->left ), GetHeight( T->right ) ) + 1;
	return T;
}

void print( AVLTree T )
{
	if( T == NULL ){
		//	cout<<"here's nothing"<<endl;
		return ;
	}
	cout<<T->value<<' '<<T->height<<endl;
	print( T->left );
	print( T->right );
}

