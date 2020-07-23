#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x=y=i=0; //Datos para cambiar posición del circulo
    rad=0.01745329252;
    potencia=0; //value de potencia
    t=0.01; //"tiempo"
    h_limit=900; //Limites del graphicsview
    v_limit=300;
    nivel=1; //contadorpara determinar los niveles

////////////////////////////Tiempos (temporizadores) y escena///////////////////////////////////////////////

    timer=new QTimer(this);                 //crea el timer
    timer2=new QTimer(this);
    timer3=new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(-300,-300,1800,900); // Set del retangulo de la escena con los parametros (x,y,ancho,alto)
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);
    qDebug()<<ui->graphicsView->size();
    this->resize(640, 480);
    qDebug()<<this->size();

////////////////////////////objetivo//////////////////////////////////////////////////////

    objetivo= new graficar(420,100, 30, 0,0,50,0,0);
    objetivo->actualizar(t,v_limit);
    scene->addItem(objetivo);
    timer->stop();                              //para el timer para objetivo y parabolico
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


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

////////////////////////////objeto trayectoria circular ///////////////////////////////////

    obstaculo2 = new circulo;
    //scene->addItem(obstaculo2);
    timer2->start(12);
    //connect(timer2,SIGNAL(timeout()),this,SLOT(posicion()));


////////////////////////////////objeto cuadrado/////////////////////////////////////////////

    obstaculo1 = new cuadrado;
    //obstaculo1->valores(230,240,20,20);
    //scene->addItem(obstaculo1);

/////////////////////Dejo de mostrar esto en el mainwindow con .hide()/////////////////////////

    ui->graphicsView->hide();
    ui->lcdNumber->hide();
    ui->pushButton->hide();
    ui->reiniciar->hide();
    ui->potencia->hide();
    ui->angulo->hide();
    ui->labelnombre->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lcdNumber_3->hide();
    ui->label_4->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->lineEdit->hide();

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

    if(objColision(parabolico->getEsf(), objetivo->getEsf())==true){
        contdisparos++;
        puntaje=puntaje+100;
        nivel++;

        delete objetivo;

        parabolico->getEsf()->setPoint(10,10);

        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(nivel==2){
             objetivo=new graficar(400,50, 30, 0,0,50,0.5,0);
             objetivo->actualizar(t,v_limit);
             scene->addItem(objetivo);
             //puntaje=puntaje+100;
             ui->lcdNumber->display(puntaje);
        }

        if(nivel==3){
            objetivo=new graficar(400,150, 30, 0,0,50,0.5,0);
            //objetivo->getEsf()->setVel(0, 50);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            //puntaje=puntaje+100;
            ui->lcdNumber->display(puntaje);
        }
        if(nivel==4){
            objetivo=new graficar(350,100, 25, 0,0,50,1,0);
            objetivo->getEsf()->setVel(10, 50);
            objetivo->actualizar(t,v_limit);
            scene->addItem(objetivo);
            //puntaje=puntaje+100;
            ui->lcdNumber->display(puntaje);
            contdisparos=contdisparos+1;
        }
        if(nivel==5){
            ui->lcdNumber->display(puntaje);
           controldemundos++;
           if(nivel==5&&controldemundos==4){
               msgBox.setText("YOU WIN TERMINASTE");
               msgBox.exec();
               close();
           }

           objetivo=new graficar(420,100, 30, 0,0,50,0,0);
           objetivo->getEsf()->setVel(0, 0);
           objetivo->actualizar(t,v_limit);
           scene->addItem(objetivo);
           if(controldemundos!=4){
           msgBox.setText("pasaste al siguiente nivel");
           msgBox.exec();
           ui->lcdNumber_3->display(controldemundos);
           }
           obstaculo1->valores(230,240,20,20);
           scene->addItem(obstaculo1);
           nivel=1;

           if(controldemundos==3){
               scene->addItem(obstaculo2);
               timer2->start(12);
               connect(timer2,SIGNAL(timeout()),this,SLOT(posicion()));

           }
        }
    }

    ui->lcdNumber_2->display(contdisparos);

 //////////////////////Colision con pendulo///////////////////////////

    collide=parabolico->collidesWithItem(obstaculo3);
    if(collide==true){

        parabolico->getEsf()->setPoint(10,10);

        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0){
            auxiliar= auxiliar+1;

            if(contdisparos==0 && auxiliar ==2){

                timer->stop();
                msgBox.setText("YOU LOSE pendulito");
                msgBox.exec();
                close();

            }

        }
    }


 ///////////////////////////////Colision con cuadrado//////////////////

    collide=parabolico->collidesWithItem(obstaculo1);
    if(collide==true){

        parabolico->getEsf()->setPoint(10,10);

        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0){
            auxiliar= auxiliar+1;

            if(contdisparos==0 && auxiliar ==2){

                timer->stop();
                msgBox.setText("YOU LOSE orbita");
                msgBox.exec();
                close();

            }

        }
    }

