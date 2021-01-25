#include <bits/stdc++.h>
using namespace std;

string go( string );

int main()
{
	string str , ans = "0";
	getline( cin , str );
//	cout << str << endl;
	char * p = (char*)str.c_str();
	string s[7];
	char * tmp = strtok( p, " " );
	int i = 0;
	while( tmp ){
		s[i] = tmp;
//		cout << s[i] << endl;
		ans += go( s[i] );
//		cout << s[i] << '%' << ans << '%' << endl;
		i++;
		tmp = strtok( NULL , " " );
	} 
	while( ans.length() > 1 && ans[0] == '0' ) ans.erase(0,1);
	cout << ans << endl; 
//	for ( int i = 0; i < 7; i++ ) cout << s[i] << endl;
} 

string go( string a )
{
	string ans;
	if( a == "one" || a == "a" || a == "another" || a == "first" ) ans+="01";
	else if( a == "two" || a == "both" || a == "second" ) ans+="04";
	else if( a == "three" || a == "third" ) ans+="09";
	else if( a == "four" || a == "forth" ) ans+="16";
	else if( a == "five" ) ans+="25";
	else if( a == "six" ) ans+="36";
	else if( a == "seven" ) ans+="49";
	else if( a == "eight" ) ans+="64";
	else if( a == "nine" ) ans+="81";
	else if( a == "ten" ) ans+="100";
	else if( a == "eleven" ) ans+="121";
	else if( a == "twelve" ) ans+="144";
	else if( a == "thirteen" ) ans+="169";
	else if( a == "fourteen" ) ans+="196";
	else if( a == "fifteen" ) ans+="225";
	else if( a == "sixteen" ) ans+="256";
	else if( a == "seventeen" ) ans+="289";
	else if( a == "eighteen" ) ans+="324";
	else if( a == "nineteen" ) ans+="361";
	else if( a == "twenty" ) ans+="400";
	else return "";
	return ans;
 } 
