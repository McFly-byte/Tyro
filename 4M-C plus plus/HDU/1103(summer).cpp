#include <iostream>//��һ��д���ⶼ�����ˣ�֮���ֹ��˺þò��ö���д������
				  //���кö�ֵ�øĽ��ĵط����������᲻д�� 
#include <queue>
using namespace std;

int tb2, tb4, tb6;//���������� ÿ��������Ŀ 
int diners; 
queue<int> a,b,c;//Ҳ��������
				// ����ϱ�table_amount:tb2/4/6,ѭ������ʡ�ܶ����ռ� 

void Judge( int dnr_n , int arv_tm );//diners'number && arrival time

int main()
{
	while( ( cin >> tb2 >> tb4 >> tb6 ) &&  ( tb2+tb4+tb6 ) != 0 ){
		while( !a.empty() ) a.pop();
		while( !b.empty() ) b.pop(); 
		while( !c.empty() ) c.pop();//���г�ʼΪ�� ��û�뵽�ð취200906 
		diners = 0; //���ڲ����Է������� 
		string time;//����ʱ��|��ʼ�ò�ʱ�� 
		int tm_min , dnr_num;
		while( cin >> time && time[0] != '#' ){
			cin >> dnr_num;
			tm_min = ((time[0]-'0')*10+(time[1]-'0'))*60
					+((time[3]-'0')*10+(time[4]-'0'));	
				//��ʱ���ת��Ҳû�뵽�ð취 
			Judge( dnr_num , tm_min );
		}
		cout << diners << endl;
	}
}

void Judge( int dnr_n , int arv_tm )
{
	//�ȴ���tb2�ģ����������� 
	if( dnr_n == 1 || dnr_n == 2 ){
		if( a.size() < tb2 ){//���sizeΪ0 a.front()��RE�� ����ֱ����a.front() 
			a.push ( arv_tm );
			diners += dnr_n; 
		}
		else if( a.size() == tb2 ){
			if( arv_tm >= a.front() && arv_tm <= a.front() + 30 ){
				arv_tm = a.front() + 30;
				a.pop();
				a.push(arv_tm); 
				diners += dnr_n; 
			}
			else if( arv_tm > a.front() + 30 ){
				a.pop();
				a.push(arv_tm);
				diners += dnr_n; 
			}
		} 
	}
	else if( dnr_n == 3 || dnr_n == 4 ){
		if( b.size() < tb4 ){//���sizeΪ0 a.front()��RE�� 
			b.push ( arv_tm );
			diners += dnr_n; //cout << '\t' << diners << ' ' << arv_tm << endl;
		}
		else if( b.size() == tb4 ){	//cout << endl;
			if( arv_tm >= b.front() && arv_tm <= b.front() + 30 ){
				arv_tm = b.front() + 30;
				b.pop();
				b.push(arv_tm); 
				diners += dnr_n;  //cout << ' ' << diners << ' ' << arv_tm << endl;
			}
			else if( arv_tm > b.front() + 30 ){
				b.pop();
				b.push(arv_tm);
				diners += dnr_n;  //cout << ' ' << diners << ' ' << arv_tm << endl;
			}
		} 
	}
	else if( dnr_n == 5 || dnr_n == 6 ){
		if( c.size() < tb6 ){//���sizeΪ0 a.front()��RE�� 
			c.push ( arv_tm );
			diners += dnr_n; 
		}
		else if( c.size() == tb6 ){
			if( arv_tm >= c.front() && arv_tm <= c.front() + 30 ){
				arv_tm = c.front() + 30;
				c.pop();
				c.push(arv_tm); 
				diners += dnr_n; 
			}
			else if( arv_tm > c.front() + 30 ){
				c.pop();
				c.push(arv_tm);
				diners += dnr_n; 
			}
		}
	}
}
