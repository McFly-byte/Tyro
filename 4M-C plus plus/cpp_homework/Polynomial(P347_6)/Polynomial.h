#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <bits/stdc++.h>
using namespace std;

//typedef double ElementType;

class Polynomial{
	private:
		vector<double> Coef;//ϵ�� 
	public:
		int Top_Expon;//���ָ�� (public�������)
		//vector�Ĵ�С��Զ��Top_Expon+1,ϵ��Ϊ��ҲдҪд 
		//ָ����Զ���±����Ӧ 
		
		//��double���鹹��һ������ʽ���� 
		Polynomial( double * Array , int N );
		//���ƹ��캯�� 
		Polynomial( const Polynomial & Poly );
		//�޲ι��캯�� 
		Polynomial();
		//��������������ûʲô��д��9.17��
		~Polynomial();
		//��ӡ����ʽ 
		void printPoly(); 
		//�����ʽ��ֵ
		double getValue( double X );
		//�����±������ 
		const double& operator[]( int Index ) const; 
		//���ض����
		Polynomial & operator=( const Polynomial & Poly );
		//���ض���� 
		Polynomial operator+( const Polynomial & Poly );//���ɷ��غ͵����� ��ʱ������������ 
		//���ض����
		Polynomial operator-( const Polynomial & Poly ); 
		//���ض���ˣ�����ʽ��ˣ� 
		Polynomial operator*( const Polynomial & Poly );
		//���ض���ˣ����ˣ� 
		Polynomial operator*( double Digit );//Poly*Digit;
		friend Polynomial operator*( double Digit , const Polynomial & Poly );//Digit*Poly;
		//���ض���==
		bool operator==( const Polynomial & Poly );
		//���ض��壡= 
		bool operator!=( const Polynomial & Poly );
}; 

Polynomial operator*( double Digit , const Polynomial & Poly ); 

#endif
