#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int ans[250] = {0};
	char a[250] = {0}, b[250] = {0};
	int s[250] = {0}, e[250] = {0};
	
	cin>>a>>b;
	int alen = strlen(a);
	int blen = strlen(b);
	for( int i = 0; i < alen; i++ )
		s[i] = a[alen-1-i] - '0';
	for( int j = 0; j < blen; j++ )
		e[j] = b[blen-1-j] - '0';
	int relay = 0, sum = 0, tag = 0;
	int i = 0, j = 0;
	for( ; i < alen; i++)
	{
		for( j = 0; j < blen || relay; j++ )
		{
			sum = s[i] * e[j] + ans[i+j] + relay;
			ans[i+j] = sum % 10;
			relay = sum / 10;
		}
	}
	
	for( int k = i + j - 2; k >= 0; k-- )
		cout<<ans[k];
	cout<<endl;
	return 0;
} 
