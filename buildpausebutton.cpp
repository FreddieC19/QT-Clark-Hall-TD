#include "buildpausebutton.h"
#include "BuildEngineerIcon.h"
#include "Game.h"
#include "Engineer.h"

extern Game * game;

BuildPauseButton::BuildPauseButton(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/goodPauseButton.png"));
}

void BuildPauseButton::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->pause();
        game->pauseScreen();
    }
}
