#include <iostream>
#include <malloc.h> 

using namespace std;

/*SAMPLE:
Input:	4 3 4 -5 2  6 1  -2 0
		3 5 20  -7 4  3 1
Output: 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
		5 20 -4 4 -5 2 9 1 -2 0*/

typedef int Type;

typedef struct PolyNode * Polynomial;
struct PolyNode {
	Type Coef , Expon ;//ϵ����ָ�� 
	Polynomial Next ; 
};


Polynomial ReadPoly( );//check
void attach( int coef , int expon , Polynomial *pRear );//check
Polynomial addPoly( Polynomial P1 , Polynomial P2 );//check
Polynomial multPoly( Polynomial P1 , Polynomial P2 );//check
void PrintPoly( Polynomial P );//check


int main()
{
	Polynomial P1 , P2 , Pa , Pm;
	P1 = ReadPoly(); 
	P2 = ReadPoly();
	Pm = multPoly( P1 , P2 );	PrintPoly( Pm );
	cout<<endl;
	Pa = addPoly( P1 , P2 );	PrintPoly( Pa );
}

void PrintPoly( Polynomial P )
{
	Polynomial flag = P;
	if( flag == NULL ){
		cout<<"0 0";
		return ;
	}//�����ʽ���"0 0" 
	for( ; flag ; flag = flag->Next )
	{
		if( flag->Next == NULL )
			cout<<flag->Coef<<' '<<flag->Expon;
		else 
			cout<<flag->Coef<<' '<<flag->Expon<<' ';
	}//ĩβ�ո���� 
}

Polynomial ReadPoly( )//����һ������ʽ 
{
	Polynomial head , rear , tmp;
	head = ( Polynomial )malloc( sizeof( PolyNode ) );
	head->Next = NULL;
	rear = head;
	
	int N , coef , expon;
	cin>>N;//����ʽ���� 
	while( N-- ){
		cin>>coef>>expon;
		attach( coef , expon , &rear );
	}
	
	tmp = head;
	head = head->Next;
	free( tmp );
	return head; 
}

void attach( int coef , int expon , Polynomial *pRear )//�β�ָ���ָ�� 
{
	Polynomial poly;
	poly = ( Polynomial )malloc( sizeof( PolyNode ) );
	poly->Coef = coef , poly->Expon = expon;
	poly->Next = NULL;
	( *pRear )->Next = poly;
	( *pRear ) = poly;
}

Polynomial addPoly( Polynomial P1 , Polynomial P2 )
{
	Polynomial i = P1 , j = P2 , Ph , Pr , Ptmp;
	Ph = ( Polynomial )malloc( sizeof( PolyNode ) );
	Ph->Next = NULL;
	Pr = Ph;
	while( i && j ){
		if( i->Expon > j->Expon ){
			attach( i->Coef , i->Expon , &Pr );
			i = i->Next;
		}
		else if( j->Expon > i->Expon ){
			attach( j->Coef , j->Expon , &Pr );
			j = j->Next;
		}
		else{
			if( i->Coef + j->Coef != 0 ){
				attach( i->Coef+j->Coef , i->Expon , &Pr );
			}
			i = i->Next , j = j->Next;
		}
	}
	while( i ){
		attach( i->Coef , i->Expon , &Pr );
		i = i->Next;
	}
	while( j ){
		attach( j->Coef , j->Expon , &Pr );
		j = j->Next;
	}
	
	Ptmp = Ph;
	Ph = Ph->Next;
	free( Ptmp );
	return Ph;
}

Polynomial multPoly( Polynomial P1 , Polynomial P2 )
{
	Polynomial i , j , P ;
	P = NULL;
	for( i = P1 ; i ; i = i->Next ){
		Polynomial Ph , Pr , Ptmp;
		Ph = ( Polynomial )malloc( sizeof( PolyNode ) );
		Ph->Next = NULL;
		Pr = Ph;
		for( j = P2 ; j ; j = j->Next ){
			attach( j->Coef*i->Coef , j->Expon+i->Expon , &Pr );
		}
		Ptmp = Ph;
		Ph = Ph->Next;		
		free( Ptmp );
		P = addPoly( P , Ph );//������ 
	}
	return P; 
}
