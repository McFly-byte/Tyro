#include <bits/stdc++.h>
#include "Polynomial.h"

Polynomial::Polynomial( double * Array , int N )//��double���鹹��һ������ʽ���� 
{
	this->Top_Expon = N;
	for( int i = 0 ; i <= N ; i++ ){
		this->Coef.push_back( Array[i] );
	}//	cout << "Polynomial constructed." << endl;
}
Polynomial::Polynomial( const Polynomial & P )//���ƹ��캯�� 
{
	for( int i = 0 ; i <= P.Top_Expon; i++ ){
		this->Coef.push_back( P.Coef[i] ); 
	}
	this->Top_Expon = P.Top_Expon;	
 } 
Polynomial::Polynomial() //�޲ι��캯�� 
{
	this->Top_Expon = 0;
}
Polynomial::~Polynomial()//��������������ûʲô��д��9.17��
{
//	cout << "Polynomial destructed." << endl;
} 

void Polynomial::printPoly()//��ӡ (10.7����޸�)
{
	for( int i = this->Top_Expon ; i >= 0 ; i-- ){
		if( this->Coef[i] > 0 && this->Coef[i] != 1 ){
			if( i == 0 ){
				if( this->Top_Expon == 0 )
					cout << this->Coef[i];
				else 
					cout << '+' << this->Coef[i] ;
			}
			else if( i == 1 ){
				if( this->Top_Expon == 1 )
					cout << this->Coef[i] << 'X';
				else 
					cout << '+' << this->Coef[i] << 'X' ;
			}		
			else if( i == this->Top_Expon )
				cout << this->Coef[i] << "X^" << i;
			else 
				cout << '+' << this->Coef[i] << "X^" << i ; 
		}
		else if( this->Coef[i] == 1 ){
			if( i == 0 ){
				if( this->Top_Expon == 0 )
					cout << 1;
				else 
					cout << '+' << 1 ;
			}
			else if( i == 1 ){
				if( this->Top_Expon == 1 )
					cout << "X";
				else 
					cout << "+X" ;
			}	
			else if( i == this->Top_Expon )
				cout << "X^" << i;
			else 
				cout << "+X^" << i ; 
		}
		else if( this->Coef[i] == -1 ){
			if( i == 0 )
				cout << this->Coef[i];
			else if( i == 1 )
				cout << "-X" ;
			else if( i == this->Top_Expon )
				cout << "-X^" << i;
			else 
				cout << "-X^" << i ; 
		}
		else if( this->Coef[i] < 0 ){
			if( i == 0 )
				cout << this->Coef[i];
			else if( i == 1 )
				cout << this->Coef[i] << 'X' ;
			else 
				cout << this->Coef[i] << "X^" << i ; 
		}
		else
			continue;
	}
	cout << endl;
}

double Polynomial::getValue( double x ) //���ض���ʽ��ֵ 
{
	int i = this->Top_Expon;
	double Value = this->Coef[i--];
	for( i ; i >= 0 ; i-- ){
		Value = Value * x + this->Coef[i];
	}
	while( !this->Coef[this->Top_Expon] ) this->Top_Expon--;
	return Value;
}

const double & Polynomial::operator[]( int index ) const//�����±������
{
	return this->Coef[index];
} 
Polynomial& Polynomial::operator=( const Polynomial & Poly )//���ظ�ֵ 
{
	//vector<double>().swap(this->Coef);
	this->Coef.clear();
//	cout << this->Coef.size()<<endl;
	this->Top_Expon = Poly.Top_Expon;
	for( int i = 0 ; i <= Poly.Top_Expon ; i++ )
		this->Coef.push_back( Poly.Coef[i] );
//	cout << this->Coef.size()<<endl;
	return *this;
}
Polynomial Polynomial::operator+( const Polynomial & Poly )//���ؼ� 
//���ɷ��غ͵����� ��ʱ������������ 
{
	Polynomial sum;
	int min_expon = min( Top_Expon , Poly.Top_Expon ),
		max_expon = max( Top_Expon , Poly.Top_Expon );
	sum.Top_Expon = max_expon;
	int i;
	//system("pause");
	for( i = 0 ; i <= min_expon ; i++ )
		sum.Coef.push_back( this->Coef[i]+Poly.Coef[i] );
	//system("pause");
	for( i ; i <= max_expon ; i++ ){
		if( this->Top_Expon == max_expon )
			sum.Coef.push_back( this->Coef[i] );
		else
			sum.Coef.push_back( Poly.Coef[i] );
	}
//	sum.printPoly();
	//system("pause");
	return sum;
} 
Polynomial Polynomial::operator-( const Polynomial & Poly )//���ؼ�
{
	Polynomial minus;
	int min_expon = min( Top_Expon , Poly.Top_Expon ),
		max_expon = max( Top_Expon , Poly.Top_Expon );
	minus.Top_Expon = max_expon; 
	int i;
	for( i = 0 ; i <= min_expon ; i++ )
		minus.Coef.push_back( this->Coef[i] - Poly.Coef[i] ); 
	for( i ; i <= max_expon ; i++ ){
		if( this->Top_Expon == max_expon )
			minus.Coef.push_back( this->Coef[i] );
		else 
			minus.Coef.push_back( 0-Poly[i] );
	}
	i--;
	for( i ; minus[i] == 0 && i >= 0; i-- ){
		minus.Coef.pop_back();
		minus.Top_Expon--;	
	}
	return minus;
}
Polynomial Polynomial::operator*( const Polynomial & Poly )//���س� 
{
	int N = this->Top_Expon+1 , M = Poly.Top_Expon+1 , L = M + N - 1; 
	double * a = new double[N];
	double * b = new double[M]; 
	double * m = new double[L];

	for( int i = 0 ; i < N ; i++ ) a[i] = this->Coef[i];
	for( int j = 0 ; j < M ; j++ ) b[j] = Poly[j];
	for( int k = 0 ; k < L ; k++ ) m[k] = 0; 
	for( int i = 0 ; i < N ; i++ ){
		for( int j = 0 ; j < M ; j++ ){
			m[i+j] += ( a[i] * b[j] );
		}
	}
	Polynomial mult;
	for( int k = 0 ; k < L ; k++ )
		mult.Coef.push_back( m[k] );
	mult.Top_Expon = L - 1;

	delete []m;
	delete []b;	
	delete []a;
	
	mult.printPoly();
	return mult;
}
Polynomial Polynomial::operator*( double Digit )//���س��� 
{
	Polynomial multDigit;
	multDigit.Top_Expon = this->Top_Expon;
	if( Digit ){
		for( int i = 0 ; i <= this->Top_Expon ; i++ )
			multDigit.Coef.push_back( this->Coef[i] * Digit );
	}
	else {
		multDigit.Coef.push_back(0);
		multDigit.Top_Expon = 0; 
	} 
	return multDigit;	
}
bool Polynomial::operator==( const Polynomial & Poly )//���ض���==
{
	if( this->Top_Expon != Poly.Top_Expon )	return false;
	for( int i = 0 ; i <= this->Top_Expon ; i++ ){
		if( this->Coef[i] != Poly[i] ) return false;
	}
	return true;
} 
bool Polynomial::operator!=( const Polynomial & Poly )//���ض��壡= 
{
	if( *this == Poly ) return false;
	return true;
} 

