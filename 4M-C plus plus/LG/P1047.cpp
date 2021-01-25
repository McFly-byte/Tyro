/**
 *    author:  McFly
 *    created: 29.12.2020  
 *	  describ:     
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

bool b[100000];

int main()
{
	int n, k, num = 0, l, r;
	cin >> n >> k;
	memset( b, true, sizeof(b) );
	while( k -- ) {
		cin >> l >> r;
		ret( i, l, r ){
			b[i] = false;
		}
	} 
	ret( i, 0, n ) if( b[i] ) num++;
	cout << num << endl;
} 
