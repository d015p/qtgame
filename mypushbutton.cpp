#include "mypushbutton.h"        //自定义按钮控件
#include<QDebug>
#include<QPropertyAnimation>
// MyPushButton::MyPushButton(QWidget *parent)
//     : QPushButton{parent}
// {}
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{

    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret){

        qDebug()<<"图片加载失败";
        return;

    }

    this->setFixedSize(pix.width(),pix.height());//设置图片固定大小

    this->setStyleSheet("QPushButton{border:0px;}");//不规则图片样式（0边像素）

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小


}

void MyPushButton::zoom1()
    {//创建可动对象
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
        animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//结束位置

    animation->setEasingCurve(QEasingCurve::OutCurve);//弹跳曲线

    animation->start();//执行动画
};//向下跳
void MyPushButton::zoom2(){
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//结束位置

    animation->setEasingCurve(QEasingCurve::OutCurve);//弹跳曲线

    animation->start();//执行动画

};//向上跳
