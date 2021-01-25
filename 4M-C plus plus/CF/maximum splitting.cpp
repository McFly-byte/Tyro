/**
 *    author:  me
 *    created: 23.12.2020  
 *	  describ: 有些质数也可被分解    
**/

#include <iostream>
using namespace std;
int main()
{
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 ){
			cout << -1 << endl;
			continue;
		} 
		int ans = n / 4, rmd = n % 4;
		if ( rmd == 0 || rmd == 2)
			cout << ans << endl;
		else
			cout << ans - 1 << endl;
	}
}
