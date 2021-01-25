#include "PigFarm.h"

bool isQualified( pig obj ){//�жϿɷ���� 
	return ( obj->Weight >= market_weight || obj->Time >= 300 );
}

void grow( pig obj ){//��ͷ������ 
	obj->Time++; 
	srand((unsigned)time(NULL));
	obj->Weight += (double)(rand()%12)/10.0;
} 

void gain( pigfarm p , int time ){//������������ 
	pigsty tmp = p->Head;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		for( int j = 0 ; j < 10 ; j++ ){
			for( int k = 0 ; k < time ; k++ )
				grow( &tmp->sty[j] );
		}
	}
} 
 
pigsty CreatePigsty( int id ){
	pigsty newsty = (pigsty)malloc( sizeof( struct Pigsty ) );
	newsty->ID = id;
	for( int i = 0 ; i < 4 ; i++ )
		newsty->amount[i] = 0;
	bool isBlack = false;
	int random_num = rand()%3+1;
	if( random_num == 1 ) isBlack = true;
	for( int i = 0 ; i < 10 ; i++ ){
		newsty->sty[i].ID = i;
		newsty->sty[i].Time = 0;
		newsty->sty[i].Weight = (double)(rand()%31+20);
		
		if( isBlack ){
			newsty->sty[i].Breed = (breed)1;
			newsty->amount[1]++; 
		}
		else {
			random_num = rand()%2+2;
			newsty->sty[i].Breed = (breed)random_num;
			newsty->amount[random_num]++;		
		}	
	}
	newsty->amount[0] = 10;
	newsty->Next = NULL;
	return newsty;
}

pigfarm CreatePigfarm(){
	pigfarm pfarm = (pigfarm)malloc(sizeof( struct Pigfarm ) );
	pfarm->Farm_Time = 0;
	pfarm->Head = (pigsty)malloc( sizeof( struct Pigsty ) );
	pfarm->Head->Next = NULL;
	for( int i = 99 ; i >= 0 ; i-- ){//ʹ��Head����һ��i==0 
		pigsty tmp = CreatePigsty( i );
		tmp->Next = pfarm->Head->Next;
		pfarm->Head->Next = tmp;
	}
	return pfarm; 
}

void printPig( pigfarm p , int Id1 , int Id2 ){
	pigsty tmp = p->Head;
	for( int i = 0 ; i <= Id1 ; i++ ){
		tmp = tmp->Next; 
	}
	fout << "(��(oo)��) ��Ȧ��ţ�" << tmp->ID << "	���ţ�" << Id2 
	<< "	Ʒ�֣�";
	if( tmp->sty[Id2].Breed == 1 ) fout << "����";
	else if( tmp->sty[Id2].Breed == 2 ) fout << "����";
	else if( tmp->sty[Id2].Breed == 3 ) fout << "����";
	fout << "	����ʱ�䣺" << tmp->sty[Id2].Time;
	fout << "	���أ�" << tmp->sty[Id2].Weight << endl;	
}

void printPig( pig obj , int Sty_Id ){
	fout << "(��(oo)��) ��Ȧ��ţ�" << Sty_Id << "	���ţ�" 
		 << obj->ID << "	Ʒ�֣�";
	if( obj->Breed == 1 ) fout << "����";
	else if( obj->Breed == 2 ) fout << "����";
	else if( obj->Breed == 3 ) fout << "����";
	fout << "	����ʱ�䣺" << obj->Time;
	fout << "	���أ�" << obj->Weight << endl;
}

void printPigsty( pigfarm p , int Id )
{
	pigsty tmp = p->Head;
	for( int i = 0 ; i <= Id ; i++ )
		tmp = tmp->Next;
	fout << "��" << Id << "����Ȧ����ǰ������" << tmp->amount[0];
	if( tmp->amount[1] ) fout << " ����������" << tmp->amount[1] << endl;
	else fout << " ����������" << tmp->amount[2] << " ����������" << tmp->amount[3] << endl;
	fout << "�ɱ�����(���)��";
	bool isNone = true;
	for( int i = 0 ; i < 10 ; i++ )
		if( isQualified( &tmp->sty[i] ) ){
			fout << i << ' ';
			isNone = false;
		} 
	if( isNone ) fout << "��" ; 
	fout << endl ;
}

