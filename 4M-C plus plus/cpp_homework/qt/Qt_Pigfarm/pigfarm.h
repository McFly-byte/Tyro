#ifndef PIGFARM_H
#define PIGFARM_H

#include "pigsty.h"
#include "mybutton.h"
#include <QMainWindow>

namespace Ui {
class Pigfarm;
}

class Pigfarm : public QMainWindow
{
    Q_OBJECT

public:
    pigsty Head;        //第一个猪圈
    int Amount[4];      //各种猪总数目
    int virus_time = 0; //病毒爆发第几天

    explicit Pigfarm(QWidget *parent = nullptr);
    ~Pigfarm();
    void initial();                                     //初始化猪场界面
    void getAmount();                                   //计算猪场猪数量
    void grow();                                        //整个猪场增长
    void sellAndBuy();                                  //猪场购买/出售猪
    void showTime();                                    //显示时间
    void showMoney();                                   //显示钱
    void showInfo();                                    //显示信息，打印分布图
    void outbreak();                                    //病毒爆发
    int  simulation( int n , bool tov = false );         //模拟
    void showVirus();                                   //为病猪更换图片
    void method();                                      //控制病毒措施
    void storeInFile();                                 //存档
    void paintEvent(QPaintEvent * e);

signals:
    void close_mainscene();

private:
    Ui::Pigfarm *ui;
};
typedef Pigfarm * pigfarm;

#endif // PIGFARM_H
