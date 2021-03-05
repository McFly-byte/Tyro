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

ll v[1000001];
ll ans[1000001];
int n;

void dfs( int i, int j ){ //i到j内的v值都相同,inclusive
	if( ans[i]<ans[i-1] && ans[j]<ans[j+1] && ans[i]!=1)  { //极小 
		ret(k,i,j) ans[k] = 1;
		int k = i-1;
		while( k > 1 && ans[k-1] == ans[i-1] ) k--; 
		if( k < i-1 ) dfs(k,i-1);
		else dfs(i-1,i-1);
		k = j+1;
		while( k < n && ans[k+1] == ans[j+1] ) k++; 
		if( k > j+1 ) dfs(j+1,k);
		else dfs(j+1,j+1);
	}
	else if( ans[i]<ans[i-1] && ans[j]-ans[j+1]>=2 ) { //递减 
		ret(k,i,j) ans[k] = ans[j+1]+1;
		int k = i-1;
		while( k > 1 && ans[k-1] == ans[i-1] ) k--; 
		if( k < i-1 ) dfs(k,i-1);
		else dfs(i-1,i-1);
	}
	else if( ans[j]<ans[j+1] && ans[i]-ans[i-1]>=2 ){ //递增 
		ret(k,i,j) ans[k] = ans[i-1]+1;
		int k = j+1;
		while( k < n && ans[k+1] == ans[j+1] ) k++; 
		if( k > j+1 ) dfs(j+1,k);
		else dfs(j+1,j+1);
	}
	else if( ans[i]-ans[i-1]>=2 && ans[j]-ans[j+1]>=2 ){ //极大 
		ret(k,i,j) ans[k] = max(ans[i-1],ans[j+1])+1;
		int k = i-1;
		while( k > 1 && ans[k-1] == ans[i-1] ) k--; 
		if( k < i-1 ) dfs(k,i-1);
		else dfs(i-1,i-1);
		k = j+1;
		while( k < n && ans[k+1] == ans[j+1] ) k++; 
		if( k > j+1 ) dfs(j+1,k);
		else dfs(j+1,j+1);
	} 
	else return ;
} 

int main()
{
	v[0] = 0;
	cin >> n;
	ret( i, 1, n ) cin >> v[i];
	ans[1] = 1;
	ret( i, 2, n ){
		if( v[i] > v[i-1] ) ans[i] = ans[i-1]+1;
		else if( v[i] < v[i-1] ) ans[i] = ans[i-1]-1;
		else ans[i] = ans[i-1];
	}
	int min = ans[1];
	ret(i, 2, n ) {
		if( ans[i] < min ) min = ans[i];
	}
	if( min < 1 ) ret( i, 1, n ) ans[i]+=(1-min);
	int j;
	ret( i, 1, n ) {
		if( ans[i] != ans[i+1] ) dfs(i,i);
		else {
			j = i;
			while( ans[i] == ans[i+1] && i+1 <= n ) i++;
			dfs( j, i );
		}
	} 
	ll sum = 0;
	ret( i, 1, n ) sum += ans[i];
	cout << sum << endl;
}