void printPigfarm( pigfarm p )//��ӡ���طֲ�ͼ  �� 
{
	pigsty tmp = p->Head;
	int t_num = 0 , b_num = 0 , w_num = 0 , c_num = 0; 
	int count[11] = {0} , position = 0; 
	int sup_count[5] = {0} , sup_position = 0;// 0-90 90-180 180-270 270-360 360-
	for( int i = 0 ; i < 100 ; i++ ){//��Ȧ��ѭ�� 
		tmp = tmp->Next;
		t_num += tmp->amount[0];
		b_num += tmp->amount[1];
		w_num += tmp->amount[2];
		c_num += tmp->amount[3];
		for( int j = 0 ; j < 9 ; j++ ){//ÿȦ�����ѭ�� 
		//���طֲ� 
			position = (int)(tmp->sty[j].Weight)/10 - 2 ;
			if( position > 10 ) position = 10 ;
			count[position]++;
		//ʱ��ֲ�
			sup_position = tmp->sty[j].Time/90;
			if( sup_position > 4 ) sup_position = 4;//���ᳬ��360�� 
			sup_count[sup_position]++; 
		}
	}
	fout << "����������Ŀ ������" << t_num << ",����������" << b_num 
	<< ",����������" << w_num << ",����������" << c_num << endl;
	//��ӡ���طֲ�ͼ 
	fout << "������طֲ���" << endl;
	for( int i = 0 ; i < 11 ; i++ )
		if( count[i] ) count[i] = sqrt(count[i]);
	int height = count[0];
	for( int i = 1 ; i < 11 ; i++ )
		if( count[i] > height ) height = count[i];
	
	for( int i = height ; i > 0 ; i-- ){
		fout << ' ';
		for( int j = 0 ; j < 11 ; j++ ){
			if( count[j] >= i ) fout << setw(4) << '*';
			else fout << "    ";  
		}
		fout << endl;
	}
	for( int k = 20 ; k <= 120 ; k += 10)
		fout << setw(4) << k ;
	fout << " ...(��������,����ҿ�)" << endl;
	//��ӡʱ��ֲ�ͼ
	fout << "�������ʱ��ֲ���" << endl;
	for( int i = 0 ; i < 5 ; i++ )
		if( sup_count[i] ) sup_count[i] = sqrt(sup_count[i]);
	//�ҵ����ֵ
	int sup_height = sup_count[0];
	for( int i = 1 ; i < 5 ; i++ )
		if( sup_count[i] > sup_height ) sup_height = sup_count[i];
	for( int i = sup_height ; i > 0 ; i-- ){
		fout << ' ';
		for( int j = 0 ; j < 5 ; j++ ){
			if( sup_count[j] >= i ) fout << setw(4) << '*';
			else fout << "    ";  
		}
		fout << endl;
	}
	for( int k = 0 ; k <= 360 ; k += 90)
		fout << setw(4) << k ;
	fout << " ...(����ʱ������,����ҿ�)" << endl;
}

double sellPig( pigsty psty , int pig_id )
{
	pig obj = &psty->sty[pig_id];
	printPig( obj , psty->ID ); //�����ļ���ʱûʵ�֣��Ȱ���Ϣ����� 
	double price = obj->Weight * Price[obj->Breed];
	fout << "����õ�" << price << "Ԫ(" 
	     << Price[obj->Breed] << "Ԫ/ǧ��)\n";  
	obj->Time = 0;	obj->Weight = 0.0;
	//����breed ��������������ͬ�������� 
	psty->amount[0]--; 
	psty->amount[obj->Breed]--;
	return price; 
}

