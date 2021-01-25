#include <iostream>

using namespace std;

#define N 2000000

char a[N + 10] = {0};			//大数一定是char型数组， int到了百万级别必毙

int main()
{
	int n; cin>>n;
	
	for( int i = 2; i <= n; i++ )
	
		if( a[i] == 0 ){
			
			int tmp = n / i; //多少可以优化算法（相比 i*j<=n） 
			
			for( int j = 2; j <= tmp; j++ )//这里我觉得应该是j<=tmp; 
			{							  //没错果然是 

				a[i * j] = 1;
			
			}
				
		}
		
	unsigned long long sum = 0;
	
	for( int i = 2; i <= n; i++ )
	{
		
		if( a[i] == 0 )
		
			sum += i;
		
	 } 
	 
	cout << sum << endl;
		
	return 0;
} 
