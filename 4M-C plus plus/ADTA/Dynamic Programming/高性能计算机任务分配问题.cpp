/**
 *    author:  McFly
 *    created: 04.2021 
 *	  describ:  	高性能计算机 wc2001 / P5813			
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f //1061109567
#define RINF -1061109567
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

struct node {
	int Ta, Tb;
	int Ka, Kb;
} tmp ;

int F[22][62][62]; // 第i台机器完成j个A与k个B所需时间 
int p[2][62][62]; //中转 
int C[22][62][62]; // 前i台机器协作完成j个A与k个B所需时间 

void dp1( node & , int , int , int );
void dp2( int , int , int );

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	int N[2], m;
	vector<node> v;
	cin >> N[0] >> N[1] >> m;
	rep( i,0,m ) {
		cin >> tmp.Ta >> tmp.Tb >> tmp.Ka >> tmp.Kb;
		v.pb( tmp );
		dp1( v[i],N[0],N[1],i ); 
		//算出每个结点 单独工作时 解决ab任务的最短时间 
		
		rep( a,0,N[0] ){
			rep( b,0,N[1] ){ 
				cout << setw(10) << p[0][a][b];
			}
			cout << endl;
		}
		cout << endl;
		rep( a,0,N[0] ){
			rep( b,0,N[1] ){ 
				cout << setw(10) << p[1][a][b] ;
			}
			cout << endl;
		}
		
		dp2( N[0],N[1],i );
	} 
	 
	rep( i,0,m ){
		ret( a,0,N[0] ){
			ret( b,0,N[1] ){ 
				cout << setw(10) << F[i][a][b];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << " - " << endl;;
	ret( i,0,m-1 ){
		ret( j,0,N[0] ){
			ret( k,0,N[1] ){
				cout << setw(10) << C[i][j][k]; 
			}
			cout << endl;
		}
		cout << endl;
	}
	
	cout << C[m-1][N[0]][N[1]] << endl; 
}

void dp1( node & n, int Na, int Nb, int index )
{
	tmp = n;
	int Min, Max, value;
	ret( a,0,Na ){
		ret( b,0,Nb ){
			if( a == 0 && b == 0 ) p[0][a][b] = p[1][a][b] = 0;
			else if( a == 0 ) {
				p[0][a][b] = INF;
				p[1][a][b] = tmp.Tb + tmp.Kb*b*b; 
			}
			else if( b == 0 ) {
				p[0][a][b] = tmp.Ta + tmp.Ka*a*a;
				p[1][a][b] = INF;
			}
			else {
				Min = INF; 
				ret( w,1,a ){
					value = p[1][a-w][b] + tmp.Ta + tmp.Ka*w*w;
					if ( value < Min ) Min = value;
				}
				p[0][a][b] = Min;
				Min = INF;
				ret( w,1,b ){
					value = p[0][a][b-w] + tmp.Tb + tmp.Kb*w*w;
					if ( value < Min ) Min = value;
				}
				p[1][a][b] = Min;
			}
			F[index][a][b] = min( p[0][a][b], p[1][a][b] );
		}
	}
}

void dp2( int Na, int Nb, int index )
{
	if( index == 0 ){
		ret( a,0,Na ) ret( b,0,Nb ) C[0][a][b] = F[0][a][b];
	}
	else {
		int Min, tmp;
		ret( a,0,Na )
		{
			ret( b,0,Nb )
			{
				Min = INF;
				ret( w1,0,a )
				{
					ret( w2,0,b )
					{
						if( w1 == 0 && w2 == 0 ) continue;
						if( w1 == a && w2 == b ) continue;
						tmp = max( C[index-1][a-w1][b-w2], 
												  F[index][w1][w2] );
						if( tmp < Min )  Min = tmp; 
					}
				}
				C[index][a][b] = Min;
			} 
		}
	}
 } 
