#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include"chooselevel.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(600,800);
    setWindowIcon(QIcon(":res/max.png"));
    setWindowTitle("f1围场小游戏");//项目起名
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });//实现退出按钮

    QSoundEffect * startSound = new QSoundEffect(this);//创建对象
    startSound->setSource(QUrl::fromLocalFile(":/res/Brian Tyler - Formula 1 Theme.wav.wav"));//添加资源
    startSound->setLoopCount(QSoundEffect::Infinite);//设置循环次数int；  QSoundEffect::Infinite 枚举值 无限循环
    startSound->play();//软件启动自动播放


//开始按钮
    MyPushButton*startBtn=new MyPushButton(":/res/begin.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    chooseScene=new ChooseLevel;//实例化关卡场景

    connect(chooseScene,&ChooseLevel::chooseBack,this,[=](){
        this->setGeometry( chooseScene->geometry());
        chooseScene->hide();
        this->show();
        //实现监听信号返回
    });//只需做一次监听

    connect(startBtn,&MyPushButton::clicked,[=](){

        startBtn->zoom1() ;

        QTimer::singleShot(500,this,[=](){
//设置位置优化
            chooseScene->setGeometry(this->geometry());

            this->hide();//隐藏主页面
            chooseScene->show();//进入到选择关卡

            startSound->stop();

        });//延时0.5秒进入到选择关卡


    });



}

void MainWindow:: paintEvent(QPaintEvent*){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//安放背景
    pix.load(":/res/tit.png");//先加载
    pix=pix.scaled(pix.width(),pix.height()*2);//改变进来的图片的长宽
    painter.drawPixmap(50,50,pix);

};
MainWindow::~MainWindow()
{
    delete ui;
}
