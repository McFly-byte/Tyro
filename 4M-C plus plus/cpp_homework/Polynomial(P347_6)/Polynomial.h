#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <bits/stdc++.h>
using namespace std;

//typedef double ElementType;

class Polynomial{
	private:
		vector<double> Coef;//系数 
	public:
		int Top_Expon;//最大指数 (public方便访问)
		//vector的大小永远是Top_Expon+1,系数为零也写要写 
		//指数永远和下标相对应 
		
		//用double数组构造一个多项式对象 
		Polynomial( double * Array , int N );
		//复制构造函数 
		Polynomial( const Polynomial & Poly );
		//无参构造函数 
		Polynomial();
		//析构函数（好像没什么可写的9.17）
		~Polynomial();
		//打印多项式 
		void printPoly(); 
		//求多项式的值
		double getValue( double X );
		//重载下标运算符 
		const double& operator[]( int Index ) const; 
		//重载定义等
		Polynomial & operator=( const Polynomial & Poly );
		//重载定义加 
		Polynomial operator+( const Polynomial & Poly );//不可返回和的引用 临时变量消亡问题 
		//重载定义减
		Polynomial operator-( const Polynomial & Poly ); 
		//重载定义乘（多项式相乘） 
		Polynomial operator*( const Polynomial & Poly );
		//重载定义乘（数乘） 
		Polynomial operator*( double Digit );//Poly*Digit;
		friend Polynomial operator*( double Digit , const Polynomial & Poly );//Digit*Poly;
		//重载定义==
		bool operator==( const Polynomial & Poly );
		//重载定义！= 
		bool operator!=( const Polynomial & Poly );
}; 

Polynomial operator*( double Digit , const Polynomial & Poly ); 

#endif
