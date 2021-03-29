/**
 *    author:  McFly
 *    created: 03.2021 
 *	  describ:  				
**/
#include <bits/stdc++.h>
using namespace std; 

typedef int ElementType;
typedef int Position; 

#define MAXN 10000
ElementType Set[MAXN]; //�洢ÿ��Ԫ�ظ���λ�ã����д��֧���� 

void Union( ElementType r1, ElementType r2 ); // Ĭ��r1�ӵ�r2�£�����rank��һ 
Position Find( ElementType e ); //��λ�� 

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0);
	
}

void Union( ElementType r1, ElementType r2 )
{
	ElementType rank1 = 0-Set[r1], rank2 = 0-Set[r2];
	if( rank1 == rank2 ){
		Set[r1] = r2;
		Set[r2]--;
	} 
	else if( rank1 < rank2 ){
		Set[r1] = Set[r2]-1;
		Set[r2] = r1;
	}
	else if( rank1 > rank2 ){
		Set[r2] = Set[r1]-1;
		Set[r1] = r2;
	}
}

Position Find( ElementType e )
{
	Position root;
	bool found = false;
	for( int i = 0; i < MAXN; i++ )
		if( Set[i] == e ){
			found = true;
			root = i;
			break;
		}
	while( Set[root] > 0 ) root = Set[root];
	return root;	
}
