#ifndef BUILDENGINEERICON_H
#define BUILDENGINEERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildEngineerIcon: public QGraphicsPixmapItem{
public:
    BuildEngineerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // BUILDENGINEERICON_H
