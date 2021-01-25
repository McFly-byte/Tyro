#include <iostream>
#include <algorithm> 
using namespace std;

#define eps 10e-6
#define _rep(k,l,r) for( int k = l; k <= r; k++ )
#define _for(k,l,r) for( int k = l; k < r; k++ )

struct node {
	int t , k;
	int value;
	int id;
	friend bool operator < ( node a , node b ){
		if( a.value == b.value && a.t == b.t ) return a.id < b.id;
		if( a.value == b.value ) return a.t > b.t;
		return a.value > b.value;
	}
};

int main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	int n;
	cin >> n ;
	node a[n];
	int t, k;
	for( int i = 0 ; i < n; i++ ){
		cin >> a[i].t >> a[i].k;
		a[i].value = a[i].t * a[i].k;
		a[i].id = i + 1;
	}
	sort( a, &a[n] );
	for( int i = 0; i < n; i++ ){
		if( i ) cout << ' ';
		cout << a[i].id;
	}
} 
