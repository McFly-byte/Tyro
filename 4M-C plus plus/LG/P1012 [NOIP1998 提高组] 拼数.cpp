#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define all(x) (x).begin(),(x).end()

#if 0 
一开始以为就是在greater的基础上前缀谁长谁往后
看了又错test4才发现并不是 
bool cmp( const string &a , const string &b ) {
	int alen = a.length() , blen = b.length(), n = min(alen,blen), m = max(alen,blen);
	int i;
	for ( i = 0; i < n; i++ ){
		if( a[i] > b[i] ) return true;
		else if( a[i] < b[i] ) return false;
	}
}
#endif 
 
 //大佬的超简短代码 
bool cmp( const string &a , const string &b ){
	return a+b>b+a;
}

int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++ ) cin >> v[i];
	sort( all(v),cmp );
	rep( i,0,n ) cout << v[i];
	cout << endl;
} 	
