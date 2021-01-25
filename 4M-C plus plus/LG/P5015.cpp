#include <iostream>
using namespace std;
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)

int main()
{
	string str;
	getline( cin, str );
	int cnt = 0;
	rep( i, 0, str.length() ){
		if( str[i] != ' ' && str[i] != '\n' ) cnt++;
	}
	cout << cnt << endl;
}
