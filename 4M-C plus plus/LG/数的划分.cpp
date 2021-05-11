/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ:  				
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n+1][k+1]; 
	ret( i,1,n ){
		ret( j,1,k ){ // iµÄj»®·Ö 
			if( j == 1 ) a[i][j] = 1;
			else if( j > i ) a[i][j] = a[i][i];
			else if( j == i ) a[i][j] = 1+a[i][j-1];
			else if( j < i && j > 1 ) a[i][j] = a[i-j][j] + a[i][j-1];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << a[n][k] << endl;
}

