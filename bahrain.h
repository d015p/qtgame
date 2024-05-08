#ifndef BAHRAIN_H
#define BAHRAIN_H

#include <QMainWindow>
#include "gamemap.h"
#include "role.h"
class Bahrain : public QMainWindow
{
    Q_OBJECT
public:
    explicit Bahrain(QWidget *parent = nullptr);
void DrawMap(int x,int y);//画地图
    virtual void paintEvent(QPaintEvent* event);//绘图事件函数
    virtual void keyPressEvent(QKeyEvent* event);//键盘按下事件
    void Collision(int _dRow,int _dCol);//检测碰撞函数
    GameMap* mPMap;

    //画家
    QPainter* mMapPainter;

    //角色
    Role* mRole;
    //游戏更新定时器
    QTimer* mTimer;

signals:
 void chooseBack();//发送自定义信号
};

#endif // BAHRAIN_H
