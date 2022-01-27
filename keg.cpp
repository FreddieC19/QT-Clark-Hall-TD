#include "keg.h"
#include "Drink.h"

Keg::Keg(QList<QPointF> pointsToFollow, QGraphicsItem *parent) : Drink(pointsToFollow, parent) {setPixmap(QPixmap(":/images/images/keg.png"));}

void Keg::setTexture(bool b) {
    setBeingDrank(b);
    if (b)
        setPixmap(QPixmap(":/images/images/blank.png"));
    else
        setPixmap(QPixmap(":/images/images/keg.png"));
}
