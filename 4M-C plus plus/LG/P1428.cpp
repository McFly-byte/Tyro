//P1428
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, n;
	vector<int> v;
	cin >> T;
	while ( T-- ){
		cin >> n;
		v.push_back( n );
	}
	int sum;
	for ( int i = 0; i < v.size(); i++ ){
		sum = 0;
		for ( int j = 0; j < i; j++ ){
			if( v[j] < v[i] ) sum++;
		}
		if( i ) cout << ' '; 
		cout << sum;
	}
 } 
