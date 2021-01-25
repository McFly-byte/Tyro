/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
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

void PreTraversal( tree T );//先序遍历，并将遍历结果储存在lop[]中 
void MidTraversal( tree T );//中序   由两种遍历确定一棵树 
tree Insert( tree T , int X );//构造一棵树 
void Clean(); //在lop[]中内容转移后清空lop[]，以便存储下一次遍历结果 
void FreeTree( tree T );//把分配给树的空间free掉 

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
		}//构造初始序列 
		
		char A[N+1] = {0} ,B[N+1] = {0};
		
		PreTraversal( OringinalT );	strcpy( A , lop );	Clean();
		MidTraversal( OringinalT ); strcpy( B , lop );	Clean();
		//记录初始序列对应树的两种遍历 
		FreeTree( OringinalT );//树没用了，留其遍历顺序就够了 
	
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
