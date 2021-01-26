#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t , n , w , k;
	cin >> t;
	while ( t-- ){
		cin >> n;
		w = n / 2020;
		k = n % 2020;
		if( k <= w ) cout << "Yes" << endl;
		else cout << "No" << endl; 
	}
}
