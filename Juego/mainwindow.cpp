#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QtWidgets>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <QString>
#include <QtGui>
#include <QImage>
#include <QSound>
#include <QGraphicsPixmapItem>// para item:V pues colocar anuncio o texto
#include <QObject>
using namespace std;


QSound *Cancion=new QSound("C:../versión 13/juego/audio/tetriz.wav");
QSound *Cancion2=new QSound("C:../versión 13/juego/audio/disparador.wav");
QSound *Cancion3=new QSound("C:../versión 13/juego/audio/contrapared.wav");
QSound *Cancion4=new QSound("C:../versión 13/juego/audio/punto.wav");
QSound *Cancion5=new QSound("C:../versión 13/juego/audio/boton.wav");
QSound *Cancion6=new QSound("C:../versión 13/juego/audio/mundo22.wav");
QSound *Cancion7=new QSound("C:../Versión 13/juego/audio/tetriz.wav");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x=y=i=10; //Datos para cambiar posición del circulo
    rad=0.01745329252;
    potencia=0; //value de potencia
    t=0.01; //"tiempo"
    h_limit=900; //Limites del graphicsview
    v_limit=300;
    nivel=1; //contadorpara determinar los niveles

    string a;
    Cancion->setLoops(10); // Se repite 10 veces la cancion
    Cancion->play();


///////////////////////Arduino, si se logra implementar//////////////////////////////////
//    serial= new QSerialPort();
//    arduino_available = false;

//    foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()) {
//        qDebug()<<"puerto:"<<serial_Info.portName();
//        portname = serial_Info.portName();
//        qDebug() << "vendor iD"<<serial_Info.vendorIdentifier();
//        vendorId=serial_Info.vendorIdentifier();
//        qDebug() <<"product id"<<serial_Info.productIdentifier();
//        productId=serial_Info.productIdentifier();
//        arduino_available=true;
////////////////////////////Tiempos (temporizadores) y escena///////////////////////////////////////////////

    timer=new QTimer(this);                 //crea el timer
    timer2=new QTimer(this);
    timer3=new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(120,100,250,120);
    scene->setBackgroundBrush(QImage("C:../versión 13/juego/audio/c.png"));
    // Set del retangulo de la escena con los parametros (x,y,ancho,alto)
    scene->setBackgroundBrush(QImage("C:../versión 13/juego/audio/c.png"));
    ui->graphicsView->setScene(scene);
    this->resize(640, 480);
    setFixedSize(650,450);// ancho y altura del mainwindow mas no de la view
    qDebug()<<this->size();

////////////////////////////objetivo//////////////////////////////////////////////////////

    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
    objetivo->actualizar(t,v_limit);
    scene->addItem(objetivo);


//////////////////Agrego un lcd para mostrar puntaje y contador de disparos////////////////////

     ui->lcdNumber->display(puntaje);
     ui->lcdNumber_2->display(contdisparos);
     ui->lcdNumber_2->hide();

/////////////////////////////pendulo//////////////////////////////////////////////////////

     QBrush brush(Qt::black); //pintar el objeto
     x1_obstaculo3 = 200.0;
     y1_obstaculo3 = 0.0;
     x2_obstaculo3 = 0.0;
     y2_obstaculo3 = 0.0;
     radio1_obstaculo3 = 15.0;
     radio2_obstaculo3 = 15.0;
     obstaculo3 = scene->addEllipse(x1_obstaculo3+200,  y1_obstaculo3,radio1_obstaculo3, radio2_obstaculo3, pen, brush);
     magnitud = sqrt(pow(x1_obstaculo3 - x2_obstaculo3, 2.0)+ pow(y1_obstaculo3 - y2_obstaculo3, 2.0));
     connect(timer3,SIGNAL(timeout()),this,SLOT(mover()));
     timer3->start(20);


//////////////////////////////////Bolita tiro parabolico///////////////////////////////////


    parabolico=new graficar(10,10,10,0,0,30,0.5,0.01);
    parabolico->actualizar(t,v_limit);
    scene->addItem(parabolico);
    timer->stop();                              //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

////////////////////////////objeto trayectoria circular ///////////////////////////////////

    obstaculo2 = new circulo;
    //scene->addItem(obstaculo2);
    timer2->start(4);
    timer2->stop();
    //connect(timer2,SIGNAL(timeout()),this,SLOT(posicion()));


