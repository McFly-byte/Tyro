#include <iostream>
using namespace std;

int a[10]={1},n,tot=0,num=0;

void print( int amount ) 
{
	if( amount == 1 ) return ;
	for ( int i = 1; i < amount; i++ ) cout << a[i] << '+';
	cout << a[amount] << endl;
}

void dfs( int m )
{
	for ( int i = a[tot]; i <= m; i++ ) //tot==0处只存值无意义 
	//i不能从一开始，应该从上一个数开始 
	{
		a[++tot] = i;
		num += i;
		if( num == n ) print(tot);
		else if( num > n ) break; //一大皆大 
		else dfs( m-i );
		tot--;
		num -= i;
	}

}

int main()
{
	cin >> n;
	dfs( n );
}
