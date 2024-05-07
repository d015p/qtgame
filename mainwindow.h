#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"chooselevel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent*);//重新paintevent事件，画背景图

    ChooseLevel*chooseScene=NULL;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
