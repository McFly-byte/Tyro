#ifndef CARD_H
#define CARD_H

#include <bits/stdc++.h>
using namespace std;

enum Suit{ Heart = 1 , Diamond , Club , Spade , BigJoker , LittleJoker };//枚举四种花色及大小王 

class Card{
	private:
		Suit CardSuit;//花色 
		int CardPoint;//点数，int便于排序，只在输出时转换 
	public:
		Card();
		Card( const Card & c );//复制构造 
		Card( Suit cardsuit , int cardpoint = 0 );
		~Card();
		void printCard();//打印 
		friend class Deck;//声明友元类 	
};

class Deck{
	private:
		Card card[54];//一副牌 
	public:
		Deck();
		void printDeck();//打印整副牌 
		void swap( Card & c1 , Card & c2 );
		void shuffle();	//洗牌 
}; 

#endif
