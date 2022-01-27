#include "coins.h"
#include <QFont>
#include <QGraphicsTextItem>

coins::coins(QGraphicsItem *parent): QGraphicsTextItem(parent){
    coinAmnt = 100;
    changeCoinText();
//    setPlainText("Coins: "+ QString::number(coins));
//    setDefaultTextColor(Qt::gray);
//    setPos(550,10);
//    setFont(QFont("time", 16));
}

void coins::changeCoinText(){
    setPlainText("Coins: "+ QString::number(coinAmnt));
    setDefaultTextColor(Qt::white);
    setPos(550,10);
    setFont(QFont("time", 16));
    return;
}

//int Coins::coins = 100;

int coins::getCoinBalance(){
    return coinAmnt;
}

void coins::coinLoss(int loss){
    coinAmnt -= loss;
    changeCoinText();
    return;
}

void coins::coinGain(int gain){
    coinAmnt += gain;
    changeCoinText();
    return;
}