////////////////////////////////objeto cuadrado/////////////////////////////////////////////

    obstaculo1 = new cuadrado;
    //obstaculo1->valores(230,240,20,20);
    //scene->addItem(obstaculo1);

/////////////////////Dejo de mostrar esto en el mainwindow con .hide()/////////////////////////

    ui->graphicsView->hide();
    ui->lcdNumber->hide();
    //ui->vida->hide();
    ui->pushButton->hide();
    ui->reiniciar->hide();
    ui->potencia->hide();
    ui->angulo->hide();
    ui->labelnombre->hide();
    ui->label_fondo->show();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lcdNumber_3->hide();
    ui->label_4->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->lineEdit->hide();
    ui->label_5JUGADOR1->hide();
    ui->label_6JUGADOR2->hide();
    ui->REGISTRARVS->hide();
    ui->lineEdit_2JUGADOR1->hide();
    ui->lineEdit_3JUGADOR2->hide();
    ui->disparovs->hide();
    ui->lcdNumber_5puntaj2->hide();
    ui->lcdNumber_4puntaje1->hide();
    ui->contavs->hide();
    ui->contanivel->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
    bordercollision(parabolico->getEsf());
    parabolico->actualizar(t,v_limit);
    nivelN();
}

bool MainWindow::objColision(crear *b, crear *b2) //Recibo el objeto 1 y 2 para analizarlos si hay colis
{
    if(sqrt(((b->getX()-b2->getX())*((b->getX())-b2->getX()))+((b->getY()-b2->getY())*(b->getY()-b2->getY())))<= b->getR()+b2->getR())
        return true;
    return false;
}

