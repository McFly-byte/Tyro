/**
 *    author:  McFly
 *    created: 01.2021 
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
	int t,n;
	cin >> t;
	while ( t-- ){
		cin >> n;
		vector<int> v(n);
		for ( int i = 0; i < n; i++ ) cin >> v[i];
		int cnt = 1, ans = 1;  
		for ( int i = 1; i < n; i++ ) {
			if( v[i] != v[i-1] ) {
				if( cnt > ans ) ans = cnt;
				cnt = 1;
			}
			else{
				cnt++;
			} 
		}
		if( cnt > ans ) ans = cnt;
		cout << ans << endl;
	}	
}

/*
其实不用这么麻烦，本质上是数出现次数最多的数的次数
for ( int i = 0; i < n; i++ ){
	cin >> tmp;
	v[tmp]++;
}
sort( all(v) , greater<int>() );
cout << v[0] << endl;
即可 
*/
