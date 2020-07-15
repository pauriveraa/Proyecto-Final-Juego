#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#define GRAV 10
#define TIME 0.1
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include<stdlib.h>
#include<time.h>
#include "obstaculocuadrado.h"
#include "mas.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    cuadrado *obstaculo1;
    pendulo *obstaculo2;
};
#endif // MAINWINDOW_H
