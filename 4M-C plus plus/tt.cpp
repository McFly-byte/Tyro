#include <bits/stdc++.h>
using namespace std;

struct node{
	string s;
	double a , b , c , sum;
};

double C( double a , double b ){
	double n = 1 , m = 1;
	for ( double i = a; i > a-b; i-- ) n *= i;
	for ( double i = 1; i <= b; i++ ) m *= i;
	return n/m;
}

int main()
{
//	int N;
//	cin >> N;
//	node n[N];
//	for ( int i = 0; i < N; i++ ){
//		cin >> n[i].s >> n[i].a >> n[i].b;
//		n[i].c = 0.7*n[i].a + 0.3*n[i].b;
//		n[i].sum = n[i].a + n[i].b;
//		if( n[i].sum > 140.0 && n[i].c >= 80.0 ) cout << "Excellent" << endl;
//		else cout << "Not excellent" << endl;
//	}
	double  n, m;
	while ( cin >> n >> m ){
		cout << C(n,m) << endl;
	}

 } 
 
