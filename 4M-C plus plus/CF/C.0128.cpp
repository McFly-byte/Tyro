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

int main(){
	int t,n;
	cin >> t;
	while( t-- ){
		cin >> n;
		vector<ll> v(n*2);
		for ( int i = 0; i < n*2; i++ ) cin >> v[i];
		sort( all(v) , greater<int>() );	
		bool fg = false;
		for ( int i = 0; i < n*2; i++ ){
			if( v[i] % 2 == 1 ){//����������
				cout << "NO" << endl;
				fg = true;
				break;
			}
			if( i%2==1 && v[i]!=v[i-1] ){//��δ�ɶԵĲ���
				cout << "NO" << endl;
				fg = true;
				break;
			}
			if( !fg ){
				int k = v[0]/n;//����a�����ֵ��2�����κ�����������ֵ�������һ��k��
								//��ȥ���k�ٵ�����ȥ���ɵó�����������ֵ 
				for ( int i = 0; i < n*2; i++ );;; 
			} 
		} 
		
		// 
	}
}
