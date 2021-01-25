/**
 *    author:  McFly
 *    created: 30.12.2020  
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
	int T, n, num, pos, maxsum, nowsum;
	cin >> T;
	while (T--){
		cin >> n;
		maxsum = 0;
		nowsum = 0;
		vector<int> v;
		vector<int> flag;
		v.pb( -1 );
		flag.pb(false);
		rep( i, 0, n ){
			cin >> num;
			v.pb( num );
			flag.pb(true);
		}
		ret( i, 1, n ){
			pos = i;
			while( pos <= n ){
				if( flag[pos] ){
					nowsum += v[pos];
					flag[pos] = false;
					pos += v[pos];
				}
				else break;
			}
			if( nowsum >= maxsum ) 
				maxsum = nowsum;
			nowsum = 0;
		}
		cout << maxsum << endl;
	}
}
