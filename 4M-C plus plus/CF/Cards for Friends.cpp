/**
 *    author:  McFly
 *    created: 05.01.2021  
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

int main(){
	int T;
	cin >> T;
	int a, b , n, t, cnt;
	while ( T-- ){
		cin >> a >> b >> n;
		t = a * b;
		int i = 1;
		while( t % i == 0 ) i *= 2;
		i /= 2;
		//cout << i << endl;
		if( i >= n ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
} 
