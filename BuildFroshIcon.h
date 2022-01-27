#ifndef BUILDFROSHICON_H
#define BUILDFROSHICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildFroshIcon: public QGraphicsPixmapItem{
public:
    BuildFroshIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // BUILDFROSHICON_H
