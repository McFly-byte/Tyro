/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define PI 3.1415926535897932385
#define MOD 1000000007LL
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define mp make_pair
#define pb push_back
#define rt insert
#define it iterator
typedef long long ll;

int main()
{
	int n,h,wt,ft;//walk-time, fishing-time
	cin >> n >> h; 
	h *= 60;
	int f[n], d[n], t[n];
	rep( i,0,n ) cin >> f[i];
	rep( i,0,n ) cin >> d[i];
	t[0] = 0; 
	rep( i,1,n ) cin >> t[i];//走到i湖要加 t[i] 
//	system( "pause" );
	int now, max = 0, tmp;
	rep( i,0,n ){
		wt = 0;
		priority_queue<int> q;
		ret( j,0,i ){
			 wt += t[j]*5;
		}
		ft = h-wt; 
		ret( j,0,i ){
			int k = 0;
			tmp = f[j];
			while( tmp > 0 && k*5 <= ft ){
				q.push( tmp );
				tmp -= d[j];
				k++;
			}
		}
		now = 0;
		while ( ft > 0 && !q.empty() ){
			now += q.top();
//			cout << i << ' ' << q.top() << endl;
			q.pop();
			ft -= 5;
		}
		if( now > max ) max = now;
	}
	cout << max << endl;
}

