#include "pigfarm.h"
#include "ui_pigfarm.h"
#include <QDebug>
#include <QTimer>
#include <QMovie>
#include <QFile>
#include <QPainter>
#include "external.h"

Pigfarm::Pigfarm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pigfarm)
{
    ui->setupUi(this);
    this->initial();

    Head = new Pigsty;
    this->Head->Next = nullptr;
    for( int i = 99 ; i >= 0 ; i-- ){
        pigsty tmp = new Pigsty( i , this );
        tmp->Next = Head->Next;
        Head->Next = tmp;
        tmp->hide();
        MyButton * styBtn = new MyButton(":/i/house.png");
        styBtn->setParent(this);
        styBtn->move( 90+75*((i)%15) , 200+75*(i/15)  );
        QLabel * lbl = new QLabel;
        lbl->setParent(this);
        lbl->setFixedSize(styBtn->width() , styBtn->height() );
        lbl->setFont(QFont("Ink Free",7,1));
        lbl->setText(QString::number(i));
        lbl->move(98+75*((i)%15) , 200+75*(i/15)  );
        lbl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect( styBtn , &MyButton::clicked , [=](){
            tmp->show();
            this->hide();
            Farm_Time->stop();
        });
        connect( tmp , &Pigsty::back_to_farm , [=](){
            Farm_Time->start(interval);
            tmp->hide();
            this->show();
        });
        styBtn->setFont(QFont("方正粗黑宋简体",12,1));
    }
    MyButton * pause = new MyButton(":/i/pause.png",":/i/pause2.png");
    pause->setParent(this);
    pause->move( this->width() - pause->width() , this->height() - pause->height() );
    QLabel * l = new QLabel;
    l->setParent(this);
    l->setFixedSize(pause->width() , pause->height() );
    l->setFont(QFont("Ink Free",10,1));
    l->setText("Pause");
    l->move(this->width() - pause->width() , this->height() - pause->height());
    l->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    l->setAttribute(Qt::WA_TransparentForMouseEvents);
    connect( pause , &MyButton::clicked , [=](){
       if( Farm_Time->isActive() ) Farm_Time->stop();
       else Farm_Time->start(interval);
    });
    this->getAmount();

}

void Pigfarm::initial()
{
    this->setFixedSize( 1280 , 880 );
    setWindowTitle("猪场");
    setWindowIcon(QIcon(":/i/smallWindow.jpeg"));                   //需要窗口小标图片路径
    ui->widget->move( this->width() * 0.5 - ui->widget->width()*0.5 , 15 );
    ui->label->setFont(QFont("方正粗黑宋简体",16,1));
    ui->label_3->setFont(QFont("Ink Free",12,1));
    ui->label_2->setFont(QFont("方正粗黑宋简体",16,1));
    ui->label_4->setFont(QFont("方正粗黑宋简体",12,1));
    ui->label_5->setFont(QFont("Ink Free",8,1));
    ui->label_7->setFont(QFont("方正粗黑宋简体",12,1));
    ui->label_8->setFont(QFont("Ink Free",8,1));
    ui->label_6->setFont(QFont("方正粗黑宋简体",12,1));
    ui->spinBox->setRange( 50 , 1000 );
    ui->spinBox->setValue(interval);
    ui->spinBox->setSingleStep(10);
    MyButton * virusBtn = new MyButton(":/i/virus.png");
    virusBtn->setParent(this);
    virusBtn->move( 10 , this->height() - virusBtn->height() - 10 );
    QLabel * lbl = new QLabel;
    lbl->setParent(this);
    lbl->setFixedSize(virusBtn->width() , virusBtn->height() );
    lbl->setFont(QFont("Ink Free",12,1));
    lbl->setText("Virus");
    lbl->move(10 , this->height() - virusBtn->height()   );
    lbl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    MyButton * simuBtn = new MyButton(":/i/simu.png");
    simuBtn->setParent(this);
    simuBtn->move(simuBtn->width()+20 , this->height() - virusBtn->height() - 10);
    QLabel * label = new QLabel;
    label->setParent(this);
    label->setFixedSize(simuBtn->width() ,  virusBtn->height() );
    label->setFont(QFont("Ink Free",12,1));
    label->setText("Simulation");
    label->move(simuBtn->width()+20 , this->height() - virusBtn->height()  );
    label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    label->setAttribute(Qt::WA_TransparentForMouseEvents);
    label->hide();
    simuBtn->hide();
    connect( simuBtn , &MyButton::clicked , [=](){
        int t = 0;
        while( this->simulation(5) < 1000 ) t+=5;
        QString str = QString("约%1天后所有猪都会被感染").arg(t);
        QMessageBox::warning(this,"警告",str);
    });
    connect( virusBtn , &MyButton::clicked , [=](){
        if( this->virus_time == 0 ){
            this->outbreak();
            virusBtn->changePhoto(":/i/virus2.png");
            lbl->setText("Method");
            simuBtn->show();
            label->show();
        }
        else {
            this->method();
            virusBtn->changePhoto(":/i/virus.png");
            lbl->setText("Virus");
            simuBtn->hide();
            label->hide();
        }
    });
    connect( ui->actionsave , &QAction::triggered , this , &Pigfarm::storeInFile );
    connect(ui->actionquit, &QAction::triggered , [=](){
        emit close_mainscene();
        this->close();
    } );
    connect( Farm_Time , &QTimer::timeout , [=]() {
        this->showTime();
        this->showMoney();
        this->grow();
        if( global_t % 90 == 0 && this->virus_time == 0 ){
            this->sellAndBuy();
        }
        if( this->virus_time != 0 ){
            this->simulation(1,true);
        }
        if( this->virus_time == 0 ){
            lbl->setText("Virus");
            simuBtn->hide();
            label->hide();
        }
        else {
            lbl->setText("Method");
            simuBtn->show();
            label->show();
        }
    });
    void(QSpinBox::*ptr)(int) = &QSpinBox::valueChanged;
    connect( ui->spinBox , ptr , this ,  [=](){
       Farm_Time->stop();
       interval = ui->spinBox->value();
       Farm_Time->start(interval);
    });
}

