#include "beer.h"
#include "Drink.h"

Beer::Beer(QList<QPointF> pointsToFollow, QGraphicsItem *parent) : Drink(pointsToFollow, parent) {setPixmap(QPixmap(":/images/images/100_Full3.png"));}

void Beer::setTexture(bool b) {
    setBeingDrank(b);
    if (b)
        setPixmap(QPixmap(":/images/images/blank.png"));
    else{
           if((get_PointIndex()%4 < 2) && !b){
               if (getVol() >=80){
                   setPixmap(QPixmap(":/images/images/100_Down3.png"));
               }
              else if (getVol() <=79 && getVol() >=60 ){
                   setPixmap(QPixmap(":/images/images/80_Down3.png"));
               }
              else if (getVol() <=59 && getVol() >=40){
                   setPixmap(QPixmap(":/images/images/60_Down3.png"));
               }
              else if (getVol() <=39&& getVol() >=1){
                   setPixmap(QPixmap(":/images/images/20_Down3.png"));
               }
               else if (getVol() <1 ){
                    setPixmap(QPixmap(":/images/images/0_Down3.png"));
                }
           }
           else if(!b){
               if (getVol() >=80){
                   setPixmap(QPixmap(":/images/images/100_Full3.png"));
               }
              else if (getVol() <=79 && getVol() >=60 ){
                   setPixmap(QPixmap(":/images/images/80_Full3.png"));
               }
              else if (getVol() <=59 && getVol() >=40){
                   setPixmap(QPixmap(":/images/images/60_Full3.png"));
               }
              else if (getVol() <=39&& getVol() >=1){
                   setPixmap(QPixmap(":/images/images/20_Full3.png"));
               }
               else if (getVol() <1 ){
                    setPixmap(QPixmap(":/images/images/0_Empty3.png"));
                }
           }
          }
}
