/**
 *    author:  McFly
 *    created: 29.12.2020  
 *	  describ: ×¢Òâ¾«¶È   
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-10
#define pause system("pause")
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

int main()
{
	double k, s = 0, i = 1;
	cin >> k;
	while( s-k <= EPS ) {
		s += 1.0/i;
		i++;
	}
	cout << i-1 << endl;
}
