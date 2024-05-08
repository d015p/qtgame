#include "role.h"
#include <QPainter>

Role::Role(QObject *parent) : QObject(parent)
{
    mRow = 1;
    mCol = 1;
    mImg = QImage(":/res/role1.png");

    //显示位置
    mPaintPos = QPoint(mCol,mRow) * mImg.height();

}

void Role::Move(int _dRow,int _dCol)
{
    mRow += _dRow;
    mCol += _dCol;

    mPaintPos = QPoint(mCol,mRow) * mImg.height();

}

void Role::Paint(QPainter* _p,QPoint _pos)
{
    _p->drawImage(mPaintPos + _pos,mImg);

}
