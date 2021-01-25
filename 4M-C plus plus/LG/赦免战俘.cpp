/**
 *    author:  McFly
 *    created: 01.2021 
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

int a[1025][1025];

void go( int li , int lj , int ri , int rj , bool isLT ); //左上右下点坐标，是否为左上的一块 

int main()
{
	int n ;
	cin >> n;
	int rj = pow( 2 , n ), ri = rj;
	ret( i , 1 , ri ){
		ret( j , 1 , rj ){
			a[i][j] = 1;
		}
	}
	go( 1 , 1 , ri , rj , false );
	ret( i , 1 , ri ){
		ret( j , 1 , rj ){
			if( j != 1 ) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
} 

void go( int li , int lj , int ri , int rj , bool isLT ) //左上右下点坐标，是否为左上的一块 
{
	if( isLT ){
		ret( i, li , ri ){
			ret( j , lj , rj ){
				a[i][j] = 0;
			}
		}
		return ;
	}
//	ret( i , li , ri ){
//		ret( j , lj , rj ){
//			if( j != 1 ) cout << ' ';
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
	if( ri - li < 1 || rj - lj < 1 ) return ;
	int len = (ri-li+1)/2; 
	go( li , lj , li+len-1 , lj+len-1 , true );//左上 
	go( li , lj+len , li+len-1 , rj , false );//右上 
	go( li+len , lj , ri , lj+len-1 , false );//左下 
	go( li+len , lj+len , ri , rj , false );//右下 
 } 