////////////////////////Colison con el circulo ///////////////////////////////

    collide=parabolico->collidesWithItem(obstaculo2);
    if(collide==true){

        parabolico->getEsf()->setPoint(10,10);

        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0){
            auxiliar= auxiliar+1;

            if(contdisparos==0 && auxiliar ==2){

                timer->stop();
                msgBox.setText("YOU LOSS orbita");
                msgBox.exec();
                close();
            }

        }
    }
}

/////////////////////////////Colisión con los bordes///////////////////////////////////

void MainWindow::bordercollision(crear *b)
{
    if(b->getX()<= b->getR()){
        b->setVel(-b->getcRest()*b->getVx(),b->getVy());
        b->setPoint(b->getR(),b->getY());
    }
    else if(b->getX()>=h_limit-b->getR()){ //Si colisiona con el borde
        parabolico->getEsf()->setPoint(10,10); //UBICO EN LA POSICION INICIAL
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0){
            auxiliar= auxiliar+1;

            if(contdisparos==0 && auxiliar ==2){

                timer->stop();
                msgBox.setText("YOU LOSE muroderecha");
                msgBox.exec();
                close();
                                        }
                             }
    }

    if(b->getY()<=b->getR()){
        b->setVel(b->getVx(),-b->getcRest()*b->getVy());
        b->setPoint(b->getX(),b->getR());
        parabolico->getEsf()->setPoint(10,10);
        parabolico->setVxi(0);
        parabolico->setVyi(0);
        if(contdisparos==0){
            auxiliar= auxiliar+1;

            if(contdisparos==0 && auxiliar ==2){

                timer->stop();
                msgBox.setText("YOU LOSE muroabajo");
                msgBox.exec();
                close();
            }
        }
    }
    else if(b->getY()>=v_limit-b->getR()){ //Colisiona con el limite
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

    if(contdisparos > 0){   //Descontar disparos
    contdisparos=contdisparos-1;}

    ui->lcdNumber_2->display(contdisparos);

    if(contdisparos==1){
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
    objetivo= new graficar(200,100, 50, 0,0,50,0,0);
    objetivo->actualizar(t,v_limit);
    scene->addItem(objetivo);
}
void MainWindow::posicion(void)
{
    int r=65;

    //Para cambiar giro del objeto 2 (trayectoria circular)
    collide=obstaculo2->collidesWithItem(obstaculo1);
    collide2=obstaculo2->collidesWithItem(obstaculo3);
    if(collide==true || collide2==true){
         bandera1=!bandera1;
    }
    if(bandera1==true){
    i+=rad;
     }
    if(bandera1==false){
        i+=-rad;
    }

    x=-1*r*cos(i*2);
    y=-1*r*sin(i*2);
    obstaculo2->setPos(x+300,y+100);//Cambia la posición del circulo 1 con x y y
}

void MainWindow::mover(){

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

    if(banderaverificador>=1){
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

}
    }


void MainWindow::on_pushButton_3_clicked()
{
    close();
}


void MainWindow::on_pushButton_4_clicked()
{
    nombre=ui->lineEdit->text();
    if(nombre==""){
    banderaverificador=0;}
    else{
        banderaverificador++;

    }
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->lineEdit->show();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
}

void MainWindow::on_pushButton_6_clicked()
{

}
