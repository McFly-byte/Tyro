/**
 *    author:  McFly
 *    created: 01.2021 
 *	  describ: ��ʵ�൱�����е�changes���ӵ��˵�һ����p0�����棬��֪��Ϊʲô���
 *           �о��Լ��е㶮�ˣ���Ϊ�޸ĵĶ���ǰ��������Ӻ���ǰ����pi��pi-1��
 	 	     δ��Ͳ�˵��;pi�����pi-1�ı䣬��changes�ӵ���߷��ӻ��Ƿ�ĸ�϶�
			 �ұ߷�ĸ��Ӱ�죬��������ߣ����ӵ���ĸ�϶��Ϸ�ɢ���߸�С���������� 
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
	int t , n , k;
	cin >> t;
	while ( t-- ){
		cin >> n >> k;
		vector<ll> v(n);
		vector<ll> carry;
		ll nowsum = 0, tmp , ans = 0;
		for ( int i = 0; i < n; i++ ) {
			cin >> v[i];
			nowsum += v[i];
		}
		for ( int i = n-1; i > 0; i-- ){
			nowsum -= v[i];
			if( v[i]*100 > nowsum*k ) {
				tmp = nowsum;
				nowsum = ( v[i]*100 ) / k;
				if( nowsum * k < v[i]*100 ) nowsum++;
//				cout << i << "  v[i]" << v[i] << "  nowsum" << nowsum << "  tmp" << tmp << endl;
				ans = ans+(nowsum-tmp);
			}
		}
		cout << ans << endl;
	}
}
