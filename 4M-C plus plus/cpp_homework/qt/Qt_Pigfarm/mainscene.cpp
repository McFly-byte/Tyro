#include "mainscene.h"
#include "ui_mainscene.h"
#include <QFile>
#include <QDebug>

mainScene::mainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainScene)
{
    ui->setupUi(this);
    this->initial();

}

void mainScene::initial()
{
    srand((unsigned)time(nullptr));
    this->setFixedSize( 1280 , 880 );
    setWindowTitle("猪场");
    setWindowIcon(QIcon(":/i/smallWindow.jpeg"));                   //需要窗口小标图片路径
    MyButton * startBtn = new MyButton(":/i/play.png",":/i/play2.png");  //start按钮图片稍后添加
    startBtn->resize(50,75);
    startBtn->setParent(this);
    startBtn->move((this->width()*0.5-startBtn->width()*0.5)/2,this->height()*0.7-110);
    connect( startBtn , &MyButton::clicked , [=] () {
        startBtn->zoomDown();
        startBtn->zoomUp();

        if( this->farm == nullptr ){
            int arg = QMessageBox::question(this,"欢迎来到猪场模拟游戏","要启动一个新的猪场吗");
            if( arg == QMessageBox::Yes ){
                    this->farm = new Pigfarm;                           //这里怎么写看构造函数
                    QTimer::singleShot(500,this,[=](){
                    this->hide();
                    this->farm->show();
                    global_t = 0;
                    Farm_Time->start(interval);                      //启动计时器 check
                });
            }
        }
        else{
            this->hide();
            this->farm->show();
            Farm_Time->start(interval);
        }
    });
    connect(ui->actioninformation , &QAction::triggered , this , &mainScene::showInfo );
    connect( ui->actionsave , &QAction::triggered , this , &mainScene::loadFromFile );
    connect( this->farm , &Pigfarm::close_mainscene , this , &mainScene::close );
    connect(ui->actionquit, &QAction::triggered , this , &QMainWindow::close );
}


void mainScene::showInfo()
{
    QString str;
    str = QString("课程设计之猪场模拟\n9191040423刘明承\n  呕心沥血");
    QMessageBox::information(this,"创作者信息",str);
}

void mainScene::loadFromFile()  //数字都是零，计时器没打开
{
    this->farm = new Pigfarm;

    QFile day(day_file);
    if (!day.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << day_file << "to write.";
        return ;
    }
    QTextStream dayin(&day);
    dayin >> global_t ;
    day.close();

    QFile virus(ill_file);
    if (!virus.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << ill_file << "to write.";
        return ;
    }
    QTextStream vin(&virus);
    vin >> src_id[0] >> src_id[1]  ;
    vin >> this->farm->virus_time;
    for( int i = 0  ; i < 100 ; i++ ){
        for( int j = 0 ; j < 10 ; j++ ){
            vin >> sickPig[i][j] ;
        }
    }
    virus.close();

    QFile data(data_file);
    if (!data.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << data_file << "to write.";
        return ;
    }
    QTextStream din(&data);
    din >> Expense >> Income;
    din >> this->farm->Amount[0]  >> this->farm->Amount[1] >> this->farm->Amount[2]  >> this->farm->Amount[3] >> this->farm->virus_time ;
    pigsty tmp = this->farm->Head;
    int temp;
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        din >> tmp->ID >> tmp->Amount[0]  >> tmp->Amount[1]  >> tmp->Amount[2] >>  tmp->Amount[3]  >> temp;
        if( temp != 0 ) tmp->isAllBlack = true;
        else tmp->isAllBlack = false;
        for( int j = 0 ; j < 10 ; j++ ){
            din >> tmp->pigs[j].StyID >> tmp->pigs[j].ID >> tmp->pigs[j].Breed  >> tmp->pigs[j].Weight
                >> tmp->pigs[j].FedTime  >> temp >> tmp->pigs[j].beenInfected ;
            if( temp != 0 ) tmp->pigs[j].isExist = true;
            else tmp->pigs[j].isExist = false;
        }
    }
    data.close();

    QMessageBox::information(this,"提示","读档成功，欢迎回到猪场");
}

void mainScene::paintEvent( QPaintEvent * e )
{
    Q_UNUSED( e );
    QPainter qpainter(this);
    QPixmap qpix;
    qpix.load(":/i/backgroung.jpg");                                                  //需要背景图路径
    qpainter.drawPixmap(0,0,this->width(),this->height(),qpix);
}

mainScene::~mainScene()
{
    delete ui;
}
