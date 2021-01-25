#include "mybutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

MyButton::MyButton( QString normalImag , QString pressImag )
{

   //成员变量normalImgPath保存正常显示图片路径
   normalImagPath = normalImag;
   //成员变量pressedImgPath保存按下后显示的图片
   pressedImagPath = pressImag;
   //创建QPixmap对象
   QPixmap pixmap;
   //判断是否能够加载正常显示的图片，若不能提示加载失败
   bool ret = pixmap.load(normalImagPath);
   if(!ret)
   {
       qDebug() << normalImag << "加载图片失败!";
   }
   this->setStyleSheet("QPushButton{text-align : left;}");
   //设置图片的固定尺寸
   this->setFixedSize( pixmap.width(), pixmap.height() );
   //设置不规则图片的样式表
   this->setStyleSheet("QPushButton{border:0px;}");
   //设置图标
   this->setIcon(pixmap);
   //设置图标大小
   this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void MyButton::changePhoto(QString normalImag, QString pressImag)
{
    //成员变量normalImgPath保存正常显示图片路径
    this->normalImagPath = normalImag;
    //成员变量pressedImgPath保存按下后显示的图片
    this->pressedImagPath = pressImag;
    //创建QPixmap对象
    QPixmap pixmap;
    //判断是否能够加载正常显示的图片，若不能提示加载失败
    bool ret = pixmap.load(normalImagPath);
    //设置图片的固定尺寸
    this->setFixedSize( pixmap.width(), pixmap.height() );
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标大小
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void MyButton::mousePressEvent(QMouseEvent *e)
{
   if( this->pressedImagPath != "" )
   {
       //创建QPixmap对象
       QPixmap pixmap;
       //判断是否能够加载正常显示的图片，若不能提示加载失败
       bool ret = pixmap.load(pressedImagPath);
       if(!ret)
       {
           qDebug() << pressedImagPath << "加载图片失败!";
       }
       //设置图片的固定尺寸
       this->setFixedSize( pixmap.width(), pixmap.height() );
       //设置不规则图片的样式表
       this->setStyleSheet("QPushButton{border:0px;}");
       //设置图标
       this->setIcon(pixmap);
       //设置图标大小
       this->setIconSize(QSize(pixmap.width(),pixmap.height()));
   }
   return QPushButton::mousePressEvent(e);
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
   if( pressedImagPath != "" )
   {
       //创建QPixmap对象
       QPixmap pixmap;
       //判断是否能够加载正常显示的图片，若不能提示加载失败
       bool ret = pixmap.load(normalImagPath);
       if(!ret)
       {
           qDebug() << normalImagPath << "加载图片失败!";
       }
       //设置图片的固定尺寸
       this->setFixedSize( pixmap.width(), pixmap.height() );
       //设置不规则图片的样式表
       this->setStyleSheet("QPushButton{border:0px;}");
       //设置图标
       this->setIcon(pixmap);
       //设置图标大小
       this->setIconSize(QSize(pixmap.width(),pixmap.height()));
   }
   //还给父类进行其他操作
   return QPushButton::mouseReleaseEvent(e);
}

void MyButton::zoomUp()
{
   //创建动画对象
   QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
   //设置时间间隔，单位毫秒
   animation1->setDuration(200);
   //创建起始位置
   animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   //创建结束位置
   animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
   //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果    animation1->setEasingCurve(QEasingCurve::OutBounce);
   //开始执行动画
   animation1->start();
}

void MyButton::zoomDown()
{
   //创建动画对象
   QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
   //设置时间间隔，单位毫秒
   animation1->setDuration(200);
   //创建起始位置
   animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
   //创建结束位置
   animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果    animation1->setEasingCurve(QEasingCurve::OutBounce);
   //开始执行动画
   animation1->start();
}
