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
	vector<int> v;
	int t , n , tmp;
	cin >> t;
	while( t-- ){
		cin >> n;
		for ( int i = 0; i < n*2; i++ ){
			cin >> tmp;
			v.pb( tmp );
		}
		sort( all( v ) , greater<int>() );
		int nowmax = v[0] , tag = 0 ;
		vector<int>::iterator pos;
		vector<int>::iterator i = v.begin();
		bool flag = true;
		v.erase(i);
		while ( i != v.end() ){
			if( i == v.end()-1 ){
				cout << "YES" << endl;
				break;
			}
			tag = nowmax - *i;
			cout << "tag:" << tag << endl;
			pos = find( i+1 , v.end() , tag );
			if( pos != v.end() ){
				nowmax = *i;
				v.erase( pos );
				v.erase( i );
				cout << "i" << *i << endl;
			} 
			else {
				if( flag ){
					flag = false;
					v.erase( i );
				}
				else {
					cout << "NO" << endl;
					break; 
				}
			}
			
		}
		v.clear();
	} 
}
