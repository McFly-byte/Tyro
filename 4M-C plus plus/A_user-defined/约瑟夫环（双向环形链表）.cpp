#include <iostream>		//约瑟夫环问题：n为人数，m为敏感数字。 
#include <malloc.h>

using namespace std;

typedef struct node *ptr;
struct node{
	int ID;
	ptr next;
	ptr last;
};

int main()
{
	int n, m;
	cin>>n>>m;
	ptr head;
	head = ( ptr )malloc( sizeof( node ) );
	head->last = NULL;
	head->next = NULL;
	head->ID = 1;
	
	for( int i = n; i > 1; i-- ){
		ptr piece;
		piece = ( ptr )malloc( sizeof( node ) );
		piece->ID = i;
		piece->next = head->next;	
		if( head->next != NULL ) head->next->last = piece;
		piece->last = head;
		head->next = piece;

		if( i == n ){
			piece->next = head;
			head->last = piece;
		}
	}	
	
	int count = 0;
	ptr tag = head;
	while( tag->next != tag ){
		count++;
		if( count == m ){
			count = 0;
			ptr tmp = tag;
			tag = tag->last;
			tag->next = tmp->next;
			(tmp->next)->last = tag; 	
			free( tmp );
		}
		tag = tag->next;
	}
	cout<<tag->ID<<endl;
	
	return 0;
}
