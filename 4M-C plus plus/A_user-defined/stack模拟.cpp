//<��ջ>
#include <malloc.h>
#include <iostream>

using namespace std;

#define error -1
#define maxSize 100


-------------------------------------------------------------
//���� 
struct sNode{
	int contain;
	sNode * next;
};

typedef sNode* Stack;

Stack CreatStack( )
{
	Stack s;
	s = ( Stack )malloc( sizeof( sNode ) );
	s->next = NULL;
	return s;
}//s����ָ 

bool isEmpty( Stack s )
{
	return ( s->next == NULL ); 
}

bool push( Stack s, int item )
{
	Stack tmp;
	tmp = ( Stack )malloc( sizeof( sNode ) );
	if( tmp == NULL )	return false;
	tmp->contain = item;
	tmp->next = s->next;
	s->next = tmp;
	return true;
}

int pop( Stack s )
{
	if( isEmpty(s) ){
		cout<<"Already empty."<<endl;
		return error;
	}
	Stack tmp = s->next;
	int item = tmp->contain;
	s->next = tmp->next;
	free(tmp);
	return item;
}

------------------------------------------------------------ 
------------------------------------------------------------ 
//��ͷ 
typedef int Position; 
struct SNode {
    ElementType *Data; /* �洢Ԫ�ص����� */
    Position Top;      /* ջ��ָ�� */
    int MaxSize;       /* ��ջ������� */
};
typedef struct SNode *Stack;//�˴�һ����㼴һ����ջ 
 
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}//S->Topֱ�Ӷ�Ӧ��������±� 
 
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}
 
bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("��ջ��");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}
 
bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}
 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("��ջ��");
        return ERROR; /* ERROR��ElementType������ֵ����־���� */
    }
    else 
        return ( S->Data[(S->Top)--] );//'--'awesome�� 
}


int main()
{
	
}
