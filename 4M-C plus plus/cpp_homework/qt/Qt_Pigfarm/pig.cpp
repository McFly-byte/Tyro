#include "pig.h"
#include "external.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>
#include <QFile>

Pig::Pig(QObject *parent) : QObject(parent)
{

}

Pig::Pig( int id , int styid , int breed )
{
    this->ID = id;
    this->StyID = styid;
    this->Breed = breed;
    this->FedTime = 0;
    this->Weight = double( rand()%31+20 );
}

/*Pig::Pig( const Pig & p ) : QObject( nullptr )
{
    this->ID = p.ID;
    this->Breed = p.Breed;
    this->Weight = p.Weight;
    this->FedTime = p.FedTime;
    this->isExist = p.isExist;
    this->beenInfected = p.beenInfected;
}*/

Pig & Pig::operator=( const Pig &p )
{
    this->ID = p.ID;
    this->StyID = p.StyID;
    this->Breed = p.Breed;
    this->Weight = p.Weight;
    this->FedTime = p.FedTime;
    this->isExist = p.isExist;
    this->beenInfected = p.beenInfected;
    return *this;
}

void Pig::showInfo()
{
    if( this->isExist ){
            QString str1 , str2 , bd;
            str1 = QString("%1号猪圈的第%2头猪").arg(this->StyID).arg(this->ID);
            if( this->Breed == 1 ) bd = QString("黑猪");
            else if( this->Breed == 2 ) bd = QString("白猪");
            else bd = QString("花猪");
            str2 = QString("品种：%1\n体重：%2\n饲养时间：%3\n").arg(bd).arg(this->Weight).arg(this->FedTime);
            if( this->beenInfected ) bd = QString("感染天数:%1").arg(this->beenInfected);
            else {
                bd = QString("健康");
            }
            str2 += bd;
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::information(nullptr, str1, str2, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
    }
    else {
        QApplication::setQuitOnLastWindowClosed(false);
        QMessageBox::warning(nullptr,"错误","此处并无猪");
    }
}

void Pig::grow()
{
    this->FedTime++;
    this->Weight += (double)(rand()%12)/10.0;
}

double Pig::sell()
{
    QFile file(global_file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << global_file << "to write.";
    }
    QTextStream fout(&file);
    fout << "出售 时间:" << global_t << " 品种:" ;
    if( this->Breed == 1 ) fout << "黑猪";
    else if( this->Breed == 2 ) fout << "白猪";
    else fout << "花猪";
    fout << " 体重:" << this->Weight << " 饲养时长:" << this->FedTime;
    double price = this->Weight * Earn[this->Breed];
    fout << " 收益:" << price << endl;
    this->Weight = 0;
    this->FedTime = 0;
    this->isExist = false;
      file.close();
     emit this->not_exist();
    return price;
}

double Pig::buy( int breed )
{
    QFile file(global_file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Can not open file: " << global_file << "to write.";
    }
    QTextStream fout(&file);
    fout << "购买 时间:" << global_t;
    this->Weight = double( rand()%31+20 );
    this->FedTime = 0;
    this->Breed = breed;
    this->isExist = true;
    double price = this->Weight * Cost[this->Breed];
    fout << "出售 时间:" << global_t << " 品种:" ;
    if( this->Breed == 1 ) fout << "黑猪";
    else if( this->Breed == 2 ) fout << "白猪";
    else fout << "花猪";
    fout << " 体重:" << this->Weight << " 饲养时长:" << this->FedTime << " 花费:" << price << endl;
    file.close();
    emit this->normal_photo();
    return price;
}

bool Pig::isQualified()
{
    return ( (this->Weight >= standard_weight) || (this->FedTime >= standard_time) );
}

double Pig::deadCost()
{
    return this->Weight * this->beenInfected;
}

void Pig::kill()
{
    this->isExist = false;
    this->Weight = 0;
    this->FedTime = 0;
    this->beenInfected = 0;
    emit this->not_exist();
}
