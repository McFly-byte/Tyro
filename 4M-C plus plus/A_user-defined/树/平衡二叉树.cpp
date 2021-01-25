/*  ��1:06:31��[������]
  	4.2 ƽ�������(2С�ڹ�22:53) */ 

#define ElementType int

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL������ */
struct AVLNode{
    ElementType Data; /* ������� */
    AVLTree Left;     /* ָ�������� */
    AVLTree Right;    /* ָ�������� */
    int Height;       /* ���� */  //4.28 ��ʵӦ�ý��������߲�ɣ� 
};

int GetHeight( AVLTree T )	// 4.28�Բ� 
{
	int L = T->Left ,R = T->Right;
	if( !T )	return 0;
	else {
		return max( L , R ) + 1;
	}
}
 
int Max ( int a, int b )
{
    return a > b ? a : b;
}
 
AVLTree SingleLeftRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B */
  /* ��A��B������������A��B�ĸ߶ȣ������µĸ����B */     
 
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    					//�ƹ�ȥ����A->Left�ˣ�֮ǰ��B->Right 
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
  
    return B;
}

AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C�����ε����������µĸ����C */
     
    /* ��B��C���ҵ�����C������ */
    A->Left = SingleRightRotation(A->Left);
    /* ��A��C��������C������ */
    return SingleLeftRotation(A);
}
 
/*************************************/
/* �ԳƵ��ҵ�������-��˫�����Լ�ʵ�� */
/*************************************/
 
AVLTree Insert( AVLTree T, ElementType X )
{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
    if ( !T ) { /* ��������������½�����һ�������� */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (�������) ���� */
 
    else if ( X < T->Data ) {
        /* ����T�������� */
        T->Left = Insert( T->Left, X);
        /* �����Ҫ���� */
        if ( GetHeight(T->Left) - GetHeight(T->Right) == 2 )
            if ( X < T->Left->Data ) //����Դ��T���������������� 
               T = SingleLeftRotation(T);      /* ���� */
            else 	//����Դ��T���������������� 
               T = DoubleLeftRightRotation(T); /* ��-��˫�� */
    } /* else if (����������) ���� */
     
    else if ( X > T->Data ){
        /* ����T�������� */
        T->Right = Insert( T->Right, X );//ˢ�����������ٻص����㺯��ʱ�Ѿ�����˲��� 
        /* �����Ҫ���� */
        if ( GetHeight(T->Left) - GetHeight(T->Right) == -2 )
            if ( X > T->Right->Data ) 						//�ж��������״� 
               T = SingleRightRotation(T);     /* �ҵ��� */
            else  
               T = DoubleRightLeftRotation(T); /* ��-��˫�� */
    } /* else if (����������) ���� */

    /* else X == T->Data��������� */
 
    /* �����˸������� */
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
     
    return T;
}
