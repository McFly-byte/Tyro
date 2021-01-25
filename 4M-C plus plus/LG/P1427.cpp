//P1427
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	vector<int> v;
	while ( cin >> n && n ){
		v.push_back( n );
	}
	for( vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++ )
		if( it == v.rbegin() ) cout << *it;
		else cout << ' ' << *it;
 } 
