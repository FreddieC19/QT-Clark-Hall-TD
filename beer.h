#ifndef BEER_H
#define BEER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include "Drink.h"



class Beer: public Drink {
public:
    Beer(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    virtual void setTexture(bool b); // changes beingDrank value and changes texture.
};

#endif // BEER_H