double buyPig( pigsty psty , int Id )
{
	pig obj = &psty->sty[Id];
	obj->Time = 0;
	obj->Weight = (double)(rand()%31+20);
	if( obj->Breed != 1 ){
		obj->Breed = (breed)(rand()%2+2); 
	}
	psty->amount[obj->Breed]++;
	psty->amount[0]++; 
	printPig( obj , psty->ID );
	double price = Cost[obj->Breed] * obj->Weight;
	fout << "������" << price << "Ԫ(" 
	     << Price[obj->Breed] << "Ԫ/ǧ��)\n"; 
	return price;
}

void sellAndBuy( pigfarm p )
{
	pigsty tmp = p->Head;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		for( int j = 0; j < 10 ; j++ ){
			if( isQualified( &tmp->sty[j] ) ){
				Income += sellPig( tmp , j );
				Expense += buyPig( tmp , j ); 
			}	
		} 
	}
}

void startTime( pigfarm p , int maxTime , int sickTime )
{
	while( ++FarmTime && FarmTime <= maxTime ){
			if( FarmTime%90 == 0 && sickTime > FarmTime ){
				if( FarmTime%360 == 0 ) fout << "��" << FarmTime/360 + 1 << "�����ۼ�¼" << endl; 
				fout << "��" << FarmTime << "�����������" << endl;
				cout << "�� " << FarmTime << " �� : ����" << endl; 
				gain( p , 90 ); //�������� 
				printPigfarm( p ); //��ӡ����Ϣ 
				sellAndBuy( p );	//�����Ե� ֻ����� 
				cout << "�����룺" << Income << ' ' << "��֧����" << Expense << endl; 
			}	
			if( sickTime == FarmTime ){ //��ʼ���� 
				cout << "	��" << FarmTime << "�죬���������ˣ�" << endl; 
				getSick();
				int tm = 0; 
				while( simulation(5) < 1000 ) tm += 5; //������ʼ�ĵ�tm�� 
				cout << "������ȡ��ʩ����Լ" << tm << "������е������Ⱦ" << endl;
				fout << "��Լ" << tm << "�����Ȧ������" << endl; 
				fout << "ģ�����ݼ�" << illfile << endl; 
				ofstream fill( illfile , ios::app );
				fill << "ģ������: (���ֶ�Ӧ����ڼ��챻��Ⱦ)" << endl; 
				for( int j = 0 ; j < 10 ; j++ ){
					for( int i = 0; i < 100 ; i++ ){
						fill << a[i][j] << ' ';
						a[i][j] = sickPig[i][j];//aֻ��ģ�⣬��ɺ�Ҫ��ԭ 
					}
					fill << endl;
				}
				fill << endl;				 
			}
			else if( sickTime < FarmTime ){ //ģ�⴫Ⱦ �� ����������Ⱦʱũ���� 
				cout << "	���߱�����" << FarmTime-sickTime+1 << "��" << endl;
				cout << "	�Ƿ��ȡ��ʩ��" ;
				int tag;
				cin >> tag;
				if( tag ){
					cout << "	��ȡ�����ʩ" << endl;
					method(p,sickTime);
					sickTime = 1000000;
				}
				else{
					int num;
					num = simulation(1); 
					ofstream fill( illfile , ios::app );
					fill << "���߱�����" << FarmTime-sickTime+1 << "��" << endl;
					for( int j = 0 ; j < 10 ; j++ ){
						for( int i = 0; i < 100 ; i++ ){
							fill << a[i][j] << ' ';
							sickPig[i][j] = a[i][j];//aֻ��ģ�⣬��ɺ�Ҫ��ԭ 
						}
						fill << endl;
					}
					fill << endl;
					if( num > 100 && num < 200 )
						cout << "	�����ڰ���,�����ڿ���,����ô��ô����/(��o��)/~~" << endl;
					else if( num >= 200 && num < 300 )
						cout << "	����ΨΨŵŵ��������ȭ������" << endl;
					else if( num >= 300 && num < 400 )
						cout << "	���ܹ������꣬������������Ӷ�������" << endl;
					else if( num >= 400 && num < 500 )
						cout << "	������ӹ���������е��޷��ӱܵĶ�����" << endl;
					else if( num >= 500 && num < 600 )
						cout << "	������װʧ�䣬�ᱻ�����˳û�������" << endl;
					else if( num >= 600 && num < 700 )
						cout << "	����һ�����Σ��������ȱ�����" << endl;
					else if( num >= 700 && num < 800 )
						cout << "	������ˮ������������˼����ɽ" << endl; 
					else if( num >= 800 ){					 
						cout << "������ʮ�ֶ��ӣ��ѱ���⣬�ټ���" << endl;
						break; 
					} 
				}
			}
		}
}

