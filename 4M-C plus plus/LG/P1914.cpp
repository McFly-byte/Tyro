#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)

int main(){
	int n;
	string str;
	cin >> n >> str;
	int len = str.length();
	int tmp;
	n %= 26;
	rep( i, 0, len ){
		tmp = str[i] + n - 'a' + 1;
		while ( tmp > 26 ) tmp -= 26;
		str[i] = tmp + 'a' - 1;
	}
	cout << str << endl;
} 
