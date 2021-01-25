#include "pigsty.h"
#include "ui_pigsty.h"
#include "mybutton.h"
#include "external.h"
#include <QDebug>
#include <QPainter>

Pigsty::Pigsty( int id , QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::Pigsty)
{
    ui->setupUi(this);
    this->ID = id;
    this->initial();
    for( int j = 0 ; j < 4 ; j++ ) this->Amount[j] = 0;
    int breed = rand()%3+1;
    if( breed == 1 ) this->isAllBlack = true;   else this->isAllBlack = false;
    for( int i = 0 ; i < 10 ; i++ ){
        if( !this->isAllBlack ) breed = rand()%2+2;
        this->pigs[i] = Pig(i,this->ID,breed);
        MyButton * pigBtn = new MyButton;
        pigBtn->setParent(this);
        pigBtn->move( 125 + 150*( i%5 ), 300 + 150*(i/5) );
        connect( pigBtn , &MyButton::clicked , [=](){
            pigs[i].showInfo();
        });
        if( breed == 1 ){
            connect( &(this->pigs[i]) , &Pig::virus_photo , [=](){
                pigBtn->changePhoto(":/i/pig121.png");                                //黑猪病图
            } );
            connect( &(this->pigs[i]) , &Pig::normal_photo , [=](){
                pigBtn->changePhoto(":/i/pig12.png");                                //黑猪正常图片
            });
        }
        else if( breed == 2 ){
            connect( &(this->pigs[i]) , &Pig::virus_photo , [=](){
                pigBtn->changePhoto(":/i/pig131.png");                                //白猪病图
            } );
            connect( &(this->pigs[i]) , &Pig::normal_photo , [=](){
                pigBtn->changePhoto(":/i/pig13.png");                                //白猪正常图片
            });
        }
        else if( breed == 3 ){
            connect( &(this->pigs[i]) , &Pig::virus_photo , [=](){
                pigBtn->changePhoto(":/i/pig141.png");                                //花猪病图
            } );
            connect( &(this->pigs[i]) , &Pig::normal_photo , [=](){
                pigBtn->changePhoto(":/i/pig14.png");                                //花猪正常图片
            });
        }
        connect( &(this->pigs[i]) , &Pig::not_exist , [=](){
            pigBtn->changePhoto("");
        });
        emit this->pigs[i].normal_photo();
        this->Amount[this->pigs[i].Breed]++; this->Amount[0]++;
    }
    this->buyThroughWindow();
    this->sellThroughWindow();
}

void Pigsty::buyThroughWindow()
{
    ui->pushButton->setText("买");
    ui->pushButton->setFont(QFont("方正粗黑宋简体",16,1));
    connect( ui->pushButton , &MyButton::clicked , [=](){
       int arg = ui->lineEdit->text().toInt();
       if( arg ){
           ui->lineEdit->clear();
           ui->lineEdit->setText("");
           this->buy(arg);
       }
    });
}

void Pigsty::sellThroughWindow()
{
    ui->pushButton_2->setText("卖");
    ui->pushButton_2->setFont(QFont("方正粗黑宋简体",16,1));
    connect( ui->pushButton_2 , &MyButton::clicked , [=](){
       int arg = ui->lineEdit_2->text().toInt();

       if( arg ){
           ui->lineEdit_2->clear();
           ui->lineEdit_2->setText("");
           this->sell(arg);
       }
    });
}

void Pigsty::buy( int id )
{
    if( id >= 0 && id < 10 ){
        if( pigs[id].isExist ){
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::critical(this,"错误","这里已经有一头猪了");
            return ;
        }
        int breed;
        if( this->Amount[0] == 0 ){
            breed = rand()%3+1;
            if( breed == 1 ) this->isAllBlack = true;
            else this->isAllBlack = false;
        }
        if( !this->isAllBlack )
            breed = rand()%2+2;
        else
            breed = 1;
        Expense += this->pigs[id].buy(breed);
        this->Amount[breed]++;
        //QString str = QString("在%1圈%2号位置购得一只新猪崽").arg(this->ID).arg(id);
        pigs[id].showInfo();
        emit pigs[id].normal_photo();
        //QApplication::setQuitOnLastWindowClosed(false);
        //QMessageBox::information(this,"提示",str);
    }
    else if( id >= 10 ){
        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::critical(this,"错误","你可能输入了错误的编号");
    }
    else{
        int breed;
        if( this->Amount[0] == 0 ){
            breed = rand()%3+1;
            if( breed == 1 ) this->isAllBlack = true;   else this->isAllBlack = false;
        }
        for( int i = 0 ; i < 10 ; i++ ){
            if( !pigs[i].isExist ){
                if( !this->isAllBlack )
                    breed = rand()%2+2;
                else
                    breed = 1;
                Expense += this->pigs[i].buy(breed);
                emit this->pigs[i].normal_photo();
                this->Amount[breed]++;
                this->Amount[0]++;
            }
        }
    }
}

