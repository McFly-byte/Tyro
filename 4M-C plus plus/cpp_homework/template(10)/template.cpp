#include <iostream>

using namespace std;

template<class T , class K>
T C( T n , K  k )
{
	if( k == 1 || k == n-1 ) return n;
	if( n-k < k ) k = n-k;
	T ans = 1 , tmp = 1;
	for( K i = k ; i > 0 ; i-- ){
		ans *= ( n-i+1 );
		tmp *= i;
	}
	ans /= tmp;
	return ans;
}

int main()
{
	cout << C( 24,4 ) << endl;
}

