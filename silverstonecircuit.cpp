#include "silverstonecircuit.h"
#include<QPainter>
SilverstoneCircuit::SilverstoneCircuit(QWidget *parent)
    : QMainWindow{parent}
{

    this->setFixedSize(600,800);//配置选择关卡页面
    setWindowIcon(QIcon(":res/lecao.png"));
    setWindowTitle("银石赛道");//项目起名
}

void SilverstoneCircuit::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res1/eachteam.png.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//安放背景
    pix.load(":/res/tit.png");//先加载
    pix=pix.scaled(pix.width(),pix.height()*2);//改变进来的图片的长宽
    painter.drawPixmap(70,50,pix);

};
