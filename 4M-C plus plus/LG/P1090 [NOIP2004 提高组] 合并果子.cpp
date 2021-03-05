/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:     P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

int main()
{
	int n, tmp, ans=0;
	cin >> n;
	priority_queue<int,vector<int>,greater<int> > q;
	rep( i,0,n ){
		cin >> tmp;
		q.push( tmp ); 
	}
	int r1,r2;
	rep( i,1,n ){
		r1 = q.top();
		q.pop();
		r2 = q.top();
		q.pop();
		ans += (r1+r2);
		q.push(r1+r2);
	}
	cout << ans << endl;
}
