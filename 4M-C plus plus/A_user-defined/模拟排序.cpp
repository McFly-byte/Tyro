#include <iostream> //Sort_s2b 
#include <malloc.h>

using namespace std;

#define n 10	//Testing Data: 2 1 3 2 4 

void bubbleSort( int * , int );			//冒泡 
void selectSort( int * , int );			//选择
void insertSort( int * , int );			//插入 
void mergeSort( int , int , int * );	//归并_分 
void merge( int , int , int * );		//归并_治 
void quickSort( int , int , int * );	//快速 
void printArray( int * , int );

int main()
{
	int a[n];
	for( int i = 0; i < n; i++ )
	{
		cin>>a[i];
	}
	
	bubbleSort( a, n );	printArray( a , n );
	selectSort( a, n );	printArray( a , n );
	insertSort( a, n );	printArray( a , n );
	mergeSort( 0, n-1, a );	printArray( a , n );
	quickSort( 0, n-1, a );	printArray( a , n );
	
	for( int i = 0; i < n; i++ )
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	system("pause");
 } 
 
 /* ______________________________________________ */ 
void bubbleSort( int *a, int size )
{
	for( int i = size; i > 0; i-- ){
		for( int j = 1; j < i; j++ ){
			if( a[j-1] > a[j] )
				swap( a[j-1], a[j] );
		}
	}
}

void selectSort( int * a, int size )
{
	int min = 0, minid = 0;
	for( int i = 0; i < size - 1; i++ )
	{
		min = a[i];	minid = i;
		for( int j = i + 1 ; j < size ; j++ ){
			if( a[j] < min ){
				minid = j;
				min = a[j];		//min用来比较，minid用来准备交换 
			}
		}
		swap( a[i], a[minid] );
	 } 
}

void insertSort( int * a, int size ){
	int tmp = 0;
	for( int i = 1 ; i < size ; i++ ){
		for( int j = 0; j < i ; j++ ){
			if( a[j] > a[i] ){
				tmp = a[i];
				for( int k = i; k > j; k-- )
				{
					a[k] = a[k-1];
				}
				a[j] = tmp;
			}
		}
	}
}

void mergeSort( int left, int right, int * a )
//将原数据从当中逐次细分(left\right:下标上下界)
{
	if( right - left <= 1 ){
		if( a[right] < a[left] )//只有a[right]和a[left]两 
								//个元素时不必调用函数了
								//是if(right>left)的优化 
			swap( a[right], a[left] );
		return ;//别忘了return 
	}
	
	int middle = left + ( right - left ) / 2;
	mergeSort( left, middle, a );
	mergeSort( middle + 1, right, a );
	merge( left, right, a );
}
void merge( int left, int right, int * a )
//将左右两半数据比较大小后填入额外空间tmp[]中 
{
	int asize = right - left + 1;
	int middle = left + ( right - left ) / 2; 
	int i = left , j = middle + 1 , tmpid = 0 ;  
	//middle是4还是5决定了j初始为middle+1还是middle 
	int * tmp;
	tmp = ( int * )malloc( asize * sizeof( int ) );
	
	while( tmpid < asize ){		//莫忘tmpid\i\j每次赋值都要++ 
		if( i > middle )	//是>而非>=,'='只出现一次且该次赋a[i] 
			tmp[tmpid++] = a[j++];
		else if( j > right )
			tmp[tmpid++] = a[i++];
		else{
			if( a[i] > a[j] )
				tmp[tmpid++] = a[j++];
			else//考虑到a[i]==a[j]的情况 
				tmp[tmpid++] = a[i++];
		}
	}
	
	for( int k = left; k <= right; k++ )//简单值转移 
		a[k] = tmp[k-left];		//小心a[]&tmp[]下标范围 
	free( tmp ); 
} 

void quickSort( int left , int right , int * a )
//逐个元素操作，使其处于正确的位置上
//（左边的都比其小，右都大） 
{
	if( left >= right ) return ;
	int i = left , j = right;
	int target = a[left];
	
	while( i != j ){
		while( a[j] >= target && i < j ) j--;
		//判断条件有'='，否则遇相同则死循环
		swap( a[j], a[i] );			 
		while( a[i] <= target && i < j ) i++;
		//'<'保证一旦相等即可退出大循环 
		swap( a[i], a[j] );
	} 
	
	int middle = i;//这里的middle不是算术平均了 
	quickSort( left , middle - 1 , a );
	quickSort( middle + 1 , right , a );
} 

void printArray( int * a , int size )
{
	for( int i = 0 ; i < size ; i++ )
		cout<<a[i]<<' ';
	cout<<endl;
}
