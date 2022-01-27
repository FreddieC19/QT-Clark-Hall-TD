#include "buildBackground.h"
#include "Game.h"

extern Game * game;

BuildBackground::BuildBackground(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/background.png"));
}
