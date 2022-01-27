#include "legend.h"
#include <QFont>

Legend::Legend(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText("20 Coins\n\n\n\n\n\n\n30 Coins\n\n\n\n\n\n\n10 Coins");
    setDefaultTextColor(Qt::white);
    setPos(2,70);
    setFont(QFont("time", 10));

}
