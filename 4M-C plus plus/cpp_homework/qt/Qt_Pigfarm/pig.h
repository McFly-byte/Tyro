#ifndef PIG_H
#define PIG_H

#include <QObject>
#include <QMessageBox>

class Pig : public QObject
{
    Q_OBJECT
public:
    int ID;                     //编号
    int StyID;                  //所在猪圈编号
    int Breed;                  //品种 1-黑，2-白，3-花
    int FedTime;                //饲养时长
    double Weight;              //体重
    bool isExist = true;        //是否有实例
    int beenInfected = 0;       //已被感染天数，未感染为零

    explicit Pig(QObject *parent = nullptr);//构造函数
    Pig( int id , int styid , int breed );//根据编号构造猪
    Pig( const Pig & p );//复制构造函数
    bool isQualified();//判断是否达到出售标准
    void showInfo();//显示该猪信息
    void grow();//实现猪的单日增长
    double sell();//卖这头猪，返回收入
    double buy( int breed = 0 );//买一头猪，返回支出
    void kill();//杀死一头猪
    double deadCost();//一头猪死亡耗费的钱
    Pig & operator=( const Pig & p );//重载等号

signals:
    void virus_photo();
    void normal_photo();
    void not_exist();

public slots:
};
typedef Pig * pig;

#endif // PIG_H
