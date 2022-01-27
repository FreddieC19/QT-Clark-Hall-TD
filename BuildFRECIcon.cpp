
#include "BuildFRECIcon.h"
#include "Game.h"
#include "FREC.h"
#include <iostream>

extern Game * game;

BuildFRECIcon::BuildFRECIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/frecIcon.png"));
}

void BuildFRECIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        if (game->shop->payFrecBill()){
            std::cout << "New Frec Purchased From Shop" << std::endl;
            game->building = new FREC();
            game->setCursor(QString(":/images/images/FREC.png"));
            game->coinAmnt->coinLoss(game->shop->getFrecCost());
            std::cout << "Coins value is now " << game->coinAmnt->getCoinBalance() << std::endl;
        }
        else{
            //return some kind of message that says that the balance is too low
        }
    }
}