void Pigsty::sell( int id )
{
    if( id >= 0 && id < 10 ){
        if( !pigs[id].isExist ){
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::warning(this,"错误","这里并没有你想要的猪");
            return ;
        }
        if( pigs[id].isQualified() ){
            int bd = this->pigs[id].Breed;
            Income += this->pigs[id].sell();
            this->Amount[0]--;
            this->Amount[bd]--;
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::information(this,"提示","成功");
        }
        else {
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::warning(this,"糟糕","现在卖这头猪似乎有点早");
        }
    }
    else if( id >= 10 ){
        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::warning(this,"错误","你可能输入了错误的编号");
    }
    else{
        for( int i = 0 ; i < 10 ; i++ ){
            if( this->pigs[i].isExist && this->pigs[i].isQualified() ){
                int bd = this->pigs[i].Breed;
                Income += this->pigs[i].sell();
                this->Amount[0]--;
                this->Amount[bd]--;
            }
        }
    }
    if( this->isAllBlack && this->Amount[0] == 0 ) this->isAllBlack = false;
}

void Pigsty::initial()
{
    this->setFixedSize( 1280 , 880 );
    QString str = QString("第 %1 号猪圈").arg(this->ID);
    setWindowTitle(str);
    setWindowIcon(QIcon(":/i/smallWindow.jpeg"));                   //需要窗口小标图片路径
    connect(ui->actionquit, &QAction::triggered , this , &QMainWindow::close );
    MyButton * backBtn = new MyButton(":/i/back.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width() , this->height()-backBtn->height()-20);
    connect( backBtn , &MyButton::clicked ,[=](){
        emit back_to_farm();
    });
    QLabel * lbl = new QLabel;
    lbl->setParent(this);
    lbl->setFixedSize(backBtn->width() , backBtn->height() );
    lbl->setFont(QFont("Ink Free",16,1));
    lbl->setText("Back");
    lbl->move(this->width()-backBtn->width() , this->height()-backBtn->height()-20);
    lbl->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    MyButton * infoBtn = new MyButton(":/i/learnmore.png",":/i/learnmore2.png");
    infoBtn->setParent(this);
    infoBtn->move( this->width() - infoBtn->width() , this->height() - infoBtn->height() - 120 );
    infoBtn->setFont(QFont("方正粗黑宋简体",8,1));
    connect( infoBtn , &MyButton::clicked , this , [=] ( ) {
        this->showInfo();
    });
}

void Pigsty::showInfo()
{
        QString str1 , str2 , str3 , str4;
        str1 = QString("猪圈编号：%1\n共有猪：%2头\n").arg(this->ID).arg(this->Amount[0]);
        if( this->isAllBlack ) str2 = QString("全部为黑猪\n");
        else str2 = QString("白猪:%1头\n花猪:%2头\n").arg(this->Amount[2]).arg(this->Amount[3]);
        str3 = QString("其中符合出售条件的有(编号):");
        str1 = str1 + str2 + str3;
        bool flag = true;
        for( int i = 0 ; i < 10 ; i++ ){
            if( pigs[i].isQualified() ){
                flag = false;
                str4 = QString("%1 ").arg(i);
                str1 += str4;
            }
        }
        if( flag ){
            str4 = QString("无");
            str1 += str4;
        }
        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::information(nullptr, "信息", str1, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
}

void Pigsty::paintEvent( QPaintEvent * e )
{
    Q_UNUSED( e );
    QPainter qpainter(this);
    QPixmap qpix;
    qpix.load(":/i/s.jpeg");                                                  //需要背景图路径
    qpainter.drawPixmap(0,0,this->width(),this->height(),qpix);
}

Pigsty::~Pigsty()
{
    delete ui;
}

