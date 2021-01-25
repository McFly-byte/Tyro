#include "Card.h"
#include <bits/stdc++.h>

using namespace std;

Card::Card( Suit cardsuit , int cardpoint )
{
	this->CardSuit = cardsuit;
	this->CardPoint = cardpoint;
}

Card::~Card() 
{	
}

Card::Card()//ȱʡ���� 
{
}

Card::Card( const Card & c )//���ƹ��캯�� 
{
	this->CardPoint = c.CardPoint;
	this->CardSuit = c.CardSuit;
}

void Card::printCard()//��ӡһ���� 
{	//���ͼ��̫���˿�����������Ҫתutf8ʲô�� 
	if( this->CardSuit == BigJoker ){
		cout << "����" << endl;
	}
	else if( this->CardSuit == LittleJoker ){
		cout << "С��" << endl;
	}
	else{
		if( this->CardSuit == Heart ) cout << "���� "; 
		else if( this->CardSuit == Diamond ) cout << "��Ƭ "; 
		else if( this->CardSuit == Club ) cout << "���� "; 
		else if( this->CardSuit == Spade ) cout << "÷�� "; 
		
		if( this->CardPoint == 1 ) cout << 'A' << endl;
		else if( this->CardPoint == 11 ) cout << 'J' << endl;
		else if( this->CardPoint == 12 ) cout << 'Q' << endl;
		else if( this->CardPoint == 13 ) cout << 'K' << endl; 
		else cout << this->CardPoint << endl;
	}
}

Deck::Deck()//����һ���ƣ������ 
{
	for( int i = 0 ; i < 52 ; i++ ){
		this->card[i].CardSuit = Suit(i/13+1);
		this->card[i].CardPoint = i%13+1;
	}
	this->card[52].CardSuit = LittleJoker;
	this->card[53].CardSuit = BigJoker;
}

void Deck::printDeck()//��ӡ 
{
	for( int i = 0 ; i < 54 ; i++ )
		this->card[i].printCard();
}

void Deck::swap( Card & c1 , Card & c2 )
{
	Card tmp(c1);
	c1.CardSuit = c2.CardSuit;
	c1.CardPoint = c2.CardPoint;
	c2.CardSuit = tmp.CardSuit;
	c2.CardPoint = tmp.CardPoint;
}

void Deck::shuffle()//����ϴ�� 
{
	srand((int)time(NULL));//������
	for(int i=0;i<100;i++)
	{
		int random_digit_1 = rand()%54+0;//����0-53֮�����
		int random_digit_2 = rand()%54+0;
		swap( this->card[random_digit_1] , this->card[random_digit_2] );
	}
}

int main()
{
	Deck A;
	A.printDeck();
	cout << "ϴ�ƣ�" << endl; 
	A.shuffle();
	A.printDeck();
} 
