#ifndef KEG_H
#define KEG_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include "Drink.h"



class Keg: public Drink {
public:
    Keg(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    virtual void setTexture(bool b); // changes beingDrank value and changes texture.
};

#endif // KEG_H
