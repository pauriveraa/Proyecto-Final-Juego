#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(this);         //crea la pestaña
    this->setGeometry(0,0,1800,800);
    scene->setSceneRect(0,0,1800,800);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(0,0,1800,800);
    qDebug()<<ui->graphicsView->size();


    obstaculo1 = new cuadrado;
    //obstaculo1->valores(400,400,50,50);
    scene->addItem(obstaculo1);


    obstaculo2= new pendulo;
    scene->addItem(obstaculo2);




}

MainWindow::~MainWindow()
{
    delete ui;
}

