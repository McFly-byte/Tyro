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

struct node {
	int num; //牌的数量 
	int value; //牌面点数 
	int reset;
	int index; //打出这牌的人 
} tmp;

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int n,m, num;
	cin >> n >> m;
	int v[3][m], cnt[3];
	rep( i,0,3 ) cnt[i] = n;
	int *a = v[0], *b = v[1], *c = v[2];
	rep( i,0,3 ) rep( j,0,m ) v[i][j] = 0;
	rep( i,0,n ) {
		cin >> num;
		a[num-1]++;
	}
	rep( i,0,n ) {
		cin >> num;
		b[num-1]++;
	}
	rep( i,0,n ){
		cin >> num;
		c[num-1]++;
	}
	
	int turn = 0, fg;
	tmp.reset = 1;
	// turn下一位出牌选手，fg是否要得起， reset是否从头开始 
	while( cnt[0]>0 && cnt[1]>0 && cnt[2]>0 ){
		if( tmp.reset ){
			rep( i,0,m ) 
				if( v[turn][i]>0 ) {
					v[turn][i]--;
					cnt[turn]--;
					tmp.index = turn;
					tmp.num = 1;
					tmp.reset = 0;
					tmp.value = i;
//					cout << tmp.index+1 << ' ' << tmp.value+1 << ' ' << tmp.num << endl;
					break;
				} 
			turn = ( turn+1 ) % 3;
		}
		else {
			if( tmp.index == turn ) {
				tmp.reset = 1;
			}
			else {
				fg = 0;
				rep( i,tmp.value+1,m ){
					if ( v[turn][i]>=tmp.num ){
						v[turn][i] -= tmp.num;
						cnt[turn] -= tmp.num;
						tmp.value = i;
						tmp.index = turn;
						fg = 1;
//						cout << tmp.index+1 << ' ' << tmp.value+1 << ' ' << tmp.num << endl;			
						break;
					}	
				} 
				if( !fg ){
					rep( i,0,m ) {
						if( v[turn][i]>tmp.num ){
							v[turn][i] = v[turn][i] - tmp.num - 1;
							cnt[turn] = cnt[turn] - tmp.num - 1;
							tmp.value = i;
							tmp.index = turn;
							tmp.num++;
							fg = 1;
//							cout << tmp.index+1 << '	' << tmp.value+1 << ' ' << tmp.num << endl;	
							break;
						}
					}
				}
//				if( !fg ) cout << turn+1 << "要不起" << endl; 
				turn = ( turn+1 ) % 3;
			}
		}
//		cout << ' ' << cnt[0] << '	' << cnt[1] << '	' << cnt[2] << endl;
	} 
	rep( i,0,3 ) if( cnt[i] == 0 ) cout << i+1 << endl;
} 

