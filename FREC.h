#ifndef FREC_H
#define FREC_H

#include "Character.h"

class FREC: public Character{
    Q_OBJECT
public:
    FREC(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};


#endif // FREC_H
