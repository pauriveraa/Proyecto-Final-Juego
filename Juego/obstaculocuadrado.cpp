#include "obstaculocuadrado.h"

cuadrado::cuadrado()
{

}

/*
void cuadrado::valores(float x, float y, float w, float h)
{
    Px = x;
    Py = y;
    width = w;
    height = h;
    setPos(Px,Py);

}
*/
cuadrado::~cuadrado()
{

}

QRectF cuadrado::boundingRect() const
{
    //return QRectF(-width,height,2*width,2*height);
    return QRectF(600,400,70,70);
}

void cuadrado::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);        //asigna el color
    painter->drawRect(boundingRect());
}

