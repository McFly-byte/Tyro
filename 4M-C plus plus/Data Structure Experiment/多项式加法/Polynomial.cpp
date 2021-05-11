/**
 *    author:  McFly
 *    created: 04.2021 
 *	  describ:  多项式加法 链表实现				
**/
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define ret(i,a,b) for(register int i=(a);i<=(b);++i)
#define INF 0x3f3f3f3f 

typedef struct PolyNode * Polynomial;
struct PolyNode
{
	int Expon;			//次数 
	int Coef;			//系数 
	Polynomial Next;	//下一项 
};
typedef Polynomial poly;

Polynomial ReadPoly();	//读入一个多项式 
Polynomial AddPoly( poly a, poly b );	//实现多项式加法 
void PrintPoly( poly p ); 	//打印多项式 

int main()
{
	poly a = ReadPoly();
	cout << "A(x) = "; 
	PrintPoly( a );
	poly b = ReadPoly();
	cout << "B(x) = ";
	PrintPoly( b );
	poly s = AddPoly( a, b );
	cout << "二者之和" << endl << "C(x) = "; 
	PrintPoly( s ); 
}

Polynomial ReadPoly()
{
	cout << "输入一个多项式" << endl; 
	poly head = (poly)malloc(sizeof(struct PolyNode));
	head->Expon = INF;
	head->Coef = INF;
	head->Next = NULL;
	int coef,expon;
	poly flag;
	while( cin >> coef >> expon && (coef || expon) )
	{
		flag = head;
		while ( flag->Next && flag->Next->Expon > expon ) flag = flag->Next;
		if( !flag->Next || flag->Next->Expon != expon ) 
		{
			poly node = (poly)malloc(sizeof(struct PolyNode));
			node->Coef = coef;
			node->Expon = expon;
			node->Next = flag->Next;
			flag->Next = node; 
		} 
		else if( flag->Next->Expon == expon ) flag->Next->Coef += coef;
		flag = flag->Next;
	}
	return head->Next;	
}

Polynomial AddPoly( poly a, poly b )
{
	poly m = a, n = b, ans = (poly)malloc(sizeof(struct PolyNode));
	ans->Coef = ans->Expon = INF;	ans->Next = NULL;
	poly flag = ans;
	while( m && n )
	{
		if( m->Expon > n->Expon )
		{
			poly tmp = (poly)malloc(sizeof(struct PolyNode));
			tmp->Expon = m->Expon;
			tmp->Coef = m->Coef;
			tmp->Next = NULL;
			flag->Next = tmp;
			m = m->Next;
		}
		else if( m->Expon < n->Expon )
		{
			poly tmp = (poly)malloc(sizeof(struct PolyNode));
			tmp->Expon = n->Expon;
			tmp->Coef = n->Coef;
			tmp->Next = NULL;
			flag->Next = tmp;
			n = n->Next;
		}
		else 
		{
			poly tmp = (poly)malloc(sizeof(struct PolyNode));
			tmp->Expon = m->Expon;
			tmp->Coef = m->Coef+n->Coef;
			tmp->Next = NULL;
			flag->Next = tmp;
			n =  n->Next;
			m = m->Next;
		}
		flag = flag->Next;
	}
	while( !m && n )
	{
		poly tmp = (poly)malloc(sizeof(struct PolyNode));
		tmp->Expon = n->Expon;
		tmp->Coef = n->Coef;
		tmp->Next = NULL;
		flag->Next = tmp;
		n = n->Next;
		flag = flag->Next;
	}
	while( !n && m )
	{
		poly tmp = (poly)malloc(sizeof(struct PolyNode));
		tmp->Expon = m->Expon;
		tmp->Coef = m->Coef;
		tmp->Next = NULL;
		flag->Next = tmp;
		m = m->Next;
		flag = flag->Next;
	}
	return ans->Next;
}

void PrintPoly( poly a )//打印
{
	if( !a ) return ;
	poly p = a;
	while( p )
	{
		if( !p->Coef ) {
			p = p->Next;
			continue;
		}
  		if( a == p )
		{
			if( p->Expon == 0 ) {
				cout << p->Coef;
				continue;
			}
			if( p->Coef != 1 ) cout << p->Coef;
			cout << 'x';
			if( p->Expon != 1 ) cout << '^' << p->Expon;  
		}
		else 
		{
			if( p->Expon == 0 ) {
				if( p->Coef > 0 ) cout << '+'; 
				cout << p->Coef;
				p = p->Next;
				continue;
			}
			if( p->Coef > 0 ) cout << '+'; 
			if( p->Coef != 1 ) 	cout << p->Coef;
			cout << 'x';
			if( p->Expon != 1 ) cout << '^' << p->Expon;    
		}
		p = p->Next;
	}
	cout << endl;
}
