#include "mas.h"
#include <QPainter>
#include <cmath>

pendulo::pendulo()
{
    setFlags(ItemIsMovable);            //Habilitar movimiento con el mouse
}

QRectF pendulo::boundingRect() const
{
    return QRectF(-15, -15, 30, 30);    //rectángulo que demarca los límites del item gráfico
}

QPainterPath pendulo::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());    //la forma del objeto gráfico es circular
    return path;
}

void pendulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);         //color del contorno
    painter->setBrush(Qt::green);       //color del relleno
    painter->drawEllipse(boundingRect());
}

void pendulo::advance(int phase)
{

}


