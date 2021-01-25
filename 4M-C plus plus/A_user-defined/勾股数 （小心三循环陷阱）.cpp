#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	for( a = 3; a < 333; a++ )
	{
		for( b = a; a + b < 667; b++ )	//not b < 334
		{
			for( c = b; a + b + c <= 1000; c++ )
			{
				if( c * c > a * a + b * b )
					break;
				if( a * a + b * b == c * c )
					cout<<a<<' '<<b<<' '<<c<<endl;
			}
		}
	}
 } 
