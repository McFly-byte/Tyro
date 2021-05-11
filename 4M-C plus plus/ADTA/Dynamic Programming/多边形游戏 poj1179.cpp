/**
 *    author:  McFly
 *    created: 04.2021 
 *	  describ:  多边形游戏 poj1179 / 洛谷P4342				
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define RINF -1061109567
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define pb push_back
#define it iterator
typedef long long ll;
typedef unsigned long long ull;

#define max(a,b,c,d) max(max(a,b),max(c,d))
#define min(a,b,c,d) min(min(a,b),min(c,d)) 

int Fi[55][55], Fa[55][55];

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int n;
	cin >> n;
	vector<int> d(n+1);
	vector<char> s(n+1);
	ret( i,1,n ) cin >> s[i] >> d[i];
	int Min,Max,tmp[5];
	ret( j,1,n ){ //从第i个开始往后数j个
		ret( i,1,n ){ 
			if( j == 1 ) Fi[i][j] = Fa[i][j] = d[i];
			else{
				Min = INF, Max = RINF;
				ret( k,1,j-1 ){
					if( s[(i+k-1)%n+1] == '+' || s[(i+k-1)%n+1] == 't' ){
						tmp[0] = Fi[i][k] + Fi[(i+k-1)%n+1][j-k];
						if( tmp[0] < Min ) Min = tmp[0];
						tmp[0] = Fa[i][k] + Fa[(i+k-1)%n+1][j-k];
						if( tmp[0] > Max ) Max = tmp[0];
//						if( i == 1 && j == 3 ) cout << Min << ' ' << Max << endl; 
					}
					else if( s[(i+k-1)%n+1] == '*' || s[(i+k-1)%n+1] == 'x' ){
						tmp[1] = Fi[i][k] * Fi[(i+k-1)%n+1][j-k];
						tmp[2] = Fi[i][k] * Fa[(i+k-1)%n+1][j-k];
						tmp[3] = Fa[i][k] * Fa[(i+k-1)%n+1][j-k];
						tmp[4] = Fa[i][k] * Fi[(i+k-1)%n+1][j-k];
						tmp[0] = min( tmp[1],tmp[2],tmp[3],tmp[4] );
						if( tmp[0] < Min ) Min = tmp[0];
						tmp[0] = max( tmp[1],tmp[2],tmp[3],tmp[4] );
						if( tmp[0] > Max ) Max = tmp[0];
					}	
				}			
				Fi[i][j] = Min;
				Fa[i][j] = Max;
			}
		}
	}
//	
//	ret( i,1,n ){
//		ret( j,1,n ) {
//			cout << Fa[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	ret( i,1,n ){
//		ret( j,1,n ) {
//			cout << Fi[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	vector<int> ans;
	ret( i,1,n )
			if( Fa[i][n]> Max ){
				Max = Fa[i][n];
				vector<int>().swap( ans );
				ans.pb( i ); 
			}
			else if( Fa[i][n] == Max ) ans.pb( i );
	cout << Max << endl;
	rep( i,0,ans.size() ) cout << ans[i] << ' ';
}
