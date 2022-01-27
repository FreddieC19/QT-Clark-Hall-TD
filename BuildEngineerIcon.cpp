#include "BuildEngineerIcon.h"
#include "Game.h"
#include "Engineer.h"
#include <iostream>

extern Game * game;

BuildEngineerIcon::BuildEngineerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/engineerIcon.png"));
}

void BuildEngineerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
            //std::cout << "New Frec Purchased From Shop" << std::endl;
            game->building = new Engineer();
            game->setCursor(QString(":/images/images/Engineer.png"));
        if (game->shop->payEngBill()){
            std::cout << "New Engineer purchased from shop." << std::endl;
            game->building = new Engineer();
            game->setCursor(QString(":/images/images/Engineer.png"));
            game->coinAmnt->coinLoss(game->shop->getEngineerCost());
            std::cout << "Coins value is now " << game->coinAmnt->getCoinBalance() << std::endl;
        }
        else{
            //return some kind of message that says that the balance is too low
        }
    }
}
