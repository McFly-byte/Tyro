#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t , n , maxn;
	bool flag;
	cin >> t;
	
	while ( t-- ){
		cin >> n;
		while ( n % 2  == 0 ) n /= 2;
		if( n == 1 ) cout << "No" << endl;
		else cout << "Yes" << endl;  
//		maxn = n/2+1;
//		flag = false;
//		if( n % 2 == 1 ) flag = true;
//		else{
//			for ( long long i = 3; i <= maxn; i+=2 ){
//				if( n % i == 0 ){
//					cout << n << ' ' << i << endl;
//					flag = true;
//					break;
//				}
//			}
//		}
//		if( flag ) cout << "Yes" << endl;
//		else cout << "No" << endl; 
	}
}

/* Ìâ½â 
#include<cstdio>
using namespace std;
int T;
long long N;
main(){
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		while(N%2==0)N/=2;
		puts(N==1?"NO":"YES");
	}
}
*/
