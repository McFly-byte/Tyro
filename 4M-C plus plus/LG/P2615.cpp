/**
 *    author:  McFly
 *    created: 25.12.2020  
 *	  describ:     
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

int a[40][40] = {0};//编号1~n 

int main()
{
	int n;
	cin >> n;
	memset( a, -1, sizeof(a) );
	a[1][n/2+1] = 1;
	ret( i, 2, n*n ){
		//在第一行，不在最后一列 
		ret( j, 1, n-1 ){
			if( a[1][j] == i-1 ){
				a[n][j+1] = i;
			}
		}
		//在最后一列但不在第一行
		ret( j, 2, n ){
			if( a[j][n] == i-1 ){
				a[j-1][1] = i;
			}
		}
		//若 (K-1) 在第一行最后一列，则将 K填在 (K-1) 的正下方；
		if( a[1][n] == i-1 ) a[2][n] = i;
		//若 (K-1)既不在第一行，也不在最后一列，如果(K-1)的右上方还未填数，
		//则将K填在(K-1)的右上方，否则将 K填在(K-1)的正下方。
		bool fg = true;
		ret( j, 1, n ){
			if( a[1][j] == i-1 || a[j][n] == i-1 ){
				fg = false;
				break;
			}
		}
		if( fg ) {
			ret( j, 2, n ){
				ret( k, 1, n-1 ){
					if( a[j][k] == i-1 ){
						if( a[j-1][k+1] == -1 ) a[j-1][k+1] = i;
						else a[j+1][k] = i;
					}
				}
			}
		}
	}
	ret( i, 1, n ){
		ret( j, 1, n ){
			if( j != 1 ) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
}
