#ifndef BAHRAIN_H
#define BAHRAIN_H

#include <QMainWindow>

class Bahrain : public QMainWindow
{
    Q_OBJECT
public:
    explicit Bahrain(QWidget *parent = nullptr);

 void paintEvent(QPaintEvent*);
signals:
};

#endif // BAHRAIN_H
