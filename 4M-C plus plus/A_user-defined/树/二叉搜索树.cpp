#include <cstdio>
#include <malloc.h> 

#define ElementType int

typedef struct sNode *BinTree;
struct sNode{
	ElementType data;
	BinTree left;
	BinTree right;
};

BinTree Find( ElementType X, BinTree bt )
{
	while( bt ){
		if( X < bt->data )
			bt = bt->left;
		else if( X > bt->data )
			bt = bt->right;
		else
			return bt; 
	}
	return NULL;
}

BinTree FindMin( BinTree bt )
{
	while( bt->left ){
		bt = bt->left;
	}
	return bt;
}

BinTree FindMax( BinTree bt )
{
	while( bt->right ){
		bt = bt->right;
	}
	return bt;
}

BinTree Insert( BinTree bst, ElementType X )
{
	if( !bst ){
		bst = ( BinTree )malloc( sizeof( sNode ) );
		bst->data = X;
		bst->left = bst->right = NULL;
	}                                          //���пշ񣬷��ռ��� 
	else{
		if( bst->data > X )
			bst->left = Insert( bst->left, X );//�൱��ˢ�������� 									  											
		else if( bst->data < X )
			bst->right = Insert( bst->right, X );
	}
	return bst;
}

BinTree Delete( BinTree bst, ElementType X )
{
	BinTree Tmp;
	if( !bst ) printf("ERROR");//�ȶ��Ƿ�� 
	else{
		if( bst->data > X )//�ٶ�X�ںδ� 
			bst->left = Delete( bst->left, X );//ˢ������ 
		else if( bst->data > X )
			bst->right = Delete( bst->right, X );
		else { /* BST����Ҫɾ���Ľ�� */
            /* �����ɾ����������������ӽ�� */ 
            if( bst->left && bst->right ) {//���X�ڵ�����״̬ 
                /* ��������������С��Ԫ�����ɾ����� */
                Tmp = FindMin( bst->right );
                bst->data = Tmp->data;
                /* ����������ɾ����СԪ�� */
                bst->right = Delete( bst->right, bst->data );
                //��������²���free,����������free 
            }
            else { /* ��ɾ�����ֻ��һ����û���ӽ�� */
                Tmp = bst; 
                if( !bst->left )       /* ֻ�����ӻ����ӽ�� */
                	bst = bst->right; 
                else                   /* ֻ������ */
                    bst = bst->left;
                free( Tmp );	//ȫ����˴�free����ȴ�Ǳؽ��е�һ�� 
            }
        }
	}
	return bst;
}

int main()
{
	return 0;
}

//PTA6-12�����������Ĳ�����
/* 
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); 
void InorderTraversal( BinTree BT ); 

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
//��Ĵ��뽫��Ƕ������ 
BinTree Insert( BinTree BST, ElementType X )
{
	if( !BST ){
		BST = ( BinTree )malloc( sizeof( struct TNode ) );
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if( X < BST->Data )
			BST->Left = Insert( BST->Left , X );
		else if( X > BST->Data )
			BST->Right = Insert( BST->Right , X);  
	}
	return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
	BinTree tmp;
	if( !BST )	printf( "Not Found\n" );
	else {
		if( X < BST->Data )
			BST->Left = Delete( BST->Left , X );
		else if( X > BST->Data )
			BST->Right = Delete( BST->Right , X);  
		else {
			if( !BST->Left || !BST->Right ){
				tmp = BST;
				if( !BST->Left ) BST = BST->Right;
				else BST = BST->Left;
				free( tmp ); 
			}
			else{
				tmp = FindMax( BST->Left );
				BST->Data = tmp->Data;
				BST->Left = Delete( BST->Left , BST->Data );
			}
		}
	}
	return BST;
}

Position Find( BinTree BST, ElementType X )
{
	while( BST ){
		if( X < BST->Data )
			BST = BST->Left;
		else if( X > BST->Data )
			BST = BST->Right;
		else
			return BST; 
	}
	return NULL;
}

Position FindMin( BinTree BST )
{
	if( BST )	
		while( BST->Left )	BST = BST->Left;
	return BST;
}
Position FindMax( BinTree BST )
{
	if( BST )
		while( BST->Right )	BST = BST->Right;
	return BST;
}

void PreorderTraversal( BinTree BT )
{
	if( BT ){
		printf(" %d" , BT->Data );
		PreorderTraversal( BT->Right );
		PreorderTraversal( BT->Left );
	}
 } 

void InorderTraversal( BinTree BT )
{
	if( BT ){
		InorderTraversal( BT->Left );
		printf( " %d" , BT->Data );
		InorderTraversal( BT->Right );
	}
 } 
*/ 
