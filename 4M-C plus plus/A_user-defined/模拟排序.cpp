#include <iostream> //Sort_s2b 
#include <malloc.h>

using namespace std;

#define n 10	//Testing Data: 2 1 3 2 4 

void bubbleSort( int * , int );			//ð�� 
void selectSort( int * , int );			//ѡ��
void insertSort( int * , int );			//���� 
void mergeSort( int , int , int * );	//�鲢_�� 
void merge( int , int , int * );		//�鲢_�� 
void quickSort( int , int , int * );	//���� 
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
				min = a[j];		//min�����Ƚϣ�minid����׼������ 
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
//��ԭ���ݴӵ������ϸ��(left\right:�±����½�)
{
	if( right - left <= 1 ){
		if( a[right] < a[left] )//ֻ��a[right]��a[left]�� 
								//��Ԫ��ʱ���ص��ú�����
								//��if(right>left)���Ż� 
			swap( a[right], a[left] );
		return ;//������return 
	}
	
	int middle = left + ( right - left ) / 2;
	mergeSort( left, middle, a );
	mergeSort( middle + 1, right, a );
	merge( left, right, a );
}
void merge( int left, int right, int * a )
//�������������ݱȽϴ�С���������ռ�tmp[]�� 
{
	int asize = right - left + 1;
	int middle = left + ( right - left ) / 2; 
	int i = left , j = middle + 1 , tmpid = 0 ;  
	//middle��4����5������j��ʼΪmiddle+1����middle 
	int * tmp;
	tmp = ( int * )malloc( asize * sizeof( int ) );
	
	while( tmpid < asize ){		//Ī��tmpid\i\jÿ�θ�ֵ��Ҫ++ 
		if( i > middle )	//��>����>=,'='ֻ����һ���Ҹôθ�a[i] 
			tmp[tmpid++] = a[j++];
		else if( j > right )
			tmp[tmpid++] = a[i++];
		else{
			if( a[i] > a[j] )
				tmp[tmpid++] = a[j++];
			else//���ǵ�a[i]==a[j]����� 
				tmp[tmpid++] = a[i++];
		}
	}
	
	for( int k = left; k <= right; k++ )//��ֵת�� 
		a[k] = tmp[k-left];		//С��a[]&tmp[]�±귶Χ 
	free( tmp ); 
} 

void quickSort( int left , int right , int * a )
//���Ԫ�ز�����ʹ�䴦����ȷ��λ����
//����ߵĶ�����С���Ҷ��� 
{
	if( left >= right ) return ;
	int i = left , j = right;
	int target = a[left];
	
	while( i != j ){
		while( a[j] >= target && i < j ) j--;
		//�ж�������'='����������ͬ����ѭ��
		swap( a[j], a[i] );			 
		while( a[i] <= target && i < j ) i++;
		//'<'��֤һ����ȼ����˳���ѭ�� 
		swap( a[i], a[j] );
	} 
	
	int middle = i;//�����middle��������ƽ���� 
	quickSort( left , middle - 1 , a );
	quickSort( middle + 1 , right , a );
} 

void printArray( int * a , int size )
{
	for( int i = 0 ; i < size ; i++ )
		cout<<a[i]<<' ';
	cout<<endl;
}
