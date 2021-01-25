
------------------------------Vol.1 顺环队列（数组）--------------------------------------- 

typedef int ElementType; 
typedef int Position;

typedef struct QNode *Queue;
struct QNode {
    ElementType * Data;     //存储元素的数组（的指针，不指明Size） 
    Position Front, Rear;  // 队列的头、尾指针 (此处为整形，即Data数组的下标; 并没有哪一个位置要轮空)
    int MaxSize;           // 队列最大容量 
};//一个节点就是一个队列 

 
Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    //注意存储这一部分怎么写 
	Q->Front = Q->Rear = 0;//很重要 
    Q->MaxSize = MaxSize;
    return Q;
}
 
bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front%Q->Maxsize); 
    //直接写在return里 
}
 
bool AddQ( Queue Q, ElementType X )//返回是bool（插入是否成功） 
{
    if ( IsFull(Q) ) {
        printf("队列满");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;//rear先后移再读入数，Data[0]不放东西。 
        return true;
    }
}
 
bool IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}

#define ERROR -1 
 
ElementType DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) ) { 
        printf("队列空");
        return ERROR;
    }
    else  {
        Q->Front = (Q->Front+1)%Q->MaxSize;
		//不必操作数据，直接把索引改了就行 
        return  Q->Data[Q->Front];
    }
}


---------------------------Vol.2 链式存储------------------------
 //链式存储需要两种结点结构 
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *Queue;
struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
    int NowSize:			//当前队列长度 
};

// 与顺环相似，但是存储部分为链表。 
//写了Nowsize和Maxsize就没有闲置的结点，每个里都有存数
 
 
bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}
 
ElementType DeleteQ( Queue Q )
{
    Position FrontCell; 
    ElementType FrontElem;
     
    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
 
        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}
