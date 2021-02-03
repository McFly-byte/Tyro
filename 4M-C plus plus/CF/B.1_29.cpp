/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ: 其实相当于所有的changes都加到了第一个（p0）上面，不知道为什么会过
 *           感觉自己有点懂了，因为修改的都是前面的数，从后向前看，pi与pi-1都
 	 	     未变就不说了;pi不变而pi-1改变，则changes加到左边分子还是分母上对
			 右边分母无影响，而对于左边，都加到分母肯定较分散两边更小，满足条件 
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
	int t , n , k;
	cin >> t;
	while ( t-- ){
		cin >> n >> k;
		vector<ll> v(n);
		vector<ll> carry;
		ll nowsum = 0, tmp , ans = 0;
		for ( int i = 0; i < n; i++ ) {
			cin >> v[i];
			nowsum += v[i];
		}
		for ( int i = n-1; i > 0; i-- ){
			nowsum -= v[i];
			if( v[i]*100 > nowsum*k ) {
				tmp = nowsum;
				nowsum = ( v[i]*100 ) / k;
				if( nowsum * k < v[i]*100 ) nowsum++;
//				cout << i << "  v[i]" << v[i] << "  nowsum" << nowsum << "  tmp" << tmp << endl;
				ans = ans+(nowsum-tmp);
			}
		}
		cout << ans << endl;
	}
}
