#include <iostream>		 //中缀表达式(含括号)计算 
#include <cstring>		 
#include <cstdlib>	   //输入括号时要注意中英文输入法中括号的不同
					  //中文括号过不了（）()
using namespace std;

#define ElementType double 

ElementType factor_value();
ElementType term_value();
ElementType expression_value();

int main()
{
	
	cout<<expression_value()<<endl;
	
	return 0;
}

ElementType factor_value()
{
	ElementType result = 0;
	char look = cin.peek();
	if( look == '(' ){
		cin.get();
		result = expression_value();
		cin.get();
	}
	else{
		while( isdigit(look) ){
			result = result * 10 + look - '0';
			cin.get();
			look = cin.peek();
		}
	}							//	cout<<"factor "<<result<<endl;
	return result;	
}

ElementType term_value()
{
	ElementType result = factor_value();
	while( 1 ){
		char look = cin.peek();
		if( look == '*' || look == '/' )
		{
			cin.get();
			ElementType value = factor_value();
			if( look == '*' )	result *= value;
			else	result /= value;
		}
		else
			break;
	}										//cout<<"term "<<result<<endl;
	return result;
}

ElementType expression_value()
{
	ElementType result = term_value();
	while( 1 ){
		char look = cin.peek();
		if( look == '+' || look == '-' ){
			cin.get();
			ElementType value = term_value();
			if( look == '+' )	result += value;
			else	result -= value; 
		}
		else
			break;
	}							//	cout<<"expression "<<result<<endl;
	return result;
}
