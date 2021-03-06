#include "shop.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include "Game.h"

extern Game * game;

Shop::Shop(QGraphicsItem *parent): QGraphicsRectItem(parent){
//    // draw the rect
//    setRect(0,0,200,50);
//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(Qt::darkCyan);
//    setBrush(brush);

//    // draw the text
//    text = new QGraphicsTextItem(name,this);
//    int xPos = rect().width()/2 - text->boundingRect().width()/2;
//    int yPos = rect().height()/2 - text->boundingRect().height()/2;
//    text->setPos(xPos,yPos);

//    // allow responding to hover events
//    setAcceptHoverEvents(true);
}

bool Shop::payEngBill(){
    int cost = getEngineerCost();
    int coins = game->coinAmnt->getCoinBalance();
    if (coins>=cost){
        game->coinAmnt->coinLoss(cost);
        return true;
    }
    else return false;
}

bool Shop::payFrecBill(){
    int cost = getFrecCost();
    int coins = game->coinAmnt->getCoinBalance();
    if (coins>=cost){
        game->coinAmnt->coinLoss(cost);
        return true;
    }
    else return false;
}

bool Shop::payFroshBill(){
    int cost = getFroshCost();
    int coins = game->coinAmnt->getCoinBalance();
    if (coins>=cost){
        game->coinAmnt->coinLoss(cost);
        return true;
    }
    else return false;
}

int Shop::getEngineerCost(){
    return 10;
}

int Shop::getFrecCost(){
    return 15;
}

int Shop::getFroshCost(){
    return 5;
}
