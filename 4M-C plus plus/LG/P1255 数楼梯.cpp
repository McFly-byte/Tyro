#include<bits/stdc++.h>
using namespace std;

long long go( long long n ){
	if( n == 0 || n == 1 ) return 1;
	return go(n-1) + go(n-2);
}

int main()
{
	long long n;
	cin >> n; 
	cout << go(n) << endl;
}
