				//��������㣬��������2020.12.15 17:29:24 
				//�˼ӷ��򵥣�����֮ǰ�漰���ٲ�һ�㣬�Ƚϸ��ӵľ��ǳ������˳���ȡ��Ҳ�ͼ���
				 
#include <iostream> 
#include <algorithm> 
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

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

bool frontIsBig( string a , string b )//a�Ƿ���ڵ���b 
{
	if( b.length() > a.length() ) return false;
	if( b.length() < a.length() ) return true;
	for( int i = 0 ; i < a.length(); i++ ){
		if( a[i] > b[i] ) return true;
		if( a[i] < b[i] ) return false;
	}
	return true;
}

string Minus( string a , string b ) // ��������Ĭ��a����b 
{
	if( isEqual( a , b ) ){		//��ͬʱΪ�㣬���Ҳ����Ҫ 
		return "0";
	}							
	 string ans(256 , '0' );
	 reverse( a.begin() , a.end() );
	 reverse( b.begin() , b.end() );
	int alen = a.length() ,blen = b.length(), carry = 0, i;
	for( i = 0 ; i < alen; i++ ){ 
		if( i >= blen ){
			ans[i] = a[i]+carry;
			carry = 0;				//carry�ù���Ҫ���� 
			if( ans[i] < '0' ){
				ans[i] += 10;
				carry = -1;
			}
			continue;	
		}
		ans[i] = (a[i]-'0')-(b[i]-'0')+carry+'0';
		carry = 0;				//ͬ�� 
		if( ans[i] < '0' ){
			ans[i] += 10;
			carry = -1;		//0&26����Ӧz������0Ҫ��ǰһλ��һ 
		}
	}
	reverse( ans.begin() , ans.end() );
	while( ans[0] == '0' ) ans.erase(0,1);
	return ans ;
}

string Divide( string a , string b )//Ĭ��a���ڵ���b 
{
	string ans = "0";
	if( !frontIsBig( a , b ) ){	//aС�˷����� 
		return "0";
	}
	string base , carry; 
	int blen = b.length(), alen = a.length(), i = blen-1;
	while ( frontIsBig( a , b ) ){
		base = b;carry = "1";
		while( frontIsBig( a, Mult( base , "10" ) ) ){ //ע���жϿ��к� 
			base = Mult( base , "10" );				  //���ܸ�������ȥ 
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

void PrintNum( string a ) //��'��'�Ĵ�������� 
{
	int i = 0 , j = 0, alen = a.length();
	if( alen % 3 == 0 ){
		i = j = 0;
	} 
	else if( alen % 3 == 1 ){
		cout << a[0];
		if( alen > 1 ) cout << ',';
		i = j = 1;
	}
	else if( alen % 3 == 2 ){
		cout << a[0] << a[1];
		if( alen > 2 ) cout << ',';
		i = j = 2;
	}
	for( ; i < alen ; i++ ){
			cout << a[i];
			if( ( i - j ) % 3 == 2 && i != alen-1 ) cout << ',';
		}
	cout << endl;
}

string Pow1314( char a , int n )//�ѵ�nλ��ĸת��Ϊ��Ӧ����ֵ 
{
	int value = a - 'a' + 1;
//	cout << "value: " << value << endl;
	char stri[23]; 
	itoa( value, stri, 10 );
	string str = stri;
	string base = "1";
	for( int i = 0; i < n ; i++ ){			
		base = Mult( base , "26" );
	}
	str = Mult( base , str );
	return str;
}

string AtoD( string a )//��ĸת��Ϊ����  alpha to digit
{
	reverse( a.begin() , a.end() );
	int alen = a.length();
	string ans = "0";
	for( int i = 0; i < alen ; i++ ){
		ans = Add( ans , Pow1314( a[i] , i ) );
	} 
	return ans;
}

string DtoA( string a )
{
	string ans(256,'0');
	int i = 0;
	while( !isEqual( a , "0" ) ){
		string carry = Mod( a , 26 );
//		cout << "carry : " << carry << endl;
		int digit = atoi( carry.data() );
		if( digit == 0 ){
			digit += 26;
			a = Minus( a , "1" );
		}
		a = Divide( a , "26" );
//		cout << "a: " << a << endl;
		ans[i++] = 'a' + digit - 1; 
//		cout << "ans: " << ans << endl;
	}
	reverse( ans.begin() , ans.end() );
	while( ans[0] == '0' ) ans.erase( 0,1 );
	return ans;
}

int main()
{
	string a;
	while ( cin >> a && a != "*" ){
		if( isdigit( a[0] ) ){//����������֣�Ҫ�õ���ӦӢ������ 
			string str = DtoA( a );
			cout << std::left << setw(22) << str;
			PrintNum( a );
		}
		else if( isalpha( a[0] ) ){//�������Ӣ�ģ�Ҫ�õ����� 
			string str = AtoD( a );
			cout << std::left << setw(22) << a;
			PrintNum( str );
		}
	}
}
