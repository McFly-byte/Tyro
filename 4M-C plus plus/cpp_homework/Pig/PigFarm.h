#ifndef PIGFARM_H
#define PIGFARM_H

#include <bits/stdc++.h>
using namespace std;

#define market_weight 100 //����������� 
#define simulation_duration 360  //ģ��ʱ�� 10�� 

enum breed{ Black = 1 , White , Colorful }; //Ʒ��  

extern char datafile[50];
extern char dayfile[50];
extern char filename[50];
extern char illfile[50];
extern int a[100][10];			//a ����ģ�⣬ sickPig������¼��ʵ���� 
extern int sickPig[100][10];    //��������  ׼�������� 
extern int sickId[2];
extern ofstream fout;
extern int FarmTime;		//��ʱ�� 
extern double Expense; 		//��֧�� 
extern double Income; 		//������ 
extern double Cost[4];		//���� 
extern double Price[4];		//�ۼ� 

typedef struct Pig * pig;
struct Pig{
	int ID;//��� 
	breed Breed;//Ʒ�� 
	double Weight;//���� 
	int Time;//����ʱ�� 
	int LifeSpan;//�Ƿ�����/ʣ������ 
};

typedef struct Pigsty * pigsty;
struct Pigsty{
	int ID;//��Ȧ��� 
	int amount[4];//0-������1-�ڣ�2-�ף�3-�� 
	Pig sty[10];//������� 
	pigsty Next;
}; 

typedef struct Pigfarm * pigfarm;
struct Pigfarm{
	int Farm_Time;//ũ��ʱ��,��������Ĳ�����������޹� 
	pigsty Head;//�������Ȧǰһ��λ�ã���ָ 
};

bool isQualified( pig obj );//�ж��Ƿ�ﵽ���۱�׼ 

void grow( pig obj );//һͷ�������ʱ�䣨�����ڲ�ѯ�������������� 

void gain( pigfarm p , int time = 1 );//������������ 

void sellAndBuy( pigfarm p );//�������������� 

double sellPig( pigsty sty , int pig_id );//��һͷ�� �������� 

double buyPig( pigsty sty , int Id );//��һͷ����¼���� 

pigsty CreatePigsty( int id );//�����µ���Ȧ 

pigfarm CreatePigfarm();//�����µĳ� 

void printPig( pigfarm p , int Id1 , int Id2 );// ��ӡĳͷ���״̬��Ϣ

void printPig( pig obj , int Sty_Id );//ͬ�� �������� 

void printPigsty( pigfarm p , int Id );//��ӡĳһ��Ȧ��������������� 

void printPigfarm( pigfarm p );//��ӡ��ÿ��Ʒ��������������طֲ���� 

void saveIofor( pigfarm p ); //������Ϣ��ŵ�txt�ļ��� 

void getSick(); //����������

int simulation( int period );//ģ�⴫Ⱦ period������ͷ����Ⱦ 

void Welcome_to_the_( pigfarm p ); //��ӭ�� 

void startTime( pigfarm p , int maxTime , int sickTime = 1000000 ); 

void method( pigfarm p , int sickTime );

#endif 
