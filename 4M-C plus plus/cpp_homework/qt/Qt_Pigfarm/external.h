#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <QTimer>

extern int standard_weight;
extern int standard_time;
//时间
extern QTimer * Farm_Time;
extern int global_t;
extern int interval;
//收支
extern double Expense;
extern double Income;
extern double Cost[4];
extern double Earn[4];
//文件名
extern QString data_file;
extern QString day_file;
extern QString ill_file;
extern QString global_file;
//传染
extern int sickPig[100][10];
extern int a[100][10];
extern int src_id[2];

#endif // EXTERNAL_H
