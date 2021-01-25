//<堆栈>
#include <malloc.h>
#include <iostream>

using namespace std;

#define error -1
#define maxSize 100


-------------------------------------------------------------
//剑鞘 
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
}//s是虚指 

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
//罐头 
typedef int Position; 
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;//此处一个结点即一个堆栈 
 
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}//S->Top直接对应最顶上数的下标 
 
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}
 
bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("堆栈满");
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
        printf("堆栈空");
        return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( S->Data[(S->Top)--] );//'--'awesome！ 
}


int main()
{
	
}
