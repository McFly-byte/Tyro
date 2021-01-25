#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int n;
	cin >> n >> str;
	while ( n-- ){
		int t;
		cin >> t;
		if( t == 1 ){
			string tmp;
			cin >> tmp;
			str += tmp;
			cout << str << endl;
		}
		else if( t == 2 ){
			int a, b;
			cin >> a >> b;
			str = str.substr( a, b );
			cout << str << endl;
		}
		else if( t == 3 ){
			string tmp;
			int a;
			cin >> a >> tmp; 
			str.insert( a, tmp );
			cout << str << endl;
		}
		else {
			string tmp;
			cin >> tmp;
			int pos = str.find( tmp );
			if( pos != string::npos ) cout << pos << endl;
			else cout << -1 << endl;
 		}
	}
}
