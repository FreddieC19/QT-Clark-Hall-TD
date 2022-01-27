#include "Frosh.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

Frosh::Frosh(QGraphicsItem *parent){
    // set all drinking speeds
    beerDrinkSpeed = 5;
    kegDrinkSpeed = 5;
    shotDrinkSpeed = 20;

    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void Frosh::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/redtowerbullet.png"));
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Frosh::aquire_target(){
    Character::aquire_target();
    if(hasTarget)
        setPixmap(QPixmap(":/images/images/froshDrink.png"));
    else
        setPixmap(QPixmap(":/images/images/Frosh.png"));

}