void getSick(){ //���������� ��������Ϊ��1�� 
	int id1 , id2;
	id1 = rand()%100;
	id2 = rand()%10;
	sickPig[id1][id2] = 1; 
	a[id1][id2] = 1; 
	fout << "����������" << endl; 
	fout << "Դͷ��" << id1 << "����Ȧ�ĵ�" << id2 << "ͷ��" << endl;
	cout << "Դͷ��" << id1 << "����Ȧ�ĵ�" << id2 << "ͷ��" << endl;
	sickId[0] = id1 , sickId[1] = id2;
} 

int simulation( int period )//��a�����Ӧ�ĵ�ǰ�쿪ʼ���������tm�� 
{ 
	int nowaday = 1 , ans = 0;
	//�ҵ����������ֵ��Ҳ�����߱������� 
	for( int i = 0 ; i < 100 ; i++ ){
		for( int j = 0;  j < 10 ; j++ ){
			if( a[i][j] > nowaday ) nowaday = a[i][j]; 
		}
	}
	int ran1 , ran2; //��Ⱦ���� 1-ͬȦ 2-��Ȧ 
	nowaday++;
	for( int t = nowaday; t < period+nowaday ; t++ ){
		for( int i = 0 ; i < 100 ; i++ ){
			for( int j = 0 ; j < 10 ; j++ ){
				if( a[i][j] < t && a[i][j] != 0 ){
					for( int k = 0 ; k < 10 ; k++ ){
						if( a[i][k] == 0 ){
							ran1 = rand()%2;
							if( ran1 ) a[i][k] = t;
						}
						if( i>=1 && a[i-1][k] == 0 ){
							ran2 = rand()%20;
							if( ran2 < 3 ) a[i-1][k] = t;
						}
						if( i<99 && a[i+1][k] == 0 ){
							ran2 = rand()%20;
							if( ran2 < 3 ) a[i+1][k] = t;
						}
					}	
				}
			}
		}	
	}
	ans=0;
	//ofstream fill( illfile , ios::app );
	for( int j = 0 ; j < 10 ; j++ )
		for( int i = 0 ; i < 100 ;i ++ )
			if( a[i][j] ) ans++;
	//fill.close();
	return ans;
}

void method( pigfarm p , int sickTime )
{
	//ofstream fill( illfile , ios::app );
	pigsty tmp = p->Head;
	int num = 0;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		bool isInfected = false;
		for( int j = 0 ; j < 10 ; j++ ){
			if( sickPig[i][j] ){
				isInfected = true;
				Expense += buyPig( tmp , j );
				Expense += tmp->sty[j].Weight * (FarmTime-sickTime+1);
				fout << "��Ȧ��ţ�" << i << " ���ţ�" << j << " �ѱ�����" << endl;
			}
		}
		if( isInfected ){
			num++;
			Expense += 5000; 
			fout << "��Ȧ��ţ�" << i << " �ѱ�����" << endl;
		}
	}
}

