#include <iostream>
using namespace std;

char ch[101][101];
int a[101][101];

int main()
{
	int n, m;
	cin >> n >> m;
	cin.get();
	for ( int i = 1; i <= n; i++ ){
		cin.getline( ch[i], m+1 );
	}
}
