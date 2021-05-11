#include <bits/stdc++.h>
using namespace std; 

#define INF 99999999
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)

typedef map<int,int>::iterator it;
map<int,int> Map;

int main()
{
	int n,value,ans = INF;
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> value;
		Map[value] += 1;
	} 
	while ( !Map.empty() )
	{
		it i = Map.begin(), j = Map.begin();
		(*i).second--;
		++j;
		value = 1;
		while ( j != Map.end() && (*j).first == (*i).first+1 && (*j).second > (*i).second ){
			 value++;
			 (*j).second--;
			 i++,j++;
		} 
		ans = min( ans, value );
		i = Map.begin();
		while ( i != Map.end() && (*i).second == 0 ) Map.erase((*i++).first);
	}
	cout << ans << endl;
} 
