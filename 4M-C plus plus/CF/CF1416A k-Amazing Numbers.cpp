/**
 *    author:  McFly
 *    created: 23.12.2020  
 *	  describ: ���������������У���С���Ǹ���
 *			   1) k < n < 2k ʱ�������� 
 *			   2) ϸ�ڵط����� 
 *			   3) �������ˣ���WA 
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
	bool flag, tag; //tag�жϽ���ǲ���-1��//�����ˣ�ֱ���ж�vector�Ƿ�� 
					//flag�ж����min��û�г�����ÿһ�������� 
	rep( j, 0, k ){
		min = a[j];
		for ( int i = k; i < n-k+1; i ++ ){	//��i++����i+=k��Ҫȷ��ÿ���������䶼������ 
			flag = false;	//ÿ��ѭ����ʼʱ��ʼ����û��Ҫ��ѭ��������һ�� 
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
	//������������һ�ΰ�sizeд��n�ˡ��� 
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
