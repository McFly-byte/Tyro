#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define maxn 2000001

struct node{
	double head,rear;
	bool operator<( const node &x ) const {
		return head < x.head;
	}
};
node a[maxn];

int main()
{
	int n, d, dd, x, y;
	double w;
	cin >> n >> d;
	dd = d*d;
	rep( i,0,n ){
		cin >> x >> y;
		if( abs(y) > d ) {
			cout << -1 << endl;
			return 0;
		}
		w = sqrt( dd - y*y );
		a[i].head = x-w, a[i].rear = x+w;
	}
	sort( a, a+n );
	int sign = 0, ans = 0;
	rep( i,1,n ){
		bool flag = false;
		rep( j,sign,i ){
			if( a[i].head > a[j].rear ){
				flag = true;
				break;
			}
		}
		if( flag ){
			ans++;
			sign = i;
		}
	} 
	cout << ans+1 << endl;
} 
