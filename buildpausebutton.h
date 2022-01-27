#ifndef BUILDPAUSEBUTTON_H
#define BUILDPAUSEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildPauseButton: public QGraphicsPixmapItem{
public:
    BuildPauseButton(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};


#endif // BUILDPAUSEBUTTON_H
