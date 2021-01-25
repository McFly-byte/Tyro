#include <bits/stdc++.h>
using namespace std;

struct Node{
	char msg[1005];
	int parameter , priority , right;//���������ȼ�ֵ��Ȩֵ
									//���������ȼ�ֵ���ʱ���ж��Ⱥ�
	bool operator<(const Node &A) const//��������أ�����const���ɻ�ȱ���ᱨ�� 
	{
		if( priority == A.priority )	return right > A.right;
		return priority > A.priority;
	}
} tmp;

int main()
{
	priority_queue<Node> Q; //���ȶ��� 
	string str;
	int right = 0;//Ȩֵ 
	while( cin >> str ){
		if( str == "GET" ){
			if( Q.empty() ) cout << "EMPTY QUEUE!" << endl;
			else {
				tmp = Q.top() ;
				Q.pop() ;
				cout << tmp.msg << ' ' << tmp.parameter << endl;
			}
		}
		else if( str == "PUT" ){
			Node temp;
			cin >> temp.msg >> temp.parameter >> temp.priority;
			temp.right = right++;
			Q.push( temp ); 
		}
	}
 } 
