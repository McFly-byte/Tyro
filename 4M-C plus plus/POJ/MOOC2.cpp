#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int factor();

int term()
{
	int result = factor();
	while(true)
	{
		char op = cin.peek();
		if(op == '*'|| op == '/')
		{
			cin.get();
			int value = factor();
			if(op=='*')
			{
				result*=value;
			}
			else
			{
				result/=value;
			}
		}
		else
		{
			break;
		 } 
	 } 
	 return result;
}

int express()//�ӵ�һ�����ʽ��ʼ������������еĺ��� 
{
	int result = term();//��һ���ֵ
	bool more = true;
	while(more)
	{
		char op = cin.peek();
		if(op=='+'||op=='-')
		{
			cin.get();
			int value = term();//��һ���ֵ 
			if(op=='+')
			{
				result += value;
			}
			else
			{
				result -= value;
			}
		}
		else
		{
			more = false;
		}
	 } 
	 return result;
}

int main()
{
	cout<<express()<<endl;
	return 0;
}

int factor()
{
	int result = 0;
	char op =cin.peek();
	if(op=='(')
	{
		cin.get();
		result = express();
		cin.get();
	}
	else
	{
		while(isdigit(op))
		{
			result = 10*result + op - '0';
			cin.get();
			op = cin.peek(); 
		}
	 } 
	 return result;
}

