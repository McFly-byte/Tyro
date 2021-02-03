/**
 *    author:  McFly
 *    created: 30.12.2020  
 *	  describ:  (HINT）枚举 
 *				思路：1)用生成回文数再判断是否为质数的方式ac
 * 					  2)埃氏筛法怎么做 
 *					  3)线性筛 
**/

#include<iostream>
#include<cmath>
#include <cstring>
using namespace std;

#define maxn 100000003
int prime[maxn];//存放prime数 
bool a[maxn];//也可以是int数组 
int tot = 0;

bool hw(int n) {//判定回文，不懂请参考数字反转 
	int rn = 0;
	int num = n;
	while(n!=0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	if( rn == num )//判断是否回文 
		return true;
	return false;
}


int main() {
	int i,n,m;
	cin >> n >> m;  //读入两个数 

	for ( i = 2; i <= m; i++ ){	
		
		if( !a[i] ) {
			prime[tot++] = i;
		}
		for ( int j = 0; j < tot && i*prime[j] <= m; j++ ){
			a[i*prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
		
	}
	
	for ( i = n; i <= m; i++ ) {
		if( a[i]==0 && hw(i) ) cout << i << endl;
	}

}
/***********************************************************************
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

//bool isPrime( int n ){
//	if( n <= 1 ) return false;
//	if( n == 2 || n == 3 || n == 5 || n == 7 ) return true;
//	rep( i, 2, n/2+1 )
//		if( n % i == 0 ) return false;
//	return true;
//} 

int getWidth( int n ){	//获得n的位数 
	int i = 0;
	while( n ){
		n /= 10;
		i++;
	}
	return i;
} 

//bool isPal( int n ){
//	if( n == 11 ) return true;
//	int wei = getWidth( n );
//	if( wei == 1 ) return true;
//	else if( wei%2 == 0 ) return false;
//	else {
//		string s = to_string( n ) , r = s;
//		reverse( all(r) );
//		if( s == r ) return true;
//		return false;
//	} 
//} 

bool isPal( int n ){
	int rn=0;
	int num = n;
	while(n!=0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	if( rn == num )//判断是否回文 
		return true;
	return false;
} 

int getMax( int n ){
	int ans = 0;
	while ( n-- ){
		ans = ans * 10 + 9;
	}
	return ans;
} 

int getMin( int n ){
	int ans = 1;
	while ( --n ){
		ans = ans * 10;
	}
	return ans+1;
}

bool prime[100000001];

int main() 
{
	int n, m;
	cin >> n >> m;
	memset( prime , true , sizeof( prime ) );
	prime[1] = false;
	ret ( i , 2 , m ){
		if( prime[i] ){
			ret( j , 2 , m/i ){
				prime[j*i] = false;
			//	cout << '\t' << j*i << endl;
			}
		}
	} 
	int wei1 = getWidth( n ) , wei2 = getWidth( m ) , head , k;
	ret ( i , wei1 , wei2 ) {
		if( i == 2 && m >= 11 ){
			cout << 11 << endl;
		} 
		if( i % 2 == 0 ) continue;
		int left = getMin(i) , right = getMax(i);
		if( i == wei1 ) left = n;
		if( i == wei2 ) right = m;
		if( i == 9 ) break;
//		cout << left << ' ' << right << endl;
		ret ( j , left , right ){
			if(j==9989900) //如果到了这个数，就break  抄的 
				break;
			if( j % 2 == 0 ) j++; 
//			if( isPrime(j) ) cout << j << "prime" << endl;
//			if( isPal(j) ) cout << j << "pal" << endl;
			if( isPal( j ) && prime[j] )
				cout << j << endl;
			k = pow( 10 , i-1 );
			head = j / k;
			j++;
			if( head%2 == 0 ) j = (head+1) * pow( 10 , i-1 ); 
//			j++;//实际上是i+=2 
		} 
	} 
}


/*int main()
{
	int a, b, aa, bb, m=0, n=0;
	cin >> a >> b;
	aa = a, bb = b;
	while ( a ) {
		m++; a /= 10; 
	} 
	while ( b ) {
		n++; b /= 10;
	}
	ll value, judge[5], num[5]; //0-g……4-c  
	int i;
	vector<int> v;
	ret( i, m, n ){
		// 从外到内
		rep(k,0,5) judge[k] = 9;
		int j;
		for( j = 4; j > (i-1)/2; j-- ) judge[j] = 0;
		ret( num[4], 0, judge[4] ) 	{
			ret( num[3], 0, judge[3] ){
				ret( num[2], 0, judge[2] ){
					ret( num[1], 0, judge[1] ){
						ret( num[0], 0, judge[0] ){
							if( i % 2 ) { //奇数位 
								value = num[4]*100000000 + num[3]*10000000 + num[2] * 1000000 + num[1]*100000 + num[0]*10000 + num[1]*1000 + num[2]*100 + num[3]*10 + num[4];
								//cout << value << ' ';
							} 
							else {
								value = num[4]*1000000000 + num[3]*100000000 + num[2] * 10000000 + num[1]*1000000 + num[0]*100000 + num[0]*10000 + num[1]*1000 + num[2]*100 + num[3]*10 + num[4];
								//cout << value << '	';
							}
							while( value != 0 && value % 10 == 0 ) value /= 10;
							if( isPrime( value ) ) v.pb( value );
								//cout << value << endl;
						}
					}
				} 
			}
		}
	}
	sort( all(v) );
	v.erase(unique(v.begin(), v.end()), v.end());
    //unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 再用erase函数擦除从这个元素到最后元素的所有的元素
	rep( i, 0, v.size() ) if( v[i] >= aa && v[i] <= bb ) cout << v[i] << endl;
}
***********************************************************************/
