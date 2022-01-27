#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "Drink.h"

class Character:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Character(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
    QTimer * drinkingTimer;         // timer for drinking nearby drinks

public slots:
    void aquire_target();       // check if drink is nearby. If so, connect timer to its update volume function.
    void drink_target();        // drink whatever target the character is linked to.


protected:          // I think this is really bad form... but... yeah.
    int beerDrinkSpeed;
    int kegDrinkSpeed;
    int shotDrinkSpeed;
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool hasTarget;
    Drink * target;             // Pointer to the drink the character is currently drinking. Null by default.
    int attackDist = 125;    // Attack radius. Will need to change this! This is only used for when a drink LEAVES the radius,
                              // a drink is assigned when it is in the polygon.
};

#endif // CHARACTER_H
