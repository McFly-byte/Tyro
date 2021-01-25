#include "mainscene.h"
#include "external.h"
#include <QApplication>
#include <fstream>

using namespace std;

int standard_weight = 100;
int standard_time = 360;
QTimer * Farm_Time = new QTimer;
int global_t = 0;
int interval = 500;
int a[100][10] = {0};
int sickPig[100][10] = {0}; 			//生病的猪对应的数组
int src_id[2] = {-1,-1};
double Expense = 0;
double Income = 0;
double Cost[4] = { 0.0 , 9.0 , 4.0 , 2.0 };
double Earn[4] = { 0.0 , 15.0 , 7.0 , 6.0 };
QString global_file = "../Qt_file/information.txt";	//存放猪场扩展信息
QString data_file = "../Qt_file/data.txt";			//存放猪场全部属性
QString day_file = "../Qt_file/Day.txt";			//存放猪场相对日期
QString ill_file = "../Qt_file/illness.txt";		//存放猪瘟模拟信息

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainScene w;
    w.show();

    return a.exec();
}
