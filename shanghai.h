#ifndef SHANGHAI_H
#define SHANGHAI_H

#include <QMainWindow>
#include "gamemap.h"
#include "role.h"
#include <QSoundEffect>//音频类
class Shanghai : public QMainWindow
{
    Q_OBJECT
public:
    explicit Shanghai(QWidget *parent = nullptr);
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
    //判断是否胜利
    bool isWin=false;

signals:
 void chooseBack();
};

#endif // SHANGHAI_H