void Welcome_to_the_( pigfarm p )
{
	ifstream fin(filename, ios::ate);
	long location = fin.tellg();
	if( location == 0 ){
		//һЩ�ϻ� 
		cout << "��ӭ����������ģ�⣬�㲻��Ҫ���κ��¾Ϳ��Եõ�һ���ζ��ϵ���" << endl;
		cout << "�������ڻ��Զ�������ÿ90���Զ�����һ������Ҫ�������ʱ������Ϣ��ʾ��" << endl;
		cout << "������Ϣ���ᱻ��¼����ʼ��" << endl;
		for( int i = 0 ; i < 100 ; i++ ) cout << '_' ;
		cout << endl; 
		system("pause"); 
		//�������ʼ��Ϣ 
		cout << "���������Ϣ�ѱ���¼���ı��ļ���information.txt����" << endl;
		fout << "����ʼ��Ϣ" << endl; 
		for( int i = 0 ; i < 100 ; i++ ){
			printPigsty( p , i );
			for( int k = 0 ; k < 10 ; k++ ){
				printPig(p,i,k);		
			}
		}
		printPigfarm( p );
		//ʱ���������Զ�������ʼ 
		cout << "��һ�����������Զ�����" << simulation_duration <<"����������Ժ�������Լ�����ʱ��" << endl; 
		startTime( p , simulation_duration );
		//����ǰʱ�䱣�棬�Ա����´δ� 
		ofstream dayout( dayfile , ios::out );
		dayout << FarmTime;
		//����ǰ������Ȧ/����Ϣ���棬�Ա����´δ� 
		pigsty ps = p->Head;
		ofstream dataOut( datafile , ios::out );
		for( int i = 0 ; i < 100 ; i++ ){
			ps = ps->Next;
			dataOut << ps->ID << ' ';
			for( int j  = 0 ; j < 4 ; j++ ) dataOut << ps->amount[j] << ' ';
			for( int k = 0 ; k < 10 ; k++ ){
				dataOut << ps->sty[k].ID << ' ';
				dataOut << (int)ps->sty[k].Breed << ' ';
				dataOut << ps->sty[k].Time << ' ';
				dataOut << ps->sty[k].Weight <<' ';
			}
		} 
		//�Ѵ򿪵��ļ�ͳͳ�ر� 
		dataOut.close();
		dayout.close();
	}
	else {
		//һЩ�ϻ� 
		cout << "��ӭ�ٴλص���" << endl; 
		//����ʱ�� 
		ifstream dayin( dayfile , ios::in );
		dayin >> FarmTime;
		cout << "���������ϵ�" << FarmTime << "��" << endl; 
		//������/��Ȧ/�����Ϣ 
		ifstream dataIn( datafile , ios::in );
		pigsty ps = p->Head;
		int temp;//breed���Ͳ���ֱ������ 
		for( int i = 0 ; i < 100 ; i++ ){
			ps = ps->Next;
			dataIn >> ps->ID;
			for( int j  = 0 ; j < 4 ; j++ ) dataIn >> ps->amount[j];
			for( int k = 0 ; k < 10 ; k++ ){
				dataIn >> ps->sty[k].ID ;
				dataIn >> temp;
				ps->sty[k].Breed = breed(temp);
				dataIn >> ps->sty[k].Time ;
				dataIn >> ps->sty[k].Weight ;
			}
		} 
		//�Ѹղŵ������Ϣ��� ��information.txt 
		cout << "��ǰ����Ϣ�ѱ���¼���ı��ļ���information.txt����" << endl;
		fout << "��ǰ����Ϣ" << endl; 
		for( int i = 0 ; i < 100 ; i++ ){
			printPigsty( p , i );
			for( int k = 0 ; k < 10 ; k++ ){
				printPig(p,i,k);		
			}
		}
		printPigfarm( p );
		//����һ��ʱ�䣬������������
		int maxT;
		cout << "����,�������������������������";
		cin >>  maxT;
		int ran_day = rand()%(maxT-360)+360; cout << ran_day << endl;
		cout << "��ĳһ�죬�����ܻ����������" << endl;
		startTime( p , maxT , ran_day );
		//����ǰʱ�䱣�棬�Ա����´δ� 
		ofstream dayout( dayfile , ios::out );
		dayout << FarmTime;
		//ͳͳ�ر� 
		dayout.close();
		dataIn.close();
		dayin.close();
	}
	fin.close();
}
