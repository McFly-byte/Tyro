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
#define it iterator
typedef long long ll;

const int minn = 60;
const int hour = 3600;
const int day = 86400;
const int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const ll year = 31536000;
//闰年再加一天的量 

bool isRun( int n ){
	return ( n%400 == 0 || n%4 == 0 && n%100 != 0 );
}

int main()
{
	ll t, scale, yr,mn,dy,h,m,s,n;
	cin >> t;
	while( t-- ){
		cin >> scale >>yr>>mn>>dy>>h>>m>>s;
		n = pow(2,scale-1)-1;
	//	cout << "n:" << n << endl;
		while( 1 ){
			if( n>=year+day && (isRun(yr) && mn<=2 || isRun(yr+1)&&mn>=3) ) n-=(year+day);
			else if( n >= year ) n -= year;
			else break;
			yr++;
	//		cout << yr << ' ' << n << endl; 
		}
//		cout << n << endl;
		//全转到下个月一号 
		if( n >= day*(mon[mn]-dy+1) ){
			if( mn == 2 ){
				if( isRun(yr) ) n -= day*(mon[mn]-dy+1+1);
				else n -= day*(mon[mn]-dy+1);
				mn++;
				dy = 1;
			} 
			else{
				n -= day*(mon[mn]-dy+1);
				mn++;
				dy = 1;
			}
			if( mn > 12 ) {
				mn = 1;
				yr++;
			}
		}
		
//		cout << "month" << mn << ' ' << dy << endl;
//		cout << n << endl;
		while( 1 ){
			if( mn==2&&isRun(yr)&&n>=(mon[mn]+1) *day) n -= (mon[mn++]+1)*day;
			else if( (mn!=2||!isRun(yr)) && n>=mon[mn]*day ) n -= mon[mn++]*day;
			else break;
			if( mn > 12 ) {
				mn = 1;
				yr++;
			}
		}
//		cout << n << endl;
//		cout << "month  " << mn << ' ' << dy << endl;
		while ( n >= day ) {
			n -= day;
			dy++;
			if( mn == 2 ){
				if( isRun(yr)&&dy>mon[mn]+1 ) {
					dy = 1;
					mn++;
					if( mn > 12 ) {
						mn = 1;
						yr++;
					}
//					cout << 1 << endl;
				}
				else if( !isRun(yr)&&dy>mon[mn] ){
					dy = 1;
					mn++;
					if( mn > 12 ) {
						mn = 1;
						yr++;
					}
//					cout << 2 << endl; 
				}
			}
			else{
				if( dy>mon[mn] ){
					dy = 1;
					mn++;
					if( mn > 12 ) {
						mn = 1;
						yr++;
					}
				}
			}
		}
//		cout << n << endl;
//cout << yr << ' ' << mn << ' ' << dy << ' ' << h << ' ' << m << ' ' << s << endl;
		while( n >= hour ) {
			n -= hour;
			h++;
			if( h >= 24 ) {
				h -= 24;
				dy++;
				if( dy > mon[mn] ){
					dy = 1;
					mn++;
					if( mn > 12 ) {
						mn = 1;
						yr++;
					}
				}
			}
		}
//		cout << n << endl;
		while( n >= minn ){
			n -= minn;
			m++;
			if( m >= 60 ){
				h++;
				m -= 60;
				if( h >= 24 ) {
					h -= 24;
					dy++;
					if( dy > mon[mn] ){
						dy = 1;
						mn++;
						if( mn > 12 ) {
							mn = 1;
							yr++;
						}
					}
				}
			}
		}
//		cout << n << endl;
		s += n;
		if( s >= 60 ){
			s -= 60;
			m++;
			if( m >= 60 ){
				h++;
				m -= 60;
				if( h >= 24 ) {
					h -= 24;
					dy++;
					if( dy > mon[mn] ){
						dy = 1;
						mn++;
						if( mn > 12 ) {
							mn = 1;
							yr++;
						}
					}
				}
			}
		}
		cout << yr << ' ' << mn << ' ' << dy << ' ' << h << ' ' << m << ' ' << s << endl;
	}
}

/*
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // 用 UTC，避免时区带来的问题
  	setenv("TZ", "/usr/share/zoneinfo/UTC", 1);
  	unsigned n;
 	scanf("%u", &n);
    while (n--) {
	    struct tm time;
	    unsigned width;
	    scanf("%u%d%d%d%d%d%d", &width, &time.tm_year, &time.tm_mon, &time.tm_mday, &time.tm_hour, &time.tm_min, &time.tm_sec);
	    time.tm_year -= 1900;
	    time.tm_mon--;
	    // 不考虑夏令时
	    time.tm_isdst = 0;
	    // 把时间戳加上 width 位有符号整数的最大值，就能得到最后的有效时间
	    time_t timer = mktime(&time) + ((1U << (width - 1)) - 1);
	    struct tm* end = localtime(&timer);
	    printf("%d %d %d %d %d %d\n", end->tm_year + 1900, end->tm_mon + 1, end->tm_mday, end->tm_hour, end->tm_min, end->tm_sec);
    }
  return 0;
}
*/