Polynomial operator*( double Digit , const Polynomial & Poly )//�������� 
{
	Polynomial multDigit;
	multDigit.Top_Expon = Poly.Top_Expon;
	if( Digit != 0 )
		for( int i = 0 ; i <= Poly.Top_Expon ; i++ )
			multDigit.Coef.push_back( Poly.Coef[i] * Digit );
	else {
		multDigit.Coef.push_back(0);
		multDigit.Top_Expon = 0; 
	}
	return multDigit;
}


//������ 
int main()
{
	int N , x ;
	
	cout << "һԪ����ʽ����ߴ���Ϊ��";
	cin >> N;	
	double * d = new double[N+1];
	cout << "����ʽ������ϵ������Ϊ���Ӵ�С����"; 
	for( int i = N ; i >= 0 ; i-- )	cin >> d[i];
	Polynomial P1( d , N );
	
	cout << "һԪ����ʽ����ߴ���Ϊ��";
	cin >> N;
	double * c = new double[N+1];
	cout << "����ʽ������ϵ������Ϊ���Ӵ�С����"; 
	for( int i = N ; i >= 0 ; i-- )	cin >> c[i];  
	Polynomial P2( c , N );

//Test	
	cout << "\n���ԣ�\n";
	Polynomial tmp1(P1) , tmp2(P2) , tmp;
	cout << "����һ�ζ���ʽ�ֱ�Ϊ��\n";
	tmp1.printPoly();
	tmp2.printPoly();
	cout << "������ʽ�Ƿ���ȣ�";
	if( tmp1 == tmp2 )	cout << "��" << endl;
	else cout << "��" << endl; 
	
	cout << "\n�����x��ֵΪ��"; 
	cin >> x;
	cout << "��������ʽ��ֵ�ֱ�Ϊ��" << tmp1.getValue(x)
	     << " , " << tmp2.getValue(x) << endl; 
	tmp = ( P1 + P2 );
	cout << "\n��ӡ��������ʽ�ĺͣ�"; 
	tmp.printPoly();
	cout << "���У�" ; 
	for( int i = 0 ; i <= tmp.Top_Expon ; i++ ){
		cout << "tmp[" << i << "]=" << tmp[i] << ' ' ;
	}
	cout << endl; 
	
	tmp = ( P1 - P2 );
	cout << "\n��ӡ��������ʽ�Ĳ"; 
	tmp.printPoly();
	cout << "���У�" ; 
	for( int i = 0 ; i <= tmp.Top_Expon ; i++ ){
		cout << "tmp[" << i << "]=" << tmp[i] << ' ' ;
	}
	cout << endl;
	
	tmp = ( P1 * P2 );
	cout << "\n��ӡ��������ʽ�ĳ˻���"; 
	tmp.printPoly();
	cout << "���У�" ; 
	for( int i = 0 ; i <= tmp.Top_Expon ; i++ ){
		cout << "tmp[" << i << "]=" << tmp[i] << ' ' ;
	}
	cout << endl;
	
	cout << "\n����һ������ʹ��������ʽ�ֱ�����������";
	int digit;
	cin >> digit;		
	tmp = P1*digit;	
	tmp.printPoly();
	tmp = digit*P2;	
	tmp.printPoly(); 
	
	delete []c;
	delete []d;
}  
//
//�̽���һ������ʽ��Polynomial��ʹһ��һԪ����ʽ��Ϊһ������
//��1.�����ʵ��Ĺ��캯������һ��double�����һ������n����һ������ʽ
//��2.�����ʵ��Ŀ������캯��/������ֵ����/�������� 
//��3.����һ����Ա����double getValue(double x),���ض���ʽ��ֵ 
//��4.���ض���Ӽ��˷�
//��5.���ض���==��!= 
