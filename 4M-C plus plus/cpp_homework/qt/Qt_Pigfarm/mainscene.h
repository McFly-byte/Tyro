#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "pigfarm.h"
#include "external.h"
#include "mybutton.h"
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QMainWindow>

namespace Ui {
class mainScene;
}

class mainScene : public QMainWindow
{
    Q_OBJECT
public:
    pigfarm farm = nullptr;
    explicit mainScene(QWidget *parent = nullptr);  //主界面构造函数
    ~mainScene();                                   //主界面析构函数
    void loadFromFile();                            //加载存档
    void initial();                                 //界面初始化
    void showInfo();                                //显示游戏信息
    void paintEvent(QPaintEvent * e);               //绘制背景等
private:
    Ui::mainScene *ui;
};

#endif // MAINSCENE_H
