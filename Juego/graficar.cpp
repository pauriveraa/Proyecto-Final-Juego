#include "graficar.h"
#include <QDebug>



graficar::graficar(float x, float y, float r, float vxi, float vyi, float m, float cR, float cF) : escala(1)
{
    esf=new crear(x,y,r,vxi,vyi,m,cR,cF);
}

graficar::~graficar()
{
    delete esf;
}

QRectF graficar::boundingRect() const
{
        return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void graficar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::lightGray);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
}

void graficar::setEscala(float s)
{
    escala=s;
}

void graficar::actualizar(float dt, float v_lim)
{
    esf->actualizar(dt);
    setPos(esf->getX()*escala,(v_lim-esf->getY())*escala);
}

crear *graficar::getEsf()
{
    return esf;
}

void graficar::setVxi(double vxi)
{
    esf->setVxi(vxi);
}

void graficar::setVyi(double vyi)
{
    esf->setVyi(vyi);
}


