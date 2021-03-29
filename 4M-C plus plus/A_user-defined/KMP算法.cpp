#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
int Next[MAXN];

#define ERROR -1;

typedef int Position;

void initNext( string s )
{
	int i = 0, k = -1, len = s.length();
	Next[0] = -1;
	while( i < len )
	{
		if( k == -1 || s[i] == s[k] )
		{
			i++,k++;
			Next[i] = k;	
		}
		else k = Next[k];
	}
}

Position KMP( string s, string sub )
{
	int slen = s.length(), tlen = sub.length(), i = 0, j = -1;
	while( i < slen && j < tlen ){
		if( j == -1 || s[i] == sub[j] )
			i++, j++;
		else
			j = Next[j];
	}
	if( j >= tlen ) return i-tlen;
	else return ERROR;
}

int main()
{
	string s,sub;
	cin >> s >> sub;
	initNext( sub );
	cout << KMP( s, sub ) << endl;
}
