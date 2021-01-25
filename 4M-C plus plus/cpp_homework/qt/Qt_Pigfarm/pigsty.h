#ifndef PIGSTY_H
#define PIGSTY_H

#include "pig.h"
#include <QMainWindow>

namespace Ui {
class Pigsty;
}

typedef class Pigsty * pigsty;
class Pigsty : public QMainWindow
{
    Q_OBJECT

public:
    int ID;
    Pig pigs[10];   //圈中猪
    pigsty Next;    //下一个猪圈
    int Amount[4]; //该圈各种数目
    bool isAllBlack;//是否全部黑猪

    explicit Pigsty(int id = -1 , QWidget *parent = nullptr);//猪圈构造函数
    ~Pigsty();//猪圈析构函数
    void sell( int id = -1 );//卖猪圈中的猪
    void buy( int id = -1 );//为猪圈添加新猪
    void buyThroughWindow();//通过窗口买
    void sellThroughWindow();//通过窗口卖
    void showInfo();//显示该猪圈信息
    void initial();//初始化猪圈页面
    void paintEvent( QPaintEvent * e );

signals:
    void back_to_farm();
private:
    Ui::Pigsty *ui;
};



#endif // PIGSTY_H
