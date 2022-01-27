#ifndef FROSH_H
#define FROSH_H

#include "Character.h"

class Frosh: public Character{
    Q_OBJECT
public:
    Frosh(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // FROSH_H
