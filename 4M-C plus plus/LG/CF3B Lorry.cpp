/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 大概思路把1的两两合并成2(不够补'0',单数去一个1) 
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define qwe system("pause");
#define pcsn(x) fixed<<setprecision(x)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define rt insert
#define it iterator
typedef long long ll;

struct node {
	int id;
	int id2;	//备用 
	int vl;
	bool operator<( const node &a ) const {
		return vl > a.vl;
	}
}tmp, v[2][100001];

int main()
{
	int n,m,w;
	cin >> n >> m; //物品数，载重 
//	vector<node> v[2];
	int tot[2] = {0};// 1，2个数 
	rep( i,0,n ){
//		cin >> w >> tmp.vl;
		cin >> w;
		cin >> v[w-1][tot[w-1]].vl;
		v[w-1][tot[w-1]].id = i+1;
		v[w-1][tot[w-1]].id2 = 0;
		tot[w-1]++;
//		tmp.id = i+1;
//		tmp.id2 = 0;
//		v[w-1].pb( tmp );
	}
//	if( m == 1 ) {
//		sort( all(v[0]) );
//		cout << v[0][0].vl << endl;
//		cout << v[0][0].id ;
//		return 0;
//	}
	
	ll sum=0, value=0, i=0;
	vector<int> order;
	sort( v[0], v[0]+tot[0] );
	if( m % 2 == 1 && tot[0] > 0 ){	// 载重为单数先去掉一个1 
		order.pb( v[0][0].id );
		value += v[0][0].vl;
		sum += 1;
//		v[0].erase( v[0].begin() );
		rep( i,0,tot[0]-1 ) v[0][i] = v[0][i+1];
		tot[0]--;
	}
	if( tot[0] % 2 == 1 ) {	//1数目为奇数则补进'0' 
//		v[0].pb(node{n+1,0,0});
		tmp.id = n+1, tmp.id2 = 0, tmp.vl = 0;
		v[0][tot[0]++] = tmp;
	}
	rep( i,0,tot[0] ){
		tmp.vl = v[0][i].vl+v[0][i+1].vl;
		tmp.id = v[0][i].id;
		tmp.id2 = v[0][i+1].id;
//		v[1].pb( tmp );
		v[1][tot[1]] = tmp;
		tot[1]++;
		i++;
	}
	
	sort( v[1],v[1]+tot[1] );
	while( sum < m && i < tot[1] ){
		if( sum + 2 <= m ){
			value += v[1][i].vl;
			order.pb( v[1][i].id );
			if( v[1][i].id2 ) {
				if( v[1][i].id2==n+1 ) sum += 1;
				else {
					order.pb( v[1][i].id2 );
					sum += 2;
				}
			}
			else sum += 2;
		}
		else {
			if( v[1][i].id2 && v[1][i].id2==n+1 ){
				sum ++;
				order.pb(v[1][i].id);
				value += v[1][i].vl;
			}
		}
		i++;
	}
	cout << value << endl;
//	if( order.empty() ) cout << endl;
//	else
		rep( i,0,order.size() ) cout << order [i] << ' ';
}

