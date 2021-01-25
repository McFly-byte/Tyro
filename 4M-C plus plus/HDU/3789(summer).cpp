#include <bits/stdc++.h> 
using namespace std;

struct nation{
	double Gold_Medals;
	double All_Medals;
	double Population;
	double G_P;
	double A_P;
	int best_rank;
	int method;
	int ID;//��ʼ���� 
	int id;//ɾȥ������������Ԫ��֮������λ�� 
};

bool cmp1(pair<double,int> &a, pair<double,int> &b){
    return a.first >= b.first;
}

int main()
{
	int N , M;
	nation tmp;
	while( cin >> N >> M ){
		 
		vector<nation> country;//�������� 
		for( int i = 0 ; i < N ; i++ ){
			cin >> tmp.Gold_Medals >> tmp.All_Medals >> tmp.Population ;
			tmp.G_P = tmp.Gold_Medals/tmp.Population;
			tmp.A_P = tmp.All_Medals/tmp.Population;
			tmp.ID = i;
			country.push_back( tmp );
		}
		
		int b[M] = {0};//��ѡ���ұ�� 
		for( int j = 0 ; j < M ; j++ ) 
			cin >> b[j];
			
		//ɾȥ�������е�Ԫ�� 	
		int k = 0;
		vector<nation>::iterator it;
		for( it = country.begin() ; it < country.end() ; ){
		
		//	cout << (*it).ID << ' ' << (*it).Gold_Medals << endl;
			if( (*it).ID == b[k] ){
				(*it).id = k++;	
				it++;
			}		
			else
				country.erase(it);
		}
		
		//������� 
		/*for( it = country.begin() ; it < country.end() ; it++ )
			cout << (*it).ID << ' ' << (*it).Gold_Medals << ' ' 
			     << (*it).All_Medals << ' ' << (*it).Population << endl;*/
			     
		//ģ��4������ 
		for( int i = 1 ; i <= 4 ; i++ ){
			vector< pair<double,int> > temporary;
			if( i == 1 ){
				for( it = country.begin() ; it < country.end() ; it++ )
					temporary.push_back(make_pair<double,int>((*it).Gold_Medals,(*it).id));
			}
			else if( i == 2 ){
				for( it = country.begin() ; it < country.end() ; it++ )
					temporary.push_back(make_pair<double,int>((*it).All_Medals,(*it).id));
			}
			else if( i == 3 ){
				for( it = country.begin() ; it < country.end() ; it++ )
					temporary.push_back(make_pair<double,int>((*it).G_P,(*it).id));
			}
			else {
				for( it = country.begin() ; it < country.end() ; it++ )
					temporary.push_back(make_pair<double,int>((*it).All_Medals,(*it).id));
			}
			sort( temporary.begin() , temporary.end() , cmp1 );
			vector< pair<double,int> >::iterator iter;
			int flag_id = 0;
			double position = -1;//�����ж��Ƿ��� 
			it = country.begin();
			for( iter = temporary.begin() ; iter < temporary.end() ; iter++ ){
				if( position != (*iter).first ){
					position = (*iter).first;
					flag_id++;
				}
				if( i== 1 || (*(it+(*iter).second)).best_rank > flag_id ){
					(*(it+(*iter).second)).best_rank = flag_id;
					(*(it+(*iter).second)).method = i; 
			  	}
			}
		}
		for( it = country.begin() ; it < country.end() ; it++ )
			cout << (*it).best_rank << ':' << (*it).method << endl;
	}
}
