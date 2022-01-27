#include "Character.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "Bullet.h"
#include <QPointF>
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Drink.h"
#include "beer.h"
#include "shot.h"
#include "keg.h"
#include <QtDebug>
#include "coins.h"
#include <iostream>
#include <QFont>

extern Game * game;

#include <QDebug>
Character::Character(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
           << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+10,y()+30);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // set attack_dest
    attack_dest = QPointF(0,0);

    // assume character does not have a target when spawned.
    hasTarget = false;

    // create timer for drinking
    drinkingTimer = new QTimer(this);
}



double Character::distanceTo(QGraphicsItem *item){
    // returns the distance to the item
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void Character::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Character::aquire_target(){
    if(!game->getPauseFlag()) {
        // get a list of all enemies that collide with attack_area, find the closest one
        // and set it's position as the attack_dest

        if (hasTarget) {        // has target. Check if its out of range.
            qInfo() << "has target is true1.1 DtT: " << distanceTo(target) << " atD" << attackDist;
            if (distanceTo(target) > attackDist) {
                //            qInfo() << "Out of range!";

                disconnect(drinkingTimer,SIGNAL(timeout()),this,SLOT(drink_target()));
                hasTarget = false;
                qInfo() << "Out of Range! hasTarget set to false";

                target->setTexture(false);
                target = nullptr;
            }
        } else {
            qInfo() << "has target is false2.";
            // get a list of all enemies within attack_area
            QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

            for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

                // make sure it is an enemy
                Drink * drink = dynamic_cast<Drink *>(colliding_items[i]);

                // see if distance is closer
                if (drink){
                    if (!drink->getBeingDrank()){
                        qInfo() << "New target found!";
                        hasTarget = true;              // if enemy is in range, return pointer to that enemy.
                        target = drink;
                        target->setTexture(true);
                        connect(drinkingTimer,SIGNAL(timeout()),this,SLOT(drink_target()));
                        drinkingTimer->start(400);
                        return;     // Don't want to start drinking other drinks!
                    }   // end inner if
                }   // end outer if
            }   // end for
        } // end if/else
    }
}


void Character::drink_target() {
    if(!game->getPauseFlag()) {
        if (target->getVol() < 0) {
            disconnect(drinkingTimer,SIGNAL(timeout()),this,SLOT(drink_target()));
            qInfo() << "Deleting target.";
            delete target;
            qInfo() << "Deleted target.";
            hasTarget = false;
            qInfo() << "has target is false3.";
            target = nullptr;
        } else {
            if (dynamic_cast<Beer *>(target))
                target->decVol(beerDrinkSpeed); // decrement the drink's volume by drinkingSpeed
            else if (dynamic_cast<Keg *>(target))
                target->decVol(kegDrinkSpeed);
            else if (dynamic_cast<Shot *>(target))
                target->decVol(shotDrinkSpeed);
        }
    }
}

/*
void Character::drink_target() {
    if (target->getVol() < 0) {
        disconnect(drinkingTimer,SIGNAL(timeout()),this,SLOT(drink_target()));
        qInfo() << "Deleting target.";
        delete target;
        qInfo() << "Deleted target.";
        hasTarget = false;
        qInfo() << "has target is false3.";
        target = nullptr;
        game->coinAmnt->coinGain(25);
        std::cout<<"DRINK FINISHED!! +25 Points" << std::endl;
    } else {
        if (dynamic_cast<Beer *>(target))
           target->decVol(beerDrinkSpeed); // decrement the drink's volume by drinkingSpeed
        else if (dynamic_cast<Keg *>(target))
           target->decVol(kegDrinkSpeed);
        else if (dynamic_cast<Shot *>(target))
           target->decVol(shotDrinkSpeed);
    }
}
*/



