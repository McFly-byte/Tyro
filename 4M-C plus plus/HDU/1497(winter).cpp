/*******************************************************************************
	(��������ʼдǰ��ע�Ͱ�)
	*ʱ�䣺2020-12-18
	*���ߣ���
	*������ǰ���ύ�˲���10�Σ�����һЩС���⡣����˳�򿴷���->tle->��Ϊ��
	cin������->��cinΪscanf->���ûȫ���������ö��ߵ���˵������Ĵ���->��
	��ǧ�������ڸ��ֵİ����������ҳ���->���ˣ�һ���->̫����ˣ�������˵��
	˵����Щ����д�Ļ��ǲ����(��'\/'��) 
*******************************************************************************/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct book{
	int id;
	bool isborrowed;
	friend bool operator < ( book a , book b ){
		return a.id < b.id;
	}
}b;

struct user{
	int id;
	int num;
	vector<int> book_id;
};

int main()
{
//	ios::sync_with_stdio( false );
//	cin.tie(0);
	int M, N, n;			//M��������N��������� 
	while ( cin >> M >> N ){		//���˰��죬ԭ����NM����˳���� tcl
									//jlwc�˼���cin���ܹ�����������
									//�ٺ���Ҳ�� 
		vector<user> p;
		vector<book> lib;
		user u; 
		char ch;
		for( int i = 1 ; i <= M ; i++ ){
			u.id = i;
			u.num = 0;
			p.push_back( u );
		}
		for( int j = 1; j <= N ; j++ ){
			b.id = j;
			b.isborrowed = false;
			lib.push_back( b );
		}

		cin >> n;
		for( int i = 0; i < n ; i++ ){
			cin >> ch;
			if( ch == 'B' ){
				int ui,bi;
				cin >> ui >> bi;	
				if( lib[bi-1].isborrowed == true )
					cout << "The book is not in the library now" << endl;
				else {
					if( p[ui-1].num >= 9 )
						cout << "You are not allowed to borrow any more" << endl;
					else{
						p[ui-1].num++;
						p[ui-1].book_id.push_back( bi );
						lib[bi-1].isborrowed = true;
						cout << "Borrow success" << endl;
					}
				}
			}
			else if( ch == 'R' ){
				int bi;
				cin >> bi;
				if( lib[bi-1].isborrowed == false )
					cout << "The book is already in the library" << endl;
				else{
					lib[bi-1].isborrowed = false;
					for( int j = 0 ; j < M ; j++ )
					{
						bool tag = false;
						if( p[j].num )
						{
							for( int k = 0; k < p[j].num ; k++ )
							{
								if( p[j].book_id[k] == bi )
								{
									vector<int>::iterator it = p[j].book_id.begin()+k;
									p[j].book_id.erase(it);
									p[j].num--;
									cout << "Return success" << endl;
									tag = true;
									break;
								}
							}
							if( tag ) break;
						}
					}
				}
			}
			else if( ch == 'Q' ){
				int ui;
				cin >> ui;
				if( p[ui-1].num == 0 ) cout << "Empty" ;
				else {
					sort( p[ui-1].book_id.begin() , p[ui-1].book_id.end() );
					for( int i = 0 ; i < p[ui-1].num ; i++ ){
						if( i ) cout << ' '; 
						cout << p[ui-1].book_id[i];
					}
				}
				cout << endl;
			} 
		}
		cout << endl;
	}
	return 0;	
} 
