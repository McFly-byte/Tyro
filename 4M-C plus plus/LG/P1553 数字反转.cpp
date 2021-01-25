#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

int main(){
	string s;
	cin >> s;
	if( s.find('.',0) != s.npos ){
		char * ss = (char*)s.c_str();
		char * a = strtok( ss , "." );
		char * b = strtok( NULL , "." );
		string aa = a, bb = b;
		reverse( all(aa) ); 
		while( aa.length() > 1 && aa[0] == '0' ) aa.erase(0,1);
		while( bb.length() > 1 && bb[0] == '0' ) bb.erase(0,1);
		reverse( all(bb) );
		cout << aa << '.' << bb << endl;  
	}
	else if( s.find('/',0) != s.npos ){
		char * ss = (char*)s.c_str();
		char * a = strtok( ss , "/" );
		char * b = strtok( NULL , "/" );
		string aa = a, bb = b;
		reverse( all(aa) );reverse( all(bb) );
		while( aa.length() > 1 && aa[0] == '0' ) aa.erase(0,1);
		while( bb[0] == '0' ) bb.erase(0,1);
		cout << aa << '/' << bb << endl;
	}
	else if( s.find('%',0) != s.npos ){
		char * ss = (char*)s.c_str();
		char * a = strtok( ss , "%" );
		string aa = a;
		reverse( all(aa) );
		while( aa.length() > 1 && aa[0] == '0' ) aa.erase(0,1);
		cout << aa << '%' << endl;
	}
	else {
		reverse( all(s) );
		while ( s.length() > 1 && s[0] == '0' ) s.erase(0,1);
		cout << s << endl;
	}
} 