void Pigfarm::showTime()
{
    global_t++;
    this->ui->label_3->setText(QString::number(global_t));
}

void Pigfarm::showMoney()
{
    this->ui->label_5->setText(QString::number(Expense));
    this->ui->label_8->setText(QString::number(Income));
}

void Pigfarm::getAmount()
{
    pigsty tmp = this->Head;
    for( int i = 0 ; i  < 4 ; i++ ){
        this->Amount[i] = 0;
    }
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        for( int j = 0 ; j < 4 ; j++ ){
            this->Amount[j] += tmp->Amount[j];
        }
    }
}

void Pigfarm::sellAndBuy()
{
    pigsty tmp = this->Head;
    if( tmp == nullptr ) qDebug() << "Head is not exist.";
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        tmp->sell();
    }
    int ans = QMessageBox::question(this,"Question","刚刚卖出了一批猪，是否要自动补满？");
    if( ans == QMessageBox::Yes ){
        pigsty tmp = this->Head;
        for( int i = 0 ; i < 100 ; i++ ){
            tmp = tmp->Next;
            tmp->buy();
        }
    }
}

void Pigfarm::grow()
{
    pigsty tmp = this->Head;
    if( tmp->Next == nullptr ) qDebug() << "Head is not exist.";
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        for( int j = 0 ; j < 10 ; j++ ){
            if( tmp->pigs[j].isExist && tmp->pigs[j].beenInfected == 0 )
                tmp->pigs[j].grow();
        }
    }
}

void Pigfarm::outbreak()
{
    int id1 , id2;
    id1 = rand()%100;
    id2 = rand()%10;
    sickPig[id1][id2] = 1;
    a[id1][id2] = 1;
    src_id[0] = id1;
    src_id[1] = id2;
    QFile info(global_file);
    if (!info.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << global_file << "to write.";
        return ;
    }
    QTextStream fout(&info);
    fout << QString("第%1天被感染的猪是第%2猪圈的第%3头猪").arg(global_t).arg(id1).arg(id2) << endl;
    info.close();
    this->virus_time = 1;
}

int Pigfarm::simulation( int period , bool tov )//从a数组对应的当前天开始，再向后数period天
{
    if( tov ){
        for( int i = 0 ; i < 100 ; i++ ){
            for( int j  =0 ; j < 10 ; j++ ){
                a[i][j] = sickPig[i][j];
            }
        }
    }
    int nowaday = 1 , ans = 0;
    //找到数组中最大值，也既瘟疫爆发天数
    for( int i = 0 ; i < 100 ; i++ ){
        for( int j = 0;  j < 10 ; j++ ){
            if( a[i][j] > nowaday ) nowaday = a[i][j];
        }
    }
    int ran1 , ran2; //传染几率 1-同圈 2-邻圈
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
    for( int j = 0 ; j < 10 ; j++ )
        for( int i = 0 ; i < 100 ;i ++ )
            if( a[i][j] ) ans++;
    if( tov ){  //若非模拟，period必为1
        this->virus_time += period;
        QFile info(global_file);
        info.open(QIODevice::WriteOnly | QIODevice::Append );
        QTextStream fout(&info);
        fout << QString("第%1天(病毒爆发第%2天)感染情况").arg(global_t).arg(this->virus_time) << endl;
        for( int j = 0 ; j <  10 ; j++ ){
            for( int i = 0 ; i < 100 ; i++ ){
                sickPig[i][j] = a[i][j];
                fout << QString::number(sickPig[i][j]);
            }
            fout << endl;
        }
        fout << endl;
        info.close();
        this->showVirus();
    }
    return ans;
}

