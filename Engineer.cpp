#include "Engineer.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

Engineer::Engineer(QGraphicsItem *parent){
    // set all drinking speeds
    beerDrinkSpeed = 20;
    kegDrinkSpeed = 5;
    shotDrinkSpeed = 5;

    // connect a timer to aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(500);
}

void Engineer::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    //game->scene->addItem(bullet);
}

void Engineer::aquire_target(){
    Character::aquire_target();
    if(hasTarget){
        setPixmap(QPixmap(":/images/images/engineerDrink.png"));
    }
    else{
        setPixmap(QPixmap(":/images/images/Engineer.png"));
    }
}
