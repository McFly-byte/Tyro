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
	int T, n , num, alice, bob;
	cin >> T;
	while( T-- ){
		alice = bob = 0;
		cin >> n;
		priority_queue<int> a , b;
		rep( i, 0, n ) {
			cin >> num ;
			if( num % 2 ) b.push( num );
			else a.push( num );
		}
		bool flag = true; //Alice first:even
		
		ret( i, 1, n ){
			if( flag ){
				if(  b.empty() || !a.empty() && !b.empty() && a.top() > b.top() ) {
					alice += a.top();
					a.pop();
				}
				else b.pop();
			} 
			else {
				if( a.empty() || !b.empty() && !a.empty() && b.top() > a.top() ){
					bob += b.top();
					b.pop();
				}
				else a.pop();
			}
			flag = !flag;
		}
		if( alice > bob ) cout << "Alice" << endl;
		else if( alice == bob ) cout << "Tie" << endl;
		else cout << "Bob" << endl;
	} 
}
