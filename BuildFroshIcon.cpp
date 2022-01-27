#include "BuildFroshIcon.h"
#include "Game.h"
#include "Engineer.h"
#include "Frosh.h"
#include <iostream>

extern Game * game;

BuildFroshIcon::BuildFroshIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/froshIcon.png"));
}

void BuildFroshIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
		if (game->shop->payFroshBill()){
            std::cout << "New Frosh Purchased From Shop" << std::endl;
            game->building = new Frosh();
            game->setCursor(QString(":/images/images/Frosh.png"));
            game->coinAmnt->coinLoss(game->shop->getFroshCost());
            std::cout << "Coins value is now " << game->coinAmnt->getCoinBalance() << std::endl;
        }
        else{
            //return some kind of message that says that the balance is too low
        }
    }
}

