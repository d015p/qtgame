#ifndef SHANGHAI_H
#define SHANGHAI_H

#include <QMainWindow>

class Shanghai : public QMainWindow
{
    Q_OBJECT
public:
    explicit Shanghai(QWidget *parent = nullptr);
 void paintEvent(QPaintEvent*);
signals:
};

#endif // SHANGHAI_H
