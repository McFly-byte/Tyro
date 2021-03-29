/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:  	寻找第k小的数
 *					输入数据过多cin依旧不行
 *                  分治的思想 分成三部分
 *					递归			
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
	// 此时j < i 
	if(k<=j) 
	    return nth_Element(l,j);
		//在左区间只需要搜左区间
	else if(i<=k) 
	    return nth_Element(i,r);
		//在右区间只需要搜右区间
	else //如果在中间区间直接输出
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
