#include "shot.h"
#include "Drink.h"

Shot::Shot(QList<QPointF> pointsToFollow, QGraphicsItem *parent) : Drink(pointsToFollow, parent) {setPixmap(QPixmap(":/images/images/shot.png"));}

void Shot::setTexture(bool b) {
    setBeingDrank(b);
    if (b)
        setPixmap(QPixmap(":/images/images/blank.png"));
    else
        setPixmap(QPixmap(":/images/images/shot.png"));
}
