/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ:     
**/
#include <bits/stdc++.h>
using namespace std; 

#define ios::sync_with_stdio(NULL);cin.tie(0);
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
	ll n,m;
	cin >> n >> m;
	ll a = max( n,m ), b = min( n,m ) , num1=0 , num2=0;
	for ( ll i = 0; i <= b; i++ ){
		num1 += ( a-i ) * ( b-i );
		num2 = num2 + (a-i)*( (b-i)*(b-1-i) / 2 ) + (b-i)*( (a-i)*(a-1-i) / 2 ); 
	}  
	cout << num1 << ' ' << num2 << endl;
}	
