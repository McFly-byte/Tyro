#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    QString normalImagPath;  //默认显示图片路径
    QString pressedImagPath; //按下后显示图片路径

    explicit MyButton(QWidget *parent = nullptr);       //构造按钮
    MyButton( QString normalImag , QString pressImag="" );//析构按钮
    void changePhoto( QString normalImag , QString pressImag="" );//切换图片
    void zoomUp();//跳
    void zoomDown();//跳
    void mousePressEvent( QMouseEvent * e );    //重写按下事件
    void mouseReleaseEvent( QMouseEvent * e );  //重写释放事件
signals:
public slots:
};

#endif // MYBUTTON_H
