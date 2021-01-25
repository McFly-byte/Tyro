/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ:    B 
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define pause system("pause")
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

bool isPrime( int n ){
	if( n == 2 || n == 3 || n == 5 || n == 7 ) return true;
	for ( int i = 2; i <= n/2+1; i++ ){
		if( n % i == 0 ) return false;
	} 
	return true;
}

int main()
{
	int t , a , l , r;
	cin >> t;
	while ( t-- ){
		cin >> a;
		int i = 1;
		while( !isPrime( a+i ) ){
			i++;
		}
		l = a+i; //cout << "l:" << l << endl; 
		i = a;
		while( !isPrime( l+i ) ){
			i++;
		}
	//	cout << "i:" << i << endl;
		r = l + i;
	//	cout << "r:" << r << endl;
		cout << r * l << endl; 
	} 
}
