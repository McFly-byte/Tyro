#include <iostream>//��ȫ������ʵ������ 
#include <stdlib.h>

using namespace std;

#define MAXVALUE 1000 /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */
#define ERROR -1

typedef int Position;
typedef int ElementType;

struct HNode {
	ElementType * Data;//����ʵ����ȫ������������i2����ϵ 
	int Capacity;//����ʱβԪλ�� 
	int Nowsize;//��ǰβԪλ�� 
};
typedef HNode * Heap;

Heap CreateHeap( int maxsize );
bool Insert( Heap H , ElementType X ); /* ��Ԫ��X��������H */
bool IsFull( Heap H );
Position Delete( Heap H );/* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
bool IsEmpty( Heap H ); 
void PercDown( Heap H, int p );
void BuildHeap( Heap H );


int main()
{
	int size;	cin >> size;
	Heap h = CreateHeap( size );		
}


Heap CreateHeap( int maxsize )
{
	Heap H = ( Heap )malloc( sizeof( struct HNode ) );
	H->Data = ( ElementType * )malloc( sizeof( ElementType ) * ( maxsize + 1) );
	//����1�Ļ�����IsFull˵��ͨ 
	H->Data[0] = MAXVALUE;//���á��ڱ���ֵ���ں����������� 
	H->Capacity = maxsize;
	H->Nowsize = 0;//ָ�����洢Ԫ��λ�� 
	
	return H;
}

bool IsFull( Heap H )
{
	return ( H->Nowsize == H->Capacity );
}

bool Insert( Heap H , ElementType X )
{
	if( IsFull( H ) ){
		cout << "FULL" << endl;
		return false;
	}
	
	/*H->Data[++H->Nowsize] = X;
	for( int i = H->Nowsize ; H->Data[i] > H->Data[i/2] ; i /= 2 ){
		swap( H->Data[i] , H->Data[i/2] );
	}*/ //Ҫ���ö��swap������������
	int i = ++H->Nowsize;
	for( ; H->Data[i/2] < X ; i /= 2 )
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;//����ٽ�X�����λ 
	return true;
}

bool IsEmpty( Heap H )
{
	return ( !H->Nowsize );
}

ElementType Delete( Heap H )
{
	if( IsEmpty( H ) ){
		cout << "Empty" ;
		return ERROR;
	}
	
	ElementType Maxitem = H->Data[1] , rear = H->Data[H->Nowsize--];
	Position parent , child;
	for( parent = 1 ; parent * 2 <= H->Nowsize ; parent = child ){
		child = parent * 2;
		if( child != H->Nowsize && H->Data[child+1] > H->Data[child] )	child++;
		//ѡ��parent�������нϴ�ֵ 
		if( rear >= H->Data[child] ) break; //�д�ȷ��� 
		else 
			H->Data[parent] = H->Data[child];//����rear���� 
	}
	H->Data[parent] = rear;//parent����λ��һֱ�Ǹ�rear׼���� 
	return Maxitem; 
}

void PercDown( Heap H, int p )//��Delete���� 
{
	ElementType X = H->Data[p];
	int parent , child;
	
	for( parent = p ; parent * 2 <= H->Nowsize ; parent = child ){
		child = parent * 2;
		if( child != H->Nowsize && H->Data[child] < H->Data[child+1] )	child++;
		if( X < H->Data[child] )
			H->Data[parent] = H->Data[child];	
		else break;
	}
	H->Data[parent] = X;
}

void BuildHeap( Heap H )
{ /* ����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */
 
    int i;
 
    /* �����һ�����ĸ��ڵ㿪ʼ���������1 */
    for( i = H->Nowsize/2; i>0; i-- )
        PercDown( H, i );
}
