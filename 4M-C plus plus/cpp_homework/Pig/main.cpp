#include <iostream> 
#include "PigFarm.h"
using namespace std;

char filename[50] = "information.txt";	//�������չ��Ϣ 
char datafile[50] = "data.txt";			//�����ȫ������ 
char dayfile[50] = "Day.txt";			//������������ 
char illfile[50] = "illness.txt";		//�������ģ����Ϣ
int a[100][10] = {0}; 
int sickPig[100][10] = {0}; 			//���������Ӧ������ 
int sickId[2];
ofstream fout( filename , ios::app );
int FarmTime = 0;
double Expense = 0;
double Income = 0;
double Cost[4] = { 0.0 , 9.0 , 4.0 , 2.0 };
double Price[4] = { 0.0 , 15.0 , 7.0 , 6.0 };

int main() 
{
	srand((unsigned)time(NULL));			//ʱ������ 
	pigfarm pig_farm = CreatePigfarm();		//����һ���� 
	Welcome_to_the_(pig_farm); 				//�Դ�����һϵ������ 
	fout.close();							//�ر�ȫ���ļ� 
	return 0;
}
