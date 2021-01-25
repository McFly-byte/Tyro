#include <bits/stdc++.h>
using namespace std;

#define eps 10e-6
#define _rep(k,l,r) for( int k = l; k <= r; k++ )
#define _for(k,l,r) for( int k = l; k < r; k++ )

bool isEqual( string a , string b );
string Minus( string a , string b ) ;
bool frontIsBig( string a , string b );
string Divide( string a , string b );
string Mod( string a ,  int n );
string Add( string a , string b );
string Mult( string a , string b );
string getMin( int n );
string getMax( int n );

int main()
{
	int n , k;
	cin >> n >> k;
	string Min( n, '1' ), Max( n, '6' );
	long count = 0;
	for( string i = Min; i <= Max; i = Add( i , "1" ) ){
		if( Mod( i , k ) == "0" )
			count++;
		count %= 1000000007;
	}
	cout << count << endl;
}

bool isEqual( string a , string b )
{
	if( a.length() == b.length() ){
		for( int i = 0 ; i < a.length(); i++ ){
			if( a[i] != b[i] ) return false;
		}
		return true;
	}
	return false;
}

string Minus( string a , string b ) // 大数减，默认a大于b 
{
	if( isEqual( a , b ) ){		//相同时为零，这个也很重要 
		return "0";
	}							
	 string ans(256 , '0' );
	 reverse( a.begin() , a.end() );
	 reverse( b.begin() , b.end() );
	int alen = a.length() ,blen = b.length(), carry = 0, i;
	for( i = 0 ; i < alen; i++ ){ 
		if( i >= blen ){
			ans[i] = a[i]+carry;
			carry = 0;				//carry用过后要归零 
			if( ans[i] < '0' ){
				ans[i] += 10;
				carry = -1;
			}
			continue;	
		}
		ans[i] = (a[i]-'0')-(b[i]-'0')+carry+'0';
		carry = 0;				//同理 
		if( ans[i] < '0' ){
			ans[i] += 10;
			carry = -1;		//0&26都对应z，遇到0要给前一位减一 
		}
	}
	reverse( ans.begin() , ans.end() );
	while( ans[0] == '0' ) ans.erase(0,1);
	return ans ;
}

bool frontIsBig( string a , string b )//a是否大于等于b 
{
	if( b.length() > a.length() ) return false;
	if( b.length() < a.length() ) return true;
	for( int i = 0 ; i < a.length(); i++ ){
		if( a[i] > b[i] ) return true;
		if( a[i] < b[i] ) return false;
	}
	return true;
}


string Divide( string a , string b )//默认a大于等于b 
{
	string ans = "0";
	if( !frontIsBig( a , b ) ){	//a小了返回零 
		return "0";
	}
	string base , carry; 
	int blen = b.length(), alen = a.length(), i = blen-1;
	while ( frontIsBig( a , b ) ){
		base = b;carry = "1";
		while( frontIsBig( a, Mult( base , "10" ) ) ){ //注意判断可行后 
			base = Mult( base , "10" );				  //才能给他乘上去 
			carry = Mult( carry , "10" );
		}
		a = Minus( a , base );
		ans = Add( ans , carry );
	}
	return ans;
}

string Mod( string a ,  int n )
{
	char stri[10];
	itoa( n , stri , 10 );
	string str = stri;
	string ans = Divide( a , str );
	return Minus( a , Mult( ans , str ) );
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
