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

string Add( string a , string b );
string Mult( string a , string b );
string And( string a , string b );
string Or( string a , string b );

int main()
{
	int T, n;
	string sum, tmp;
	cin >> T;
	while ( T-- ){
		cin >> n;
		string a[n];
		rep( i, 0, n ) cin >> a[i];
		sum = "0",	m = "0";
		rep( i, 0, n ){
			rep( j, 0, n ){
				rep( k, 0, n ){
					tmp = Mult( And( a[i], a[j] ), Or( a[i], a[k] ) );
					sum = Add( sum , tmp );
				}
			}
		}
		cout << sum << endl;
	}
}

string Mult( string a , string b )
{
	string ans(256,'0');
	reverse( a.begin(), a.end() );
	reverse( b.begin(), b.end() );
	int value, carry = 0, remainder = 0, i, j;
	int alen = a.length(), blen = b.length();
	for( i = 0 ; i < alen; i++ ){
		for( j = 0 ; j < blen; j++ ){
			value = (ans[i+j]-'0')+carry+(a[i]-'0')*(b[j]-'0');
			carry = value/10;
			ans[i+j] = value%10+'0';
		} 
		if( carry ){
			ans[i+j] = carry+'0';
			carry /= 10;
		}
	}
	reverse( ans.begin() , ans.end() );
	while ( ans[0] == '0' ) ans.erase(0,1);
	return ans;
}

string Add( string a , string b )
{
	reverse( a.begin() , a.end() );
	reverse( b.begin() , b.end() );
	string ans(256,'0');
	int value = 0 , carry = 0;
	int i , j , alen = a.length() , blen = b.length();
	if( alen < blen ){
		swap( a , b );
		swap( alen , blen ); //cout << a << b << endl;
	}
	for( i = 0 ; i < alen ; i++ ){
		if( i >= blen ){
			value = (a[i]-'0') + carry;
			carry = value / 10;
			ans[i] = value % 10 + '0';
			continue;
		}
		value = (a[i]-'0') + (b[i]-'0')+carry;
		carry = value/10;
		ans[i] = value % 10 + '0';
	}
	if( carry ){
		ans[i] = carry + '0';
	}
	reverse( ans.begin() , ans.end() );
	while ( ans[0] == '0' ) ans.erase( 0, 1 );
	return ans;
}

