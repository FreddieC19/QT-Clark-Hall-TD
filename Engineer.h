#ifndef ENGINEER_H
#define ENGINEER_H

#include "Character.h"

class Engineer: public Character{
    Q_OBJECT
public:
    Engineer(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
private:
    int drinkingSpeedBeer;
    int drinkingSpeedShot;
    int drinkSpeedKeg;
};

#endif // ENGINEER_H
