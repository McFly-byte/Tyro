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

Card::Card()//缺省构造 
{
}

Card::Card( const Card & c )//复制构造函数 
{
	this->CardPoint = c.CardPoint;
	this->CardSuit = c.CardSuit;
}

void Card::printCard()//打印一张牌 
{	//输出图案太难了看不懂，好像要转utf8什么的 
	if( this->CardSuit == BigJoker ){
		cout << "大王" << endl;
	}
	else if( this->CardSuit == LittleJoker ){
		cout << "小王" << endl;
	}
	else{
		if( this->CardSuit == Heart ) cout << "红桃 "; 
		else if( this->CardSuit == Diamond ) cout << "方片 "; 
		else if( this->CardSuit == Club ) cout << "黑桃 "; 
		else if( this->CardSuit == Spade ) cout << "梅花 "; 
		
		if( this->CardPoint == 1 ) cout << 'A' << endl;
		else if( this->CardPoint == 11 ) cout << 'J' << endl;
		else if( this->CardPoint == 12 ) cout << 'Q' << endl;
		else if( this->CardPoint == 13 ) cout << 'K' << endl; 
		else cout << this->CardPoint << endl;
	}
}

Deck::Deck()//构造一副牌，整齐的 
{
	for( int i = 0 ; i < 52 ; i++ ){
		this->card[i].CardSuit = Suit(i/13+1);
		this->card[i].CardPoint = i%13+1;
	}
	this->card[52].CardSuit = LittleJoker;
	this->card[53].CardSuit = BigJoker;
}

void Deck::printDeck()//打印 
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

void Deck::shuffle()//把牌洗乱 
{
	srand((int)time(NULL));//设种子
	for(int i=0;i<100;i++)
	{
		int random_digit_1 = rand()%54+0;//产生0-53之间的数
		int random_digit_2 = rand()%54+0;
		swap( this->card[random_digit_1] , this->card[random_digit_2] );
	}
}

int main()
{
	Deck A;
	A.printDeck();
	cout << "洗牌：" << endl; 
	A.shuffle();
	A.printDeck();
} 
