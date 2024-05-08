#include "chooselevel.h"
#include<QMenuBar>
#include<QPainter>
#include<QTimer>
#include"mypushbutton.h"
ChooseLevel::ChooseLevel(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(600,800);//配置选择关卡页面
    setWindowIcon(QIcon(":res/laohan.png"));
    setWindowTitle("选择关卡");//项目起名
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("start");
    //创建退出 菜单项
    QAction *quitAction = startMenu->addAction("quit");//点击退出实现退出游戏
    connect (quitAction, &QAction::triggered, [=](){
        this->close();
    }   );
//返回按钮
    MyPushButton*backBtn=new MyPushButton(":/res/return.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //发送一个信号，主场景监听接收这个信号
    connect(backBtn,&MyPushButton::clicked,[=](){

        backBtn->zoom1() ;
        QTimer::singleShot(500,this,[=](){
             emit this->chooseBack();
        });//延时0.5秒返回主场景
    });

    MyPushButton * menuBtn1 = new MyPushButton(":/res/ba.png");
    menuBtn1->setParent(this);
menuBtn1->move(this->width()*0.5-menuBtn1->width()*0.5,this->height()*0.3-menuBtn1->height()*0.5);

    MyPushButton * menuBtn2 = new MyPushButton(":/res/yin2.png");
    menuBtn2->setParent(this);
    menuBtn2->move(this->width()*0.5-menuBtn2->width()*0.5,this->height()*0.5-menuBtn2->height()*0.5);

    MyPushButton * menuBtn3 = new MyPushButton(":/res/ao.png");
    menuBtn3->setParent(this);
    menuBtn3->move(this->width()*0.5-menuBtn3->width()*0.5,this->height()*0.71-menuBtn3->height()*0.5);

//实例化三个关卡
    ssc=new SilverstoneCircuit;
    shc=new Shanghai;
    bc=new Bahrain;
connect(menuBtn1,&MyPushButton::clicked,[=](){

    menuBtn1->zoom1() ;
    QTimer::singleShot(500,this,[=](){
        this->hide();//隐藏页面

        bc->show();//进入到选择关卡

        connect(bc,&Bahrain::chooseBack,[=](){
            this->show();
            bc->hide();
        });



    });//延时0.5秒到场景
});

connect(menuBtn2,&MyPushButton::clicked,[=](){

        menuBtn2->zoom1() ;
        QTimer::singleShot(500,this,[=](){
            this->hide();//隐藏页面
            ssc->show();//进入到选择关卡

            connect(ssc,&SilverstoneCircuit::chooseBack,[=](){
                this->show();
                ssc->hide();
            });



        });//延时0.5秒到场景
    });
connect(menuBtn3,&MyPushButton::clicked,[=](){

    menuBtn3->zoom1() ;
    QTimer::singleShot(500,this,[=](){
        this->hide();//隐藏页面
        shc->show();//进入到选择关卡

        connect(shc,&Shanghai::chooseBack,[=](){
            this->show();
            shc->hide();
        });

    });//延时0.5秒到场景
});

}

void ChooseLevel::paintEvent(QPaintEvent*)
    {

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res1/eachteam.png.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//安放背景
    pix.load(":/res/tit.png");//先加载
    pix=pix.scaled(pix.width(),pix.height()*2);//改变进来的图片的长宽
    painter.drawPixmap(70,50,pix);

};
