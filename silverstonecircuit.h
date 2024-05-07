#ifndef SILVERSTONECIRCUIT_H
#define SILVERSTONECIRCUIT_H

#include <QMainWindow>

class SilverstoneCircuit : public QMainWindow
{
    Q_OBJECT
public:
    explicit SilverstoneCircuit(QWidget *parent = nullptr);

 void paintEvent(QPaintEvent*);
signals:
};

#endif // SILVERSTONECIRCUIT_H
