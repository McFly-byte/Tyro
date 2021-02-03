#include <bits/stdc++.h>
using namespace std;

void fun( int n ){
//	if( n == 0 ){
//		cout << 0;
//		return ;
//	}
	vector<int> v;
	while ( n ){
		v.push_back(n%2);
		n /= 2; 
	}
	int num;
	bool fg = false;
	for ( int i = v.size()-1; i >= 0; i-- ){
		if( v[i] == 0 ) continue;
		num = pow(2,i);					
		if( fg ) cout << '+';
		fg = true;
		if( num == 1 )			
			cout << "2(0)";
		else if( num == 2 )
			cout << 2;
		else {
			cout << 2 << '(';
			fun(i); 
			cout << ')';
		}	
	}
}

int main()
{
	int n;
	 cin >> n ;
	fun(n);
}
