/**
 *    author:  McFly
 *    created: 23.12.2020  
 *	  describ: ���һ���ַ�����ÿ����ͬ�ַ�֮������࣬
 *       	   ���ֱȽϵ���Сֵ   
**/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define PI 3.1415926535897932385
#define INF 0x3f3f3f3f
#define EPS 10e-6
#define pause system("pause");
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define it iterator
typedef long long ll;

int main()
{
	int num[26], pos[26];
	memset( num , INF, sizeof( num ) );
	memset( pos, -1, sizeof( pos ) );
	string str;
	cin >> str;
	int len = str.length();
	rep( i, 0, len ){
		if( num[str[i]-'a'] == INF ) 
			num[str[i]-'a'] = i+1;
		else
			if( i-pos[str[i]-'a'] > num[str[i]-'a'] ) 
				num[str[i]-'a'] = i-pos[str[i]-'a'];
	//	cout << num[str[i]-'a'] << ' ' << i << endl;
		pos[str[i]-'a'] = i;
	}
	rep( i, 0, 26 ){
		if( len-pos[i] > num[i] ) 
			num[i] = len-pos[i];	//�����ĸ������һ�λᵼ�´���
									//��β����ǰҲҪ�������� 
	}
	sort( num, &num[26] );//��С���� 
	cout << num[0] << endl;
}
