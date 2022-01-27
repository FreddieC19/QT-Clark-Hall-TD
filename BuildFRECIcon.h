#ifndef BUILDFRECICON_H
#define BUILDFRECICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildFRECIcon: public QGraphicsPixmapItem{
public:
    BuildFRECIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // BUILDFRECICON_H
