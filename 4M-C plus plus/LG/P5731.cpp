/**
 *    author:  McFly
 *    created: 25.12.2020  
 *	  describ: 和hdu那道仙人球的残影不同，用多循环做，有点像快速排序的思想 
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define pause system("pause")
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int a[10][10];
int flag;

int main()
{
	int n;
	cin >> n;
	memset( a , 0 , sizeof(a) );
	int num = 1, i = 1, j = 1;
	while( num <= n*n ){
		while( a[i][j] == 0 && j <= n ) a[i][j++] = num++;j--;i++;
		while( a[i][j] == 0 && i <= n ) a[i++][j] = num++;i--;j--;
		while( a[i][j] == 0 && j >= 1 ) a[i][j--] = num++;j++;i--;
		while( a[i][j] == 0 && i >= 1 ) a[i--][j] = num++;i++;j++;//cout << i << j;
	} 
	for ( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= n; j++ )
			cout << setw(3) << a[i][j];
		cout << endl;
	}
 } 
