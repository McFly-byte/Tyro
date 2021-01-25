#ifndef CLOSEDSHAPE_H
#define CLOSEDSHAPE_H

#include <bits/stdc++.h>
using namespace std;

class ClosedShape{//���ͼ���� 
	public:
		virtual double getArea();//����� 
		virtual double getPerimeter();//���ܳ� 
		virtual void moveOff( int x , int y );//�ƶ�λ�� 
};

class Point{
	int X;
	int Y;
	public:
		Point();
		Point( int x , int y );
		Point & operator=( const Point & p );
		friend class ClosedShape;
		friend class Circle;
		friend class Rectangle;
		friend class Triangle;
}; 

class Circle : public ClosedShape{
		Point Center;
		int Radius;
	public:
		Circle();
		Circle( int x , int y , int r ); 
		virtual double getArea();//����� 
		virtual double getPerimeter();//���ܳ� 
		virtual void moveOff( int x , int y );//�ƶ�λ�� 
};

class Rectangle : public ClosedShape{
		Point LeftTop;
		int Height;
		int Width;
	public:	
		Rectangle();
		Rectangle( int x , int y , int h , int w );
		virtual double getArea();//����� 
		virtual double getPerimeter();//���ܳ� 
		virtual void moveOff( int x , int y );//�ƶ�λ�� 
};

class Triangle : public ClosedShape{
		Point Vertexes[3];//�������� 
		double Side[3];//�����߳� 
	public:
		Triangle();
		Triangle( int x0 , int y0 ,int x1 , int y1 , int x2 , int y2 );
		virtual double getArea();//����� 
		virtual double getPerimeter();//���ܳ� 
		virtual void moveOff( int x , int y );//�ƶ�λ�� 
}; 

#endif
