#include "shanghai.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include<QDebug>

Shanghai::Shanghai(QWidget *parent)
    : QMainWindow{parent}
{

    this->setFixedSize(600,800);//配置选择关卡页面
    setWindowIcon(QIcon(":res/laohan.png"));
    setWindowTitle("奥地利红牛赛道");//项目起名


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

    //初始化地图元素
    mPMap = new GameMap(this);
    //QString fileName =QFileDialog::getOpenFileName(this,"打开地图","./","*.txt");

    if(!mPMap->InitByFile("./MAP/map1.txt"))
    {
        QMessageBox::warning(this,"警告","文件打开失败");
    }


    mMapPainter = new QPainter(this);//创建画家
    mRole = new Role(this);//创建人物
    mTimer = new QTimer(this);//创建定时器使得实时更新
    mTimer->start(100);//更新速度
    //定时调用更新函数
    connect(mTimer,&QTimer::timeout,[this](){this->update();});


}

//实现地图的搭建,读入文件的地图编码，实现画图渲染
void Shanghai::DrawMap(int x,int y)
{
    for(int i = 0;i < mPMap->mRow;i++)
    {
        for(int j = 0;j < mPMap->mCol;j++)
        {
            QString imgUrl;
            switch (mPMap->mPArr[i][j])
            {
            case Road: imgUrl = "";break;
            case Wall: imgUrl = ":/res/lwall.png";break;
            case Box: imgUrl = ":/res/lun.png";break;
            case Point: imgUrl = ":/res/change.png";break;
            case InPoint: imgUrl = ":/res/jiang.png";break;
            }
            QImage img(imgUrl);
            mMapPainter->drawImage(QRect(x + j*img.width(),y +i*img.height(),img.width(),img.height()),img);
        }
    }
}

void Shanghai::paintEvent(QPaintEvent*)
{

    mMapPainter->begin(this);//设置画布

    //画背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//安放背景
    pix.load(":/res/tit.png");//先加载
    pix=pix.scaled(pix.width(),pix.height()*2);//改变进来的图片的长宽
    painter.drawPixmap(70,50,pix);
    //画地图
    DrawMap(50,300);
    //画人物
    mRole->Paint(mMapPainter,QPoint(50,300));
    mMapPainter->end();//结束
};
//键盘事件
void Shanghai::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_W:
    case Qt::Key_Up:
    {
        //逻辑碰撞检测函数
        Collision(-1,0);
        break;
    }
    case Qt::Key_S:
    case Qt::Key_Down:
    {
        //逻辑碰撞检测函数
        Collision(1,0);
        break;
    }
    case Qt::Key_A:
    case Qt::Key_Left:
    {
        //逻辑碰撞检测函数
        Collision(0,-1);
        break;
    }
    case Qt::Key_D:
    case Qt::Key_Right:
    {
        //逻辑碰撞检测函数
        Collision(0,1);
        break;
    }

    }
}
//碰撞函数逻辑实现
void Shanghai::Collision(int _dRow,int _dCol)//向量移动
{
    //判断位置定义
    int newRow = mRole->mRow + _dRow;
    int newCol = mRole->mCol + _dCol;

    if(mPMap->mPArr[newRow][newCol] == Wall)//判断前方是墙
    {
        return;
    }
    else if(mPMap->mPArr[newRow][newCol] == Box)//判断前方是箱子
    {
        //判断箱子前方
        if(mPMap->mPArr[newRow+_dRow][newCol + _dCol] == Road)
        {
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol + _dCol] = Box;//箱子前方变成箱子
            mPMap->mPArr[newRow][newCol] = Road;//箱子之前在的地方变成了路

        }
        else if(mPMap->mPArr[newRow+_dRow][newCol + _dCol] == Point)//判断操作前方是目标点
        {
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol + _dCol] = InPoint;//箱子前方变成进目标点
            mPMap->mPArr[newRow][newCol] = Road;
        }
        else
        {
            return;//无法推动箱子
        }
    }
    else if(mPMap->mPArr[newRow][newCol] == InPoint)//前方是进目标点（箱子与目标重合）
    {
        //判断目标点前方
        if(mPMap->mPArr[newRow+_dRow][newCol + _dCol] == Road)
        {
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol + _dCol] = Box;//目标点前方变成箱子
            mPMap->mPArr[newRow][newCol] = Point;

        }
        else if(mPMap->mPArr[newRow+_dRow][newCol + _dCol] == Point)
        {
            //改变地图元素
            mPMap->mPArr[newRow+_dRow][newCol + _dCol] = InPoint;//箱子进点
            mPMap->mPArr[newRow][newCol] = Point;
        }
        else
        {
            return;//无法推动箱子
        }

    }                                 //操作之后更新图标位置update

    //否则移动
    mRole->Move(_dRow,_dCol);

    qDebug() << "人物绘制位置：" << mRole->mPaintPos;
}
