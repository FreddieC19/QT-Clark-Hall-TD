#ifndef DRINK_H
#define DRINK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Drink: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drink(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    void setDVol(int d);
    int getVol();
    void decVol(int dVol);
    bool getBeingDrank();
    void setBeingDrank(bool b);
    virtual void setTexture(bool b);        // updates the texture of the drink, and sets the beingDrank attribure to false.
    int get_PointIndex();
    void checkEnd();
public slots:
    void moveForward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int volume;
    bool beingDrank;
};

#endif // DRINK_H
