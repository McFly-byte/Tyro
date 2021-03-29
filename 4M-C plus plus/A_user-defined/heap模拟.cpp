/**
 *    author:  McFly
 *    created: 03.2021 
 *	  describ:     
**/
#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)

typedef long long ll;

#define ERROR -1
#define MAXN 100001

int Heap[MAXN] , tot;

void Create();
bool isFull();
bool isEmpty();
void Insert( int x );
int  Top();
void Pop(); 

int main(){
	int t, k, d;
	cin >> t;
	while ( t-- ){
		cin >> k;
		if( k == 1 ){
			cin >> d;
			Insert(d);
		}
		else if( k == 2 ){
			cout << Top() << endl;
		}
		else{
			Pop();
		}
	}
}

void Create()
{
	tot = 0;
	Heap[0] = -1;
}

bool isFull(){
	return (tot >= MAXN);
}

bool isEmpty(){
	return (tot == 0);
}

void Insert( int x ){
	if( isFull() ) return ;
	tot++;
	int i;
	for ( i = tot; Heap[i/2] > x; i /= 2 ) Heap[i] = Heap[i/2];
	Heap[i] = x;
}

int Top()
{
	if( !isEmpty() ) return Heap[1];
	return ERROR;
}

void Pop(){
	if( isEmpty() ) return ;
	int l=1, r=1, i=1,j;
	Heap[1] = Heap[tot--];
	for ( i; i*2<=tot; i = j ){
		j = i*2;
		if( j+1 <= tot && Heap[j+1] < Heap[j] ) j++;
		if( Heap[j] < Heap[i] ) swap(Heap[i],Heap[j]);
	}
}

