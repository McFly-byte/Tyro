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

int a[40][40] = {0};//���1~n 

int main()
{
	int n;
	cin >> n;
	memset( a, -1, sizeof(a) );
	a[1][n/2+1] = 1;
	ret( i, 2, n*n ){
		//�ڵ�һ�У��������һ�� 
		ret( j, 1, n-1 ){
			if( a[1][j] == i-1 ){
				a[n][j+1] = i;
			}
		}
		//�����һ�е����ڵ�һ��
		ret( j, 2, n ){
			if( a[j][n] == i-1 ){
				a[j-1][1] = i;
			}
		}
		//�� (K-1) �ڵ�һ�����һ�У��� K���� (K-1) �����·���
		if( a[1][n] == i-1 ) a[2][n] = i;
		//�� (K-1)�Ȳ��ڵ�һ�У�Ҳ�������һ�У����(K-1)�����Ϸ���δ������
		//��K����(K-1)�����Ϸ������� K����(K-1)�����·���
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
