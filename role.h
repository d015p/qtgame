#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include <QPoint>
#include <QImage>

class Role : public QObject
{
    Q_OBJECT
public:
    explicit Role(QObject *parent = nullptr);

    //对应在地图的映射行列
    int mRow;
    int mCol;
    //画图位置
    QPoint mPaintPos;
    //人物图片
    QImage mImg;

    void Move(int _dRow,int _dCol);//移动函数
    void Paint(QPainter* _p,QPoint _pos);//自己的绘制函数

signals:

public slots:
};

#endif // ROLE_H
