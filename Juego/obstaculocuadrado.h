#ifndef OBSTACULOCUADRADO_H
#define OBSTACULOCUADRADO_H

#include <QGraphicsItem>
#include <QPainter>


class cuadrado:public QGraphicsItem
{
public:
    float Px;
    float Py;
    float width;   //Ancho
    float height;  //Altura
    cuadrado();
   // void valores(float x,float y,float w,float h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~cuadrado();
};

#endif // OBSTACULOCUADRADO_H




