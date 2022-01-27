#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Character.h"
#include "enums.h"
#include "coins.h"
#include "shop.h"
#include "legend.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    // member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createDrinks(int numberOfDrinks);
    void createBar();
    void gameOver();
    QGraphicsRectItem* drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void pause();
    bool getPauseFlag();
    void pauseScreen();
    int getRandNum();


    // member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Character * building;
    QTimer * spawnTimer;
    coins * coinAmnt;
    Shop * shop;
    Legend * legend;
    int drinksSpawned;
    int maxNumberOfDrinks;
    QList<QPointF> pointsToFollow;
public slots:
    void restartGame();
    void unPause();
    void spawnEnemy();
    void startGame();
    void displayRules();
    void displayMainMenu();
    //void endOfTrack();
private:
    bool pauseFlag;
    QGraphicsRectItem* pscreen1;
    QGraphicsRectItem* pscreen2;
    QGraphicsRectItem* pbutton1;
    QGraphicsRectItem* pbutton2;
    QGraphicsRectItem* pbutton3;
    QGraphicsTextItem* ptext1;
};

#endif // GAME_H
