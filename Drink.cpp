#include "Drink.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <iostream>
#include "Game.h"

#include <QDebug>

extern Game * game;

Drink::Drink(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    // set graphics
    //setPixmap(QPixmap(":/images/images/Enemy.png"));

    // set points
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);
    beingDrank = false;     // when a drink is spawned, it is not being drank.
    volume = 100;

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveForward()));
    //  connect(timer, SIGNAL(timeout()), this, SLOT(updateVolume()));
    timer->start(100);
}

bool Drink::getBeingDrank() {
    return beingDrank;
}

void Drink::setBeingDrank(bool b) {
    // By default, it is assumed the drink is beer.
    beingDrank = b;
}

void Drink::setTexture(bool b) {
    setBeingDrank(b);
    if (b)
        setPixmap(QPixmap(":/images/images/blank.png"));
    else
        setPixmap(QPixmap(":/images/images/Enemy.png"));
}

void Drink::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}


int Drink::getVol() {
    return volume;
}

void Drink::decVol(int dVol) {
    volume -= dVol;
}

int Drink::get_PointIndex(){
    return  point_index;
}

void Drink::moveForward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),dest);

    if (ln.length() < 5 && !game->getPauseFlag()){
        point_index++;
        // last point reached
        if (point_index >= points.size()){
            checkEnd();
            return;
        }
        // last point not reached
        dest = points[point_index];
        rotateToPoint(dest);
        if(point_index%4 < 2){
            if (getVol() >=80){
                setPixmap(QPixmap(":/images/images/100_Down3.png"));
            }
            else if (getVol() <=79 && getVol() >=60 ){
                setPixmap(QPixmap(":/images/images/80_Down3.png"));
            }
            else if (getVol() <=59 && getVol() >=40){
                setPixmap(QPixmap(":/images/images/60_Down3.png"));
            }
            else if (getVol() <=39&& getVol() >=20){
                setPixmap(QPixmap(":/images/images/20_Down3.png"));
            }
        }else{
            if (getVol() >=80){
                setPixmap(QPixmap(":/images/images/100_Full3.png"));
            }
            else if (getVol() <=79 && getVol() >=60 ){
                setPixmap(QPixmap(":/images/images/80_Full3.png"));
            }
            else if (getVol() <=59 && getVol() >=40){
                setPixmap(QPixmap(":/images/images/60_Full3.png"));
            }
            else if (getVol() <=39&& getVol() >=20){
                setPixmap(QPixmap(":/images/images/20_Full3.png"));
            }
        } // end if/else
    }

    if(!game->getPauseFlag()){
        // move enemy forward at current angle
        int STEP_SIZE = 5;
        double theta = rotation(); // degrees

        double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
        double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

        setPos(x()+dx, y()+dy);
    }
}

void Drink::checkEnd(){
    game->gameOver();
}
