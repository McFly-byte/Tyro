/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:  	Ѱ�ҵ�kС����
 *					�������ݹ���cin���ɲ���
 *                  ���ε�˼�� �ֳ�������
 *					�ݹ�			
**/
#include <bits/stdc++.h> 
using namespace std

#define MAXN 5000005 
int a[MAXN], k ;

int nth_Element( int l, int r )
{ 
	int mid=a[l+(r-l)/2], i = l, j = r;
	while( i <= j )
	{
		while( a[j] > mid ) j--;
		while( a[i] < mid ) i++;
		if( i <= j ) 
		{ 
			swap( a[i], a[j] );
			i++,j--; 
		} 
	}
	// ��ʱj < i 
	if(k<=j) 
	    return nth_Element(l,j);
		//��������ֻ��Ҫ��������
	else if(i<=k) 
	    return nth_Element(i,r);
		//��������ֻ��Ҫ��������
	else //������м�����ֱ�����
	    return a[j + 1]; 		
} 

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n >> k;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	cout << nth_Element( 0,n-1 ) << endl;
} 
