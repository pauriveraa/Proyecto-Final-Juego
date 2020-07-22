#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define GRAV 10
#define TIME 0.1
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "crear.h"
#include "graficar.h"
#include<stdlib.h>
#include<time.h>
#include "objetocircular.h"
#include "objetocuadrado.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actualizar();
    bool objColision(crear *b, crear *b2);
    void nivelN();
    void mover();
     void posicion();

    void on_pushButton_clicked();

    void on_potencia_valueChanged(int value);

    void on_angulo_valueChanged(int value);

    void on_reiniciar_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    float puntaje=0;
    float t;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int nivel;
    int prueba=0;
    int angulo; //value
    int potencia; //value
    void bordercollision(crear *b);   //metodo para las colisiones con los bordes del mundo
    graficar*parabolico; //circulo a lanzar con tiro parabolico
    graficar*objetivo;  //circulo objetivo
    circulo *obstaculo2; //obstaculo con trayectoria circular
    cuadrado *obstaculo1; //obstaculo cuadrado
    float rad;//Ángulo(radianes)
    float x,y,i;
    //Datos del circulo con trayectoria de un pendulo
    double x1_obstaculo3;
    double x2_obstaculo3;
    double y1_obstaculo3;
    double y2_obstaculo3;
    double radio1_obstaculo3;
    double radio2_obstaculo3;
    double magnitud;
    QGraphicsEllipseItem *obstaculo3;
    QPen pen;
    bool colision;
    bool collide;
    bool collide2;
    QMessageBox msgBox;
    int contdisparos=12;
    bool bandera1=true;
    int auxiliar=0;

};

#endif // MAINWINDOW_H

