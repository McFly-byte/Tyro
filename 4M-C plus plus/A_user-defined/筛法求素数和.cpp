#include <iostream>

using namespace std;

#define N 2000000

char a[N + 10] = {0};			//����һ����char�����飬 int���˰��򼶱�ر�

int main()
{
	int n; cin>>n;
	
	for( int i = 2; i <= n; i++ )
	
		if( a[i] == 0 ){
			
			int tmp = n / i; //���ٿ����Ż��㷨����� i*j<=n�� 
			
			for( int j = 2; j <= tmp; j++ )//�����Ҿ���Ӧ����j<=tmp; 
			{							  //û���Ȼ�� 

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
