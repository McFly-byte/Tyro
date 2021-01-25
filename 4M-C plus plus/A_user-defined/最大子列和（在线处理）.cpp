#include <iostream>			//最大子列和（在线处理）：O（N）。 

using namespace std; 

int main()
{
	int ThisSum = 0, MaxSum = 0, i = 0;
	int N;
	cin>>N;
	int a[N+1];
	for( i = 0; i < N; i++ )
		cin>>a[i];
	
	for( i = 0; i < N; i++ )
	{
		ThisSum += a[i];
		if( ThisSum > MaxSum )
			MaxSum = ThisSum;
		else if( ThisSum < 0 )
			ThisSum = 0;
	 } 
	 
	cout<<MaxSum<<endl;
	
	return 0;
}
