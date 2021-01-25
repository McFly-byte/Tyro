#include <iostream>//完全二叉树实现最大堆 
#include <stdlib.h>

using namespace std;

#define MAXVALUE 1000 /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */
#define ERROR -1

typedef int Position;
typedef int ElementType;

struct HNode {
	ElementType * Data;//数组实现完全二叉树，父子i2倍关系 
	int Capacity;//填满时尾元位置 
	int Nowsize;//当前尾元位置 
};
typedef HNode * Heap;

Heap CreateHeap( int maxsize );
bool Insert( Heap H , ElementType X ); /* 将元素X插入最大堆H */
bool IsFull( Heap H );
Position Delete( Heap H );/* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
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
	//不大1的话下面IsFull说不通 
	H->Data[0] = MAXVALUE;//设置“哨兵”值大于后面所有数据 
	H->Capacity = maxsize;
	H->Nowsize = 0;//指向最后存储元素位置 
	
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
	}*/ //要调用多次swap函数，不够快
	int i = ++H->Nowsize;
	for( ; H->Data[i/2] < X ; i /= 2 )
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;//最后再将X填入空位 
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
		//选中parent左右子中较大值 
		if( rear >= H->Data[child] ) break; //有大既符合 
		else 
			H->Data[parent] = H->Data[child];//否则rear下滤 
	}
	H->Data[parent] = rear;//parent所在位置一直是给rear准备的 
	return Maxitem; 
}

void PercDown( Heap H, int p )//与Delete相似 
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
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */
 
    int i;
 
    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Nowsize/2; i>0; i-- )
        PercDown( H, i );
}
