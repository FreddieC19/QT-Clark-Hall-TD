#include "Screens.h"
#include "Game.h"

extern Game * game;

StartScreen::StartScreen(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/logo.png"));
}
