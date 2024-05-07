#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QPushButton>
#include <QWidget>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg,QString pressImg="");//正常显示，按下显示
    QString normalImgPath;
    QString pressImgPath;

    //设置按钮弹跳效果
    void zoom1();//向下跳
    void zoom2();//向上跳


signals:
};

#endif // MYPUSHBUTTON_H
