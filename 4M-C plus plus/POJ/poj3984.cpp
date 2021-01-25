#include <iostream>
using namespace std;

struct queue {
	int x, y;
	int last_location;
}; 

queue Q[26];//下标从1开始 
queue ans[18];
bool maze[7][7];
bool isRan[7][7] = {0}; 
int it = 1;

bool push( int i );

int main()
{
	for( int i = 1 ; i <= 5 ; i++ )
		for( int j = 1 ; j <= 5 ; j++ ){
			cin >> maze[i][j];
			if( maze[i][j] == 0 )
				isRan[i][j] = false;
			else 
				isRan[i][j] = true;
		}
			
	Q[1].x = 1;
	Q[1].y = 1;
	Q[1].last_location = -1;
	int i = 1;
	while( Q[i].x != 5 || Q[i].y != 5 ){
		if( push( i ) ) break;
		i++;
	}
	i = it;
	int j = 1;
	while( i > 0 ){
		ans[j].x = Q[i].x;
		ans[j].y = Q[i].y;
		j++;
		i = Q[i].last_location;
	} 
	for( i = j-1 ; i > 0 ; i-- ){
		cout << '(' << ans[i].x-1 << ", " << ans[i].y-1 << ')' << endl;
	}
}

bool push( int i )
{
	int x = Q[i].x , y = Q[i].y;
	if( x == 5 && y == 5 ) return true;
	if( x < 1 || y < 1 || x > 5 || y > 5 )	return false;
	if( x >= 2 && !isRan[x-1][y] ){
		Q[++it].x = x-1;
		Q[it].y = y;
		Q[it].last_location = i;
		isRan[x-1][y] = true;
	}
	if( y >= 2 && !isRan[x][y-1] ){
		Q[++it].x = x;
		Q[it].y = y-1;
		Q[it].last_location = i;
		isRan[x][y-1] = true;
	}
	if( x <= 4 && !isRan[x+1][y] ){
		Q[++it].x = x+1;
		Q[it].y = y;
		Q[it].last_location = i;
		isRan[x+1][y] = true;
	}
	if( y <= 4 && !isRan[x][y+1] ){
		Q[++it].x = x;
		Q[it].y = y+1;
		Q[it].last_location = i;
		isRan[x][y+1] = true;
	}
	return false;
}







