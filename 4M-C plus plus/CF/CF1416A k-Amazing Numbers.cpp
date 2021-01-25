/**
 *    author:  McFly
 *    created: 23.12.2020  
 *	  describ: 出现在所有区间中，最小的那个数
 *			   1) k < n < 2k 时方法出错 
 *			   2) 细节地方不行 
 *			   3) 样例过了，但WA 
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
typedef short int sint;

int a[500000];

int findDigit( int k , int n )
{
	vector<int> ans;
	int min;
	bool flag, tag; //tag判断结果是不是-1，//不用了，直接判断vector是否空 
					//flag判断这个min有没有出现在每一个区间内 
	rep( j, 0, k ){
		min = a[j];
		for ( int i = k; i < n-k+1; i ++ ){	//是i++而非i+=k，要确保每个连续区间都被覆盖 
			flag = false;	//每轮循环开始时初始化，没必要在循环外面多此一举 
			rep( e, i, i+k ){
				if( a[e] == min ){
					flag = true;
					break;
				}
			}
			if( !flag ) break;
		}
		if( flag )
			ans.pb( min );
	}

	if ( k > n/2 ){		//k < n < 2k
		rep( i, n-k, k ){
			min = a[i];
			vector<int>::it iter = find(ans.begin(),ans.end(),min);
			if( iter == ans.end() ) ans.pb( min ); 
		}
	}
	//cout << endl;
	//rep( i, 0, ans.size() ) cout << ans[i] << ' '; cout << endl; 
	//上面这个输出第一次把size写成n了。。 
	if( ans.begin() == ans.end() ) return -1;
	else sort( all(ans) );
	return ans[0];
}

int main()
{
	int T, n;
	cin >> T;
	while ( T-- ){
		cin >> n;
		rep( i, 0, n ) cin >> a[i];
		ret( k, 1, n ){
			cout << findDigit( k, n );
			if( k != n ) cout << ' ';
		}
		cout << endl;
	}
}