void MainWindow::nivelN()
{
    //Detectar colisión entre objeto a lanzar y objetivo para pasar los niveles
    if(banderaverificadorvs==0 &&objColision(parabolico->getEsf(), objetivo->getEsf())==true)
    {
        contdisparos++;
        Cancion4->play();
        puntaje=puntaje+100;
        nivel++;
        delete objetivo;
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(nivel==2)
        {
             objetivo=new graficar(400,50, 30, 0,0,50,0.5,0);
             objetivo->actualizar(t,v_limit);
             scene->addItem(objetivo);
             ui->lcdNumber->display(puntaje);
        }

        if(nivel==3)
        {
            objetivo=new graficar(400,150, 30, 0,0,50,0.5,0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            ui->lcdNumber->display(puntaje);
        }
        if(nivel==4)
        {
            objetivo=new graficar(350,100, 25, 0,0,50,1,0);
            objetivo->getEsf()->setVel(0, 0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            ui->lcdNumber->display(puntaje);
        }
        if(nivel==5)
        {
           ui->lcdNumber->display(puntaje);
           controldemundos++;
           if(nivel==5&&controldemundos==4)
           {
               msgBox.setText("YOU WIN TERMINASTE");
               msgBox.setInformativeText("");
               msgBox.exec();
               close();
           }
           objetivo=new graficar(420,100, 30, 0,0,50,0,0);
           objetivo->getEsf()->setVel(0, 0);
           objetivo->actualizar(t,v_limit);
           scene->addItem(objetivo);
           if(controldemundos!=4)
           {
               msgBox.setText("Pasaste al siguiente nivel");
               msgBox.setInformativeText("");
               msgBox.exec();
               ui->lcdNumber_3->display(controldemundos);
           }
           obstaculo1->valores(230,240,20,20);
           scene->addItem(obstaculo1);
           nivel=1;
           if(controldemundos==3)
           {
               scene->addItem(obstaculo2);
               timer2->start(12);
               connect(timer2,SIGNAL(timeout()),this,SLOT(posicion()));

           }
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////

    if(banderaverificadorvs==1 &&objColision(parabolico->getEsf(), objetivo->getEsf())==true)
    {
        Cancion4->play();
        delete objetivo;
        if(terminacion==1)
        {
            terminacion=0;
            contdisparos1=3;
            banderajugador2=1;
            ui->contavs->display(contdisparos1);
            objetivo= new graficar(420,100, 30, 0,0,50,0,0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            puntaje1=puntaje1+100;
            puntaje2=puntaje2-100;

        }
        if(terminacion==2)
        {
            contdisparos1++;
            puntaje2=puntaje2+100;
            objetivo= new graficar(420,100, 30, 0,0,50,0,0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            if(puntaje1<puntaje2)
            {
                msgBox.setText("GANADOR JUGADOR 2");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(puntaje1>puntaje2)
            {
                msgBox.setText("GANADOR JUGADOR 1");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(puntaje1==puntaje2)
            {
                msgBox.setText("EMPATADOS");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }

        }
        if(banderajugador2==0)
        {
        contdisparos1++;
        puntaje1=puntaje1+100;
        }
        if(banderajugador2==1)
        {
            contdisparos1++;
            puntaje2=puntaje2+100;
        }
        ui->lcdNumber_5puntaj2->display(puntaje2);
        ui->lcdNumber_4puntaje1->display(puntaje1);
        nivel1++;
        ui->contavs->display(contdisparos1);
        ui->contanivel->display(nivel1);
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(nivel1==2)
        {
            objetivo=new graficar(400,50, 30, 0,0,50,0.5,0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            ui->contavs->display(contdisparos1);
            ui->contanivel->display(nivel1);
        }
        if(nivel1==3)
        {
            objetivo=new graficar(400,150, 30, 0,0,50,0.5,0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            ui->contavs->display(contdisparos1);
            ui->contanivel->display(nivel1);
        }
        if(nivel1==4)
        {
            objetivo=new graficar(350,100, 25, 0,0,50,1,0);
            objetivo->getEsf()->setVel(0, 0);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            ui->contanivel->display(nivel1);
            nivel1=0;
            terminacion=1;
            if(banderajugador2==1)
            {
                terminacion=2;
                qDebug()<<terminacion;
            }
            if(contdisparos1==0)
            {
                contdisparos1=4;
            }
            ui->contavs->display(contdisparos1);
        }
    }

/////////////////////////////////////////////////////////////////////////////////

    ui->lcdNumber_2->display(contdisparos);

 //////////////////////Colision con cuadrado///////////////////////////

    collide=parabolico->collidesWithItem(obstaculo1);
    if(collide==true)
    {
        Cancion3->play();
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0||contdisparos1==0)
        {
            auxiliar= auxiliar+1;
            if(contdisparos==0 && auxiliar ==2)
            {
                timer->stop();
                msgBox.setText("YOU LOSE murito");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(contdisparos1==0&&auxiliar==2)
            {
                if(banderajugador2==0)
                {
                    msgBox.setText("TURNO JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    contdisparos1=4;//recargar
                    ui->contavs->display(contdisparos1);
                    banderajugador2=1;
                    nivel1=1;
                    terminacion=0;
                    delete objetivo;
                    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                    objetivo->actualizar(t,v_limit);
                    scene->addItem(objetivo);
                }
                if(banderajugador2==1 && puntaje1<puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1>puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 1");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1==puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("EMPATADOS");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
            }
        }
    }

 ///////////////////////////////Colision con pendulo//////////////////

    collide=parabolico->collidesWithItem(obstaculo3);
    if(collide==true)
    {
        Cancion3->play();
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0||contdisparos1==0)
        {
            auxiliar= auxiliar+1;
            if(contdisparos==0 && auxiliar ==2)
            {
                timer->stop();
                msgBox.setText("YOU LOSE pendulo");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(contdisparos1==0&&auxiliar==2)
            {
                if(banderajugador2==0)
                {
                    msgBox.setText("TURNO JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    contdisparos1=4;//recargar
                    ui->contavs->display(contdisparos1);
                    banderajugador2=1;
                    nivel1=1;
                    terminacion=0;
                    delete objetivo;
                    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                    objetivo->actualizar(t,v_limit);
                    scene->addItem(objetivo);
                }
                if(banderajugador2==1 && puntaje1<puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1>puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 1");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1==puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("EMPATADOS");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
            }
        }
    }

////////////////////////Colison con objeto circular ///////////////////////////////

    collide=parabolico->collidesWithItem(obstaculo2);
    if(collide==true)
    {
        Cancion3->play();
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0||contdisparos1==0)
        {
            auxiliar= auxiliar+1;
            if(contdisparos==0 && auxiliar ==2)
            {
                timer->stop();
                msgBox.setText("YOU LOSE orbita");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();

            }
            if(contdisparos1==0&&auxiliar==2)
            {
                if(banderajugador2==0)
                {
                    msgBox.setText("TURNO JUGADOR 2");
                    msgBox.exec();
                    contdisparos1=4;
                    ui->contavs->display(contdisparos1);
                    banderajugador2=1;
                    nivel1=1;
                    terminacion=0;
                    delete objetivo;
                    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                    objetivo->actualizar(t,v_limit);
                    scene->addItem(objetivo);
                }

                if(banderajugador2==1 && puntaje1<puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1>puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 1");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1==puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("EMPATADOS");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }

            }



        }
    }
}

/////////////////////////////Colisión con los bordes///////////////////////////////////

void MainWindow::bordercollision(crear *b)
{
    if(b->getX()<= b->getR())
    {
        b->setVel(-b->getcRest()*b->getVx(),b->getVy());
        b->setPoint(b->getR(),b->getY());
    }
    else if(b->getX()>=h_limit-b->getR())
    { //Si colisiona con el borde
        parabolico->getEsf()->setPoint(10,10); //UBICO EN LA POSICION INICIAL
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0||contdisparos1==0)
        {
            auxiliar= auxiliar+1;
            if(contdisparos==0 && auxiliar ==2)
            {
                timer->stop();
                msgBox.setText("YOU LOSE muroderecha");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(contdisparos1==0&&auxiliar==2)
            {
                if(banderajugador2==0)
                {
                    msgBox.setText("TURNO JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    contdisparos1=4;
                    ui->contavs->display(contdisparos1);
                    banderajugador2=1;
                    nivel1=1;
                    terminacion=0;
                    delete objetivo;
                    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                    objetivo->actualizar(t,v_limit);
                    scene->addItem(objetivo);
                }
                if(banderajugador2==1 && puntaje1<puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 2");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();                                                              }
                if(banderajugador2==1 && puntaje1>puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("GANADOR JUGADOR 1");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }
                if(banderajugador2==1 && puntaje1==puntaje2&&contdisparos1==0)
                {
                    msgBox.setText("EMPATADOS");
                    msgBox.setInformativeText("");
                    msgBox.exec();
                    close();
                }

             }
      }
}

    if(b->getY()<=b->getR()) // limite inferior
    {
        b->setVel(b->getVx(),-b->getcRest()*b->getVy());
        b->setPoint(b->getX(),b->getR());
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0||contdisparos1==0)
        {
            auxiliar= auxiliar+1;
            if(contdisparos==0 && auxiliar ==2)
            {
                timer->stop();
                msgBox.setText("YOU LOSE muroabajo");
                msgBox.setInformativeText("");
                msgBox.exec();
                close();
            }
            if(contdisparos1==0&&auxiliar==2)
            {
                if(banderajugador2==0)
                {
                     msgBox.setText("TURNO JUGAADOR 2");
                     msgBox.setInformativeText("");
                     msgBox.exec();
                     contdisparos1=4;
                     ui->contavs->display(contdisparos1);
                     banderajugador2=1;
                     nivel1=1;
                     terminacion=0;
                     delete objetivo;
                     objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                     objetivo->actualizar(t,v_limit);
                     scene->addItem(objetivo);
                }

                if(banderajugador2==1 && puntaje1<puntaje2&&contdisparos1==0)
                {
                     msgBox.setText("GANADOR JUGADOR 2");
                     msgBox.setInformativeText("");
                     msgBox.exec();
                     close();
                }
                if(banderajugador2==1 && puntaje1>puntaje2&&contdisparos1==0)
                {
                     msgBox.setText("GANADOR JUGADOR 1");
                     msgBox.setInformativeText("");
                     msgBox.exec();
                     close();
                }
                if(banderajugador2==1 && puntaje1==puntaje2&&contdisparos1==0)
                {
                     msgBox.setText("EMPATADOS");
                     msgBox.setInformativeText("");
                     msgBox.exec();
                     close();
                }
            }
        }
    }
    else if(b->getY()>=v_limit-b->getR())
    { //Colisiona con el limite
        b->setVel(b->getVx(),-b->getcRest()*b->getVy());
        b->setPoint(b->getX(),v_limit-b->getR());
    }
}

void MainWindow::on_pushButton_clicked()  // Clic en botón RUN
{
    timer->start(500*t);
    parabolico->getEsf()->setPoint(10,10);
    int vxi=potencia*cos(angulo*M_PI/180); //paso a radianes
    int vyi=potencia*sin(angulo*M_PI/180);
    parabolico->setVxi(vxi*2);
    parabolico->setVyi(vyi*2);
    parabolico->actualizar(t,v_limit);
    scene->addItem(parabolico);

    if(contdisparos > 0)
    {   //Descontar disparos
        contdisparos=contdisparos-1;
    }
    ui->lcdNumber_2->display(contdisparos);
    if(contdisparos==1)
    {
        auxiliar=1; //Es un avisador para que a través de auxiliar acabe la simulación
    }

}

void MainWindow::on_potencia_valueChanged(int value)
{
    potencia=value;
}

void MainWindow::on_angulo_valueChanged(int value)
{
    angulo=value;
}

void MainWindow::on_reiniciar_clicked()
{
    nivel=1;
    contdisparos=12;
    ui->lcdNumber_2->display(contdisparos);
    parabolico->getEsf()->setPoint(10,10);
    parabolico->setVxi(0);
    parabolico->setVyi(0);
    delete objetivo;
    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
    objetivo->actualizar(t,v_limit);
    scene->addItem(objetivo);
}

void MainWindow::posicion(void)
{
    int r=65;

    //Para cambiar giro del objeto 2 (trayectoria circular)
    collide=obstaculo2->collidesWithItem(obstaculo1);
    collide2=obstaculo2->collidesWithItem(obstaculo3);
    if(collide==true || collide2==true)
    {
         bandera1=!bandera1;
    }
    if(bandera1==true)
    {
        i+=rad;
    }
    if(bandera1==false)
    {
        i+=-rad;
    }
    x=-1*r*cos(i*2);
    y=-1*r*sin(i*2);
    obstaculo2->setPos(x+300,y+100);//Cambia la posición del circulo 1 con x y y
}

void MainWindow::mover()
{

    double angulo = asin((x1_obstaculo3 ) / magnitud);
    double a_x = -GRAV * sin(angulo);
    static double vx = 0;// velocidad incial en x es cero
    vx += a_x * TIME;// velocidad en x
    static double w = 0; //Velocidad angular
    w = vx / magnitud;
    double ace_angulo = w / TIME;
    angulo = angulo + w * TIME  + (ace_angulo / 2 ) * TIME * TIME;

    x1_obstaculo3 = magnitud * sin(angulo);
    y1_obstaculo3 = magnitud * cos(angulo);
    obstaculo3->setPos(x1_obstaculo3 - 200, y1_obstaculo3);

}

void MainWindow::on_pushButton_2_clicked()
{
    Cancion5->play();
    if(banderaverificador>=1)
    {
        ui->label_4->show();
        ui->lcdNumber_3->show();
        ui->lcdNumber_3->display(controldemundos);
        ui->label_3->show();
        ui->lineEdit->hide();
        ui->pushButton_4->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->lcdNumber_2->show();
        ui->graphicsView->show();
        ui->lcdNumber->show();
        ui->pushButton->show();
        ui->potencia->show();
        ui->angulo->show();
        ui->labelnombre->show();
        ui->label->show();
        ui->label_2->show();
        ui->labelnombre->setText(nombre);
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->label_fondo->show();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    Cancion5->play();
    close();
}


void MainWindow::on_pushButton_4_clicked()
{
    Cancion5->play();
    nombre=ui->lineEdit->text();
    if(nombre=="")
    {
        banderaverificador=0;
    }
    else
    {
        banderaverificador++;
        if(banderaverificador>0)
        {
            ui->pushButton_2->show();
        }
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    Cancion5->play();
    //ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->lineEdit->show();
    ui->label_fondo->show();

}

void MainWindow::on_pushButton_6_clicked()
{
    Cancion5->play();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->REGISTRARVS->show();
    ui->label_5JUGADOR1->show();
    ui->label_6JUGADOR2->show();
    ui->lineEdit_2JUGADOR1->show();
    ui->lineEdit_3JUGADOR2->show();
    ui->label_fondo->show();
}

void MainWindow::on_REGISTRARVS_clicked()
{
    Cancion5->play();
    jugador1= ui->lineEdit_2JUGADOR1->text();
    jugador2= ui->lineEdit_3JUGADOR2->text();
    if(jugador1==""||jugador2=="")
    {
        banderaverificadorvs=0;
        msgBox.setText("DEBES REGISTRAR 2 USUARIOS");
        msgBox.setInformativeText("");
        msgBox.exec();
    }
    else
    {
        banderaverificadorvs=1;
        ui->label_5JUGADOR1->hide();
        ui->label_6JUGADOR2->hide();
        ui->REGISTRARVS->hide();
        ui->lineEdit_2JUGADOR1->hide();
        ui->lineEdit_3JUGADOR2->hide();
        ui->REGISTRARVS->hide();
        ui->angulo->show();
        ui->potencia->show();
        ui->graphicsView->show();
        obstaculo1->valores(230,240,20,20);
        scene->addItem(obstaculo1);
        ui->disparovs->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->contavs->show();
        ui->contanivel->hide();
        ui->lcdNumber_5puntaj2->show();
        ui->lcdNumber_4puntaje1->show();
        ui->label_5->setText(jugador1);
        ui->label_6->setText(jugador2);
        ui->contavs->display(contdisparos1);
        ui->label_7->show();
        ui->label_8->show();
        //ui->label->show();
        ui->label_fondo->show();
       }
}

void MainWindow::on_disparovs_clicked()
{
    Cancion2->play();
    ui->contavs->display(contdisparos1);
    timer->start(500*t);
    parabolico->getEsf()->setPoint(10,10);
    int vxi=potencia*cos(angulo*M_PI/180);
    int vyi=potencia*sin(angulo*M_PI/180);
    parabolico->setVxi(vxi*2);
    parabolico->setVyi(vyi*2);
    parabolico->actualizar(t,v_limit);
    scene->addItem(parabolico);
    if(contdisparos1 > 0)
    {
        contdisparos1=contdisparos1-1;
    }
    ui->contavs->display(contdisparos1);
    if(contdisparos1==1)
    {
        auxiliar=1;
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    Cancion5->play();
    string hola;
    string nivelasdf;
    string tiros;
    ifstream archivo;
    archivo.open("guardar.txt",ios::out| ios::app);
    archivo.close();
    archivo.open("guardar.txt");
    while(!archivo.eof())
    {
        archivo>>hola;
        archivo>>nivelasdf;
        archivo>>tiros;
        if(hola==nombre.toStdString())
        {
            puedoguardar++;
            qDebug()<<puedoguardar;
            if(puedoguardar==1)
            {
                msgBox.setText(nombre);
                msgBox.setInformativeText("Este usuario ya existe,si desea guardar datos hazlo con otro usuario");
                msgBox.exec();
            }
        }
    }
    archivo.close();
    if(puedoguardar==0)
    {
        ofstream Fichero;
        Fichero.open("guardar.txt",ios::out| ios::app);
        Fichero<<nombre.toStdString()<<" "<<controldemundos<<" "<<contdisparos<<endl;
        Fichero.close();
        puedoguardar=0;
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    Cancion5->play();
    QString prueba;
    int contadordelregistro=0;
    string hola;
    string nivelasdf;
    string tiros;
    ifstream archivo;
    archivo.open("guardar.txt", ios::in);
    while(!archivo.eof())
    {
        archivo>>hola;
        archivo>>nivelasdf;
        archivo>>tiros;
        contadordelregistro++;
        if(hola==nombre.toStdString())
        {
            if(nivelasdf=="1")
            {
                ui->lcdNumber_2->display(stoi(tiros));
                ui->lcdNumber_3->display(stoi(nivelasdf));
                ui->lcdNumber->display(0);
                puntaje=0;
                contdisparos=stoi(tiros);
                controldemundos=stoi(nivelasdf);
                nivel=1;
                delete objetivo;
                objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                objetivo->actualizar(t,v_limit);
                scene->addItem(objetivo);
            }
            if(nivelasdf=="2")
            {
                ui->lcdNumber_2->display(stoi(tiros));
                ui->lcdNumber_3->display(stoi(nivelasdf));
                ui->lcdNumber->display(400);
                puntaje=400;
                contdisparos=stoi(tiros);
                controldemundos=stoi(nivelasdf);
                obstaculo1->valores(230,240,20,20);
                scene->addItem(obstaculo1);
                nivel=1;
                delete objetivo;
                objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                objetivo->actualizar(t,v_limit);
                scene->addItem(objetivo);
            }
            if(nivelasdf=="3")
            {
                ui->lcdNumber_2->display(stoi(tiros));
                ui->lcdNumber_3->display(stoi(nivelasdf));
                ui->lcdNumber->display(800);
                puntaje=800;
                contdisparos=stoi(tiros);
                controldemundos=stoi(nivelasdf);
                scene->addItem(obstaculo2);
                timer2->stop();
                timer2->start(17);
                connect(timer2,SIGNAL(timeout()),this,SLOT(posicion()));
                obstaculo1->valores(230,240,20,20);
                scene->addItem(obstaculo1);
                nivel=1;
                delete objetivo;
                objetivo= new graficar(420,100, 30, 0,0,50,0,0);
                objetivo->actualizar(t,v_limit);
                scene->addItem(objetivo);
            }
        }
  }
  archivo.close();
}
