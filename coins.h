#ifndef COINS_H
#define COINS_H
#include <QGraphicsItem>


class coins: public QGraphicsTextItem
{
public:
    coins(QGraphicsItem *parent=0);
    void changeCoinText();
    int getCoinBalance();
    void coinLoss(int loss);
    void coinGain(int gain);
private:
    int coinAmnt;

};

#endif // COINS_H
