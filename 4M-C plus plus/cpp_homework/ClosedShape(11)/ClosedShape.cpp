#include <bits/stdc++.h>
#include "ClosedShape.h"

#define pai 3.1415926

using namespace std;

int main()
{
}

Point::Point(){
}
Point::Point( int x , int y ){
	this->X = x;	
	this->Y = y;
}
Point & Point::operator=( const Point & p ){
	this->X = p.X;
	this->Y = p.Y;
}

Circle::Circle(){
}
Circle::Circle( int x , int y , int r ){
	this->Radius = r;
	this->Center = Point(x,y);
}
double Circle::getArea(){
	return pai * this->Radius * this->Radius ;
}
double Circle::getPerimeter(){
	return 2 * this->Radius * pai;
}
void Circle::moveOff( int x , int y ){
	this->Center.X += x;
	this->Center.Y += y;
}

Rectangle::Rectangle(){
}
Rectangle::Rectangle( int x , int y , int h , int w ){
	this->LeftTop = Point( x , y );
	this->Height = h;
	this->Width = w; 
}
double Rectangle::getArea(){
	return this->Height * this->Width;
}
double Rectangle::getPerimeter(){
	return 2 * ( this->Height + this->Width );
}
void Rectangle::moveOff( int x , int y ){
	this->LeftTop.X += x;
	this->LeftTop.Y += y;
}

Triangle::Triangle(){
}
Triangle::Triangle( int x0 , int y0 ,int x1 , int y1 , int x2 , int y2 ){
	this->Vertexes[0] = Point( x0 , y0 );
	this->Vertexes[1] = Point( x1 , y1 );
	this->Vertexes[2] = Point( x2 , y2 );	
	this->Side[0] = sqrt( pow( y0-y1 , 2 ) + pow( x0-x1 , 2 ) ); 
	this->Side[1] = sqrt( pow( y0-y2 , 2 ) + pow( x0-x2 , 2 ) ); 
	this->Side[2] = sqrt( pow( y2-y1 , 2 ) + pow( x2-x1 , 2 ) ); 
}
double Triangle::getArea(){
	int p = ( this->Side[0] + this->Side[1] + this->Side[2] ) / 2;
	return sqrt( p * ( p - Side[0] ) * ( p - Side[1] ) * ( p - Side[2] ) );
}
double Triangle::getPerimeter(){
	return this->Side[0]+this->Side[1]+this->Side[2];
}
void Triangle::moveOff( int x , int y ){
	for( int i = 0 ; i < 3 ; i++ ){
		this->Vertexes[i].X += x;
		this->Vertexes[i].Y += y;	
	}
}
