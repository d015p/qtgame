#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QMainWindow>
#include"silverstonecircuit.h"
#include"shanghai.h"
#include"bahrain.h"

class ChooseLevel : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevel(QWidget *parent = nullptr);
//重写绘图事件
    void paintEvent(QPaintEvent*);
    SilverstoneCircuit*ssc=NULL;
    Shanghai*shc=NULL;
    Bahrain*bc=NULL;


signals://写一个自定义信号，告诉主场景
    void chooseBack();
};

#endif // CHOOSELEVEL_H
