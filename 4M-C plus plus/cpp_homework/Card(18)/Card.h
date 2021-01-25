#ifndef CARD_H
#define CARD_H

#include <bits/stdc++.h>
using namespace std;

enum Suit{ Heart = 1 , Diamond , Club , Spade , BigJoker , LittleJoker };//ö�����ֻ�ɫ����С�� 

class Card{
	private:
		Suit CardSuit;//��ɫ 
		int CardPoint;//������int��������ֻ�����ʱת�� 
	public:
		Card();
		Card( const Card & c );//���ƹ��� 
		Card( Suit cardsuit , int cardpoint = 0 );
		~Card();
		void printCard();//��ӡ 
		friend class Deck;//������Ԫ�� 	
};

class Deck{
	private:
		Card card[54];//һ���� 
	public:
		Deck();
		void printDeck();//��ӡ������ 
		void swap( Card & c1 , Card & c2 );
		void shuffle();	//ϴ�� 
}; 

#endif
