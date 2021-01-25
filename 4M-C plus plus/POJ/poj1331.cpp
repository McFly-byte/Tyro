#include<iostream>
#include<cmath>

using namespace std;

#define max 100

bool is1331( long long a, long long b, long long c, int i )
{
	long long A = 0, B = 0, C = 0;
	int j = 0;
	while( a ){
		A += ( a % 10 ) * pow( i, j );
		a /= 10;
		j++;
	} 
	j = 0;
	while( b ){
		B += ( b % 10 ) * pow( i, j );
		b /= 10;
		j++;
	} 
	j = 0;
	while( c ){
		C += ( c % 10 ) * pow( i, j );
		c /= 10;
		j++;
	}
	if( A * B == C)
		return true;
	else
		return false;
}

int main()
{
	int T;
	cin>>T;
	while( T-- ){
		
		long long a, b, c;
		cin>>a>>b>>c;
		
		int maxIndex = 0;
		long long tmp = a;
		while( tmp ){
			if( tmp % 10 > maxIndex )
				maxIndex = tmp % 10;
			tmp /= 10;
		}
		tmp = b;
		while( tmp ){
			if( tmp % 10 > maxIndex )
				maxIndex = tmp % 10;
			tmp /= 10;
		}
		tmp = c;
		while( tmp ){
			if( tmp % 10 > maxIndex )
				maxIndex = tmp % 10;
			tmp /= 10;
		}
		
		int i;
		bool flag = false;
		for(  i = maxIndex +1 ; i < max; i++)
		{
			if( is1331( a, b, c, i ) )
			{
				flag = true;
				break;
			}
		}
		
		if( flag )
			cout<<i<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
} 
