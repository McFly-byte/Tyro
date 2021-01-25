#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

#define eps 10e-6
#define _rep(k,l,r) for( int k = l; k <= r; k++ )
#define _for(k,l,r) for( int k = l; k < r; k++ )

struct node{
	string filename;
	int build_time;
	friend bool operator < ( node a , node b ){
		return a.build_time < b.build_time;
	}
}tmp;

int ID = 1;
vector<node> file;

int Find( string filename );

int main()
{
	int T;
	cin >> T;
	string cmd, str;
	tmp.build_time = 0;
	tmp.filename = "ERROR";
	file.push_back( tmp );
	while ( T-- ){
		cin >> cmd;
		if( cmd[1] == 'o' ){  //touch
			cin >> str;
			if( Find( str ) == 0 ){
				tmp.filename = str;
				tmp.build_time = ID++;
				file.push_back( tmp );
				//cout << "Get" << endl;
			}		
		}
		else if( cmd[1] == 'm' ){ // rm
			cin >> str;
			int i = Find( str );
			if( i != 0 ){
				vector<node>::iterator it = file.begin();
				for( int j = 0;  j < i ; j++ ) it++;
				file.erase( it ); 
			}
		}
		else if( cmd[1] == 's' ){ // ls
			sort( file.begin(), file.end() ); 
			vector<node>::iterator i = file.begin(); i++;
			for( ; i < file.end(); i++ )
				cout << (*i).filename << endl;
		}
		else if( cmd[1] == 'e' ){ //rename
			string name;
			cin >> str >> name;
			int i = Find( str );
			if( i != 0 ){
				file[i].filename = name;
			}
		}
	}
}

int Find( string name )
{
	vector<node>::iterator it = file.begin();
	int i = 0;
	for( ; it < file.end(); it++ ){
		if( (*it).filename == name )
			return i;
		i++;
	}
	return 0;
}
