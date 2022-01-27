#ifndef SHOP_H
#define SHOP_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "Character.h"
#include "Frosh.h"
#include "Engineer.h"
#include "FREC.h"

class Shop: public QObject, public  QGraphicsRectItem
{
    Q_OBJECT
public:
    Shop(QGraphicsItem* parent=NULL);
    bool payEngBill();
    bool payFrecBill();
    bool payFroshBill();
    int getEngineerCost();
    int getFrecCost();
    int getFroshCost();
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // SHOP_H
