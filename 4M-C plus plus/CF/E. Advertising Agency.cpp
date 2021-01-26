#include <bits/stdc++.h>	//选排列写的有问题，没可能出现浮点 
using namespace std;		//改用杨辉三角写果然AC了 

//long long C( long long a , long long b ){
//	long long n = 1 , m = 1;
//	for ( long long i = a; i > a-b; i-- ) n *= i;
//	for ( long long i = 1; i <= b; i++ ) m *= i;
//	return n/m;
//}

const int N = 2010, M = 1e9 + 7;
int C[N][N];
 
void init() {
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }
}

int main()
{
	init();
	int t , n , k , tmp , count;
	cin >> t;
	while ( t-- ){
		cin >> n >> k;
		vector<int> v;
		count = 0;
		for ( int i = 0; i < n; i++ ) {
			cin >> tmp;
			v.push_back( tmp );
		}
		sort( v.begin() , v.end() , greater<int>() );
		int a = v[k-1] , i = 0;
		for ( ; i < n; i++ ) if( v[i] == a ) break;
		int b = k-i;
		for ( i ; i < n; i++ ) {
			if( v[i] == a ) count++;
			else break;
		}
		cout << C[count][b] << endl;
	} 
}