void Pigfarm::showVirus()
{
    pigsty tmp = this->Head;
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        for( int j = 0 ; j < 10 ; j++ ){
            if( sickPig[i][j] ){
                tmp->pigs[j].beenInfected = sickPig[i][j];
                emit tmp->pigs[j].virus_photo();
            }
        }
    }
}

void Pigfarm::method()//图片在这里恢复,数据必须恢复成最初始的样子
{
    pigsty tmp = this->Head;
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        for( int j = 0 ; j < 10 ; j++ ){
            if( tmp->pigs[j].beenInfected ){
                Expense += tmp->pigs[j].deadCost();
                tmp->Amount[0]--;
                tmp->Amount[tmp->pigs[j].Breed]--;
                tmp->pigs[j].kill();
            }
        }
        if( tmp->Amount[0] == 0 ) tmp->isAllBlack = false;
    }
    this->getAmount();
    this->virus_time = 0;
    src_id[0] = src_id[1] = -1;
    for( int i = 0 ; i < 100 ; i++ ){
        for( int j = 0 ; j < 10 ; j++ ){
            a[i][j] = sickPig[i][j] = 0;
        }
    }
}

void Pigfarm::storeInFile()
{
    this->getAmount();
    //存入时间
    QFile day(day_file);
    if (!day.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << day_file << "to write.";
        return ;
    }
    QTextStream dayout(&day);
    dayout << global_t ;
    day.close();

    //存入感染信息
    QFile virus(ill_file);
    if (!virus.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << ill_file << "to write.";
        return ;
    }
    QTextStream vout(&virus);
    vout << src_id[0] << ' ' << src_id[1] << endl ;
    vout << this->virus_time << endl;
    for( int i = 0  ; i < 100 ; i++ ){
        for( int j = 0 ; j < 10 ; j++ ){
            vout << sickPig[i][j] << ' ';
        }
        vout << endl;
    }
    virus.close();

    //存入猪圈信息
    QFile data(data_file);
    if (!data.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << data_file << "to write.";
        return ;
    }
    QTextStream dout(&data);
    //先存全局变量
    dout << Expense << ' ' << Income << endl;
    //再存整个场信息
    dout << this->Amount[0] << ' ' << this->Amount[1] << ' ' << this->Amount[2] << ' ' << this->Amount[3] << ' ' << this->virus_time << endl;
    pigsty tmp = this->Head;
    for( int i = 0 ; i < 100 ; i++ ){
        tmp = tmp->Next;
        dout << tmp->ID << ' ' << tmp->Amount[0] << ' ' << tmp->Amount[1] << ' ' << tmp->Amount[2] << ' ' << tmp->Amount[3] << ' ';
        if( tmp->isAllBlack ) dout << 1 << endl;
        else dout << 0 << endl;
        for( int j = 0 ; j < 10 ; j++ ){
            dout << tmp->pigs[j].StyID << ' ' << tmp->pigs[j].ID << ' '  << tmp->pigs[j].Breed << ' ' << tmp->pigs[j].Weight
                 << ' ' << tmp->pigs[j].FedTime << ' ' ;
            if( tmp->pigs[j].isExist ) dout << 1 << ' ';
            else dout << 0 << ' ';
            if( tmp->pigs[j].beenInfected ) dout << 1 << endl;
            else dout << 0 << endl;
        }
    }
    data.close();
    QMessageBox::information(this,"提示","存档成功");
}

void Pigfarm::paintEvent( QPaintEvent * e )
{
    Q_UNUSED( e );
    QPainter qpainter(this);
    QPixmap qpix;
    qpix.load(":/i/ba.jpeg");                                                  //需要背景图路径
    qpainter.drawPixmap(0,0,this->width(),this->height(),qpix);
}

Pigfarm::~Pigfarm()
{
    delete ui;
}

