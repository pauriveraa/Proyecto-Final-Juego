#ifndef MAS_H
#define MAS_H


#include <QGraphicsItem>

class pendulo : public QGraphicsItem
{

public:
    pendulo();
    QRectF boundingRect() const;//Forma
    QPainterPath shape() const;//Color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};


#endif // MAS_H
