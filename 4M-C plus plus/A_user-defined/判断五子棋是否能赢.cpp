#include <bits/stdc++.h>
using namespace std;

char a[26][26];//BOARD

void toWin( bool flag );
int canWin( int i , int j , bool flag );

int main()
{
	int black_num = 0, white_num = 0;
	for( int i = 1 ; i < 26 ; i++ )
		for( int j = 1 ; j < 26 ; j ++ ){
			cin >> a[i][j];
			if( a[i][j] == 'x' ) black_num++;
			else if( a[i][j] == 'o' ) white_num++;
			else continue;
		}
	if( black_num == white_num ) toWin( 0 );
	else toWin( 1 );	
}

int canWin( int i , int j , bool flag ){
	char ch;
	if( flag ) ch = 'o';
	else ch = 'x' ; 
	if( i <= 21 && a[i][j] == ch && a[i+1][j] == ch && a[i+2][j] == ch && a[i+3][j] == ch )
		return 1;
	if( j <= 21 && a[i][j] == ch && a[i][j+1] == ch && a[i][j+2] == ch && a[i][j+3] == ch )
		return 2;
	if( i <= 21 && j <= 21 && a[i][j] == ch && a[i+1][j+1] == ch && a[i+2][j+2] == ch && a[i+3][j+3] == ch)
		return 3;
	if( i <= 21 && j >= 5 &&  a[i][j] == ch && a[i+1][j-1] == ch && a[i+2][j-2] == ch && a[i+3][j-3] == ch)
		return 4;
	return 0;
}

void toWin( bool flag )
{
	bool motto = true;
	int tag;
	char ch;
	if( flag ) ch = 'o';
	else ch = 'x';
	
	for( int i = 1 ; i < 26 ; i++ ){
		for( int j = 1 ; j < 26 ; j++ ){
			if( a[i][j] == ch && canWin( i , j , flag ) ){
				motto = false;
				tag = canWin( i , j , flag );
				if( tag == 1 ){
					if( i < 21 )
						cout << a[i][j] << ' ' << a[i+4][j] << endl;
					else 
						cout << a[i][j] << endl;
				}
				else if( tag == 2 ){
					if( j < 21 )
						cout << a[i][j] << ' ' << a[i][j+4] << endl;
					else 
						cout << a[i][j] << endl;
				}
				else if( tag == 3 ){
					if( j < 21 && i < 21 )
						cout << a[i][j] << ' ' << a[i+4][j+4] << endl;
					else 
						cout << a[i][j] << endl;
				}
				else if( tag == 4 ){
					if( j > 5 && i < 21 )
						cout << a[i][j] << ' ' << a[i-4][j-4] << endl;
					else 
						cout << a[i][j] << endl;
				}
			}
		}
	}
	if( motto ) cout << "tie" << endl;
}
