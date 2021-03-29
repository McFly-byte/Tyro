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
#define INF 0x3f3f3f3f //1061109567
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

struct node{
	int value;
	int index;
	bool operator < ( const node & x ){
		return value >= x.value;
	}
};

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int n,k;
	cin >> n >> k;
	node a[n],b[k];
	rep( i,0,n ) {
		cin >> a[i].value;
		a[i].index = i+1;;
	}
	rep( i,0,k ) {
		cin >> b[i].value;
		b[i].index = i+1;
	}
	sort( a, a+n );
	sort( b, b+k );
	int ans[n];
	rep( i,0,k ){
		ans[b[i].index-1] = a[i].index;
	}
	rep( i,0,k ) cout << ans[i] << ' ';
	
}

