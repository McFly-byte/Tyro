/**
 *    author:  McFly
 *    created: 23.12.2020  
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

int main()
{
	vector<int> a,b;
	int n, k;
	cin >> n >> k;
	double s = 0, t = 0;
	int ss = 0, tt = 0;
	ret( i, 1, n ){
		if( i % k == 0 ) {
			s += i;
			ss++;
		}
		else {
			t += i;
			tt++;
		}
	}
	cout << fixed << setprecision(1) << s/ss << ' ' << t/tt << endl;
 } 
