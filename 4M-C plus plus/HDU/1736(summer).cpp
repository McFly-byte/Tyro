#include <bits/stdc++.h>//�����ַ�һ��ռ���ֽ� 
using namespace std;	//����"����"ҪС�� 
						//�������ŵ�ascii��һλΪ��ֵ���ڶ�λ������-80������-79 
						//����ʱ�пո�
						//ͬ���Ƕ������� 
int main()
{
	string str;
	while( getline(cin,str) ){
	
	int len = str.length();
	bool flag = 1;
	for( int i = 0 ; i < len ; i++ ){
	
		if( str[i] == ',' ) cout << "��";
		else if( str[i] == '.' ) cout << "��";
		else if( str[i] == '?' ) cout << "��";
		else if( str[i] == '!' ) cout << "��"; 
		else if( str[i] == '"' ){
			if( flag ){
				 cout << "��";
				 flag = 0;
			}
			else {
				cout << "��";
				flag = 1; 
			}
		}
		else if( str[i] == '<' && str[i+1] == '<' ){
			cout << "��";
			i++; 
		}
		else if( str[i] == '>' && str[i+1] == '>' ){
			cout << "��";
			i++; 
		} 
		else cout << str[i];
		if( str[i] < 0 && str[i+1] == -80 ) flag = 0;
		if( str[i] < 0 && str[i+1] == -79 ) flag = 1;
	}
	cout << endl;
	}
 } 
