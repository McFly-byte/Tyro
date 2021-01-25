
------------------------------Vol.1 ˳�����У����飩--------------------------------------- 

typedef int ElementType; 
typedef int Position;

typedef struct QNode *Queue;
struct QNode {
    ElementType * Data;     //�洢Ԫ�ص����飨��ָ�룬��ָ��Size�� 
    Position Front, Rear;  // ���е�ͷ��βָ�� (�˴�Ϊ���Σ���Data������±�; ��û����һ��λ��Ҫ�ֿ�)
    int MaxSize;           // ����������� 
};//һ���ڵ����һ������ 

 
Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    //ע��洢��һ������ôд 
	Q->Front = Q->Rear = 0;//����Ҫ 
    Q->MaxSize = MaxSize;
    return Q;
}
 
bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front%Q->Maxsize); 
    //ֱ��д��return�� 
}
 
bool AddQ( Queue Q, ElementType X )//������bool�������Ƿ�ɹ��� 
{
    if ( IsFull(Q) ) {
        printf("������");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;//rear�Ⱥ����ٶ�������Data[0]���Ŷ����� 
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
        printf("���п�");
        return ERROR;
    }
    else  {
        Q->Front = (Q->Front+1)%Q->MaxSize;
		//���ز������ݣ�ֱ�Ӱ��������˾��� 
        return  Q->Data[Q->Front];
    }
}


---------------------------Vol.2 ��ʽ�洢------------------------
 //��ʽ�洢��Ҫ���ֽ��ṹ 
typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *Queue;
struct QNode {
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    int MaxSize;           /* ����������� */
    int NowSize:			//��ǰ���г��� 
};

// ��˳�����ƣ����Ǵ洢����Ϊ���� 
//д��Nowsize��Maxsize��û�����õĽ�㣬ÿ���ﶼ�д���
 
 
bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}
 
ElementType DeleteQ( Queue Q )
{
    Position FrontCell; 
    ElementType FrontElem;
     
    if  ( IsEmpty(Q) ) {
        printf("���п�");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
            Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
 
        free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
        return  FrontElem;
    }
}
