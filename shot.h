#ifndef SHOT_H
#define SHOT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include "Drink.h"



class Shot: public Drink {
public:
    Shot(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    virtual void setTexture(bool b); // changes beingDrank value and changes texture.
};

#endif // SHOT_H
