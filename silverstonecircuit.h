#ifndef SILVERSTONECIRCUIT_H
#define SILVERSTONECIRCUIT_H

#include <QMainWindow>
#include "gamemap.h"
#include "role.h"

class SilverstoneCircuit : public QMainWindow
{
    Q_OBJECT
public:
    explicit SilverstoneCircuit(QWidget *parent = nullptr);  
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
 void chooseBack();
};

#endif // SILVERSTONECIRCUIT_H
