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
	for ( int i = a[tot]; i <= m; i++ ) //tot==0��ֻ��ֵ������ 
	//i���ܴ�һ��ʼ��Ӧ�ô���һ������ʼ 
	{
		a[++tot] = i;
		num += i;
		if( num == n ) print(tot);
		else if( num > n ) break; //һ��Դ� 
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
