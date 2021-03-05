#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define all(x) (x).begin(),(x).end()

struct node{
	int head, rear;
	bool operator<( const node & x ) const {
		return rear < x.rear;
	}
}; 

int main()
{
	int n;
	cin >> n;
	vector<node> v(n);
	rep( i,0,n ) cin >> v[i].head >> v[i].rear;
	sort(all(v));
	int ans = 0, nowRear = 0;
	rep( i,0,n ){
		if( v[i].head >= nowRear ){
			ans++;
			nowRear = v[i].rear;
		}
	}  
	cout << ans << endl;
}


