/*
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�
����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:
Yes
No
No
*/

#include <iostream>
#include <cstring>
#include <malloc.h>

using namespace std;

typedef struct TreeNode * tree;
struct TreeNode{
	int Data;
	tree Left , Right;
};

char lop[11] = {0};
int id = 0;

void PreTraversal( tree T );//��������������������������lop[]�� 
void MidTraversal( tree T );//����   �����ֱ���ȷ��һ���� 
tree Insert( tree T , int X );//����һ���� 
void Clean(); //��lop[]������ת�ƺ����lop[]���Ա�洢��һ�α������ 
void FreeTree( tree T );//�ѷ�������Ŀռ�free�� 

int main()
{
	int N , L;
	while( cin >> N && N != 0 ){
		cin >> L ;
		
		tree OringinalT = NULL;
		int cup;
		for( int i = 0 ; i < N ; i++ ){
			cin >> cup ;
			OringinalT = Insert( OringinalT , cup );
		}//�����ʼ���� 
		
		char A[N+1] = {0} ,B[N+1] = {0};
		
		PreTraversal( OringinalT );	strcpy( A , lop );	Clean();
		MidTraversal( OringinalT ); strcpy( B , lop );	Clean();
		//��¼��ʼ���ж�Ӧ�������ֱ��� 
		FreeTree( OringinalT );//��û���ˣ��������˳��͹��� 
	
		while( L-- ){
			tree T = NULL;
			int cup;
			for( int i = 0 ; i < N ; i++ ){
				cin >> cup ;
				T = Insert( T , cup );
			}
			char a[N+1] = {0} ,b[N+1] = {0};
			PreTraversal( T );	strcpy( a , lop );	Clean();
			MidTraversal( T );  strcpy( b , lop );	Clean();
			
			if( !strncmp( A , a , N ) && !strncmp( B , b , N ) )
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
			
			FreeTree( T );
		}
		
	}
	return 0;
}

tree Insert( tree T , int X )
{
	if( !T ){
		T = ( tree )malloc( sizeof( TreeNode ) );
		T->Data = X;
		T->Left = T->Right = NULL; 
	}
	else {
		if ( X < T->Data )
			T->Left = Insert( T->Left , X );
		else 
			T->Right = Insert( T->Right , X );
	}
	return T;
}

void PreTraversal( tree T )
{
	if( T ){
		lop[id++] = T->Data; 
		PreTraversal( T->Left );
		PreTraversal( T->Right );
	}
}

void MidTraversal( tree T )
{
	if( T ){
		MidTraversal( T->Left );
		lop[id++] = T->Data;	
		MidTraversal( T->Right );
	}
}

void Clean()
{
	memset( lop , 0 , 11 );
	id = 0;
}

void FreeTree( tree T )
{
	if( T ){
		FreeTree( T->Left );
		FreeTree( T->Right ); 
		free( T );
	}
}
