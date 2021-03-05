/**
 *    author:  McFly
 *    created: 02.2021 
 *	  describ: 
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define MOD 1000000007LL
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

struct cow{
	int A,B;
	int No;
	int stallID;
	bool operator<( const cow & x ) const {
		return A < x.A;
	}
}; 

bool cmp( const cow &a, const cow &b ){
	return a.No < b.No;
} 

#define maxn 500001
cow a[maxn];

struct stall{
	int endTime;
	int ID;
	bool operator<( const stall & s ) const {
		return endTime > s.endTime;		
	}
} tmp;

int num = 0;

int main()
{
	int n;
	cin >> n;
	rep( i,0,n ){
		cin >> a[i].A >> a[i].B;
		a[i].No = i+1;
	}
	sort( a, a+n );
//	rep( i,0,n ) cout << a[i].A << a[i].B << endl;
	priority_queue<stall> q; 
	rep( i,0,n ){
		if( q.empty() ){
			tmp.ID = ++num;
			tmp.endTime = a[i].B;
			q.push( tmp );
			a[i].stallID = tmp.ID;
		}
		else{
			tmp = q.top();
//			cout << tmp.ID << ' ' << tmp.endTime << ' ' << a[i].No << ' ' << a[i].A << endl;;
			if( tmp.endTime < a[i].A ){
				q.pop();
				tmp.endTime = a[i].B;
				q.push( tmp );
				a[i].stallID = tmp.ID;
			}
			else {
				tmp.ID = ++num;
				tmp.endTime = a[i].B;
				q.push( tmp );
				a[i].stallID = tmp.ID;
			}
		}
	} 
	cout << num << endl;
	sort( a, a+n, cmp );
	rep( i,0,n ) cout << a[i].stallID << endl;
}

