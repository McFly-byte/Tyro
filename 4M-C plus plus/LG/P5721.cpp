/**
 *    author:  McFly
 *    created: 23.12.2020  
 *	  describ: 其实不用写函数转string，判断一下小于十多数出一个0就行  
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

string toNum( int n ){
	string ans;
	if( n < 10 ) ans = "0" + to_string( n );
	else ans = to_string( n );
	return ans;
}

int main()
{
	int n, id = 1;
	cin >> n;
	rep( i, 0, n ){
		rep( j, 0, n-i ) cout << toNum( id++ ) ;
		cout << endl;
	}
}
