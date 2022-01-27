#include "Game.h"
#include <QGraphicsScene>
#include "Engineer.h"
#include "Bullet.h"
#include "Drink.h"
#include "BuildEngineerIcon.h"
#include "BuildFRECIcon.h"
#include "BuildFroshIcon.h"
#include "buildpausebutton.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsLineItem>
#include "buildBackground.h"
#include "Screens.h"
#include "Button.h"
#include "beer.h"
#include "shot.h"
#include "keg.h"
#include <iostream>
#include <QProcess>
#include "coins.h"
#include "shop.h"


Game::Game(): QGraphicsView(){

    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,700,656);

    // set the scene
    setScene(scene);

    // set curosr
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    // alter window
    setFixedSize(700, 656);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    pauseFlag = false;

    std::cout << "About to start main menu" << std::endl;

    displayMainMenu();

//    BuildBackground * background1 = new BuildBackground();
//    background1->setPos(x(),y());
//    scene->addItem(background1);


//    /*
//    //Adds game logo
//    StartScreen *logo = new StartScreen();
//    logo->setPos(x() + 90,y() + 85);
//    scene -> addItem(logo);
//    */



//    // create enemy
//    spawnTimer = new QTimer(this);
//    drinksSpawned = 0;
//    maxNumberOfDrinks = 0;
//    pointsToFollow << QPointF(500,160) << QPointF(250,160) << QPointF(210, 290) << QPointF(465, 290)
//                   << QPointF(500, 420) << QPointF(180, 420) << QPointF(130, 550) << QPointF(560, 550);

//    createDrinks(5);//5

//    // create Bar
//    createBar();

//    // test code
//    BuildEngineerIcon * bt = new BuildEngineerIcon();
//    BuildFRECIcon * gt = new BuildFRECIcon();
//    BuildFroshIcon * rt = new BuildFroshIcon();
//    gt->setPos(x(),y()+100);
//    rt->setPos(x(),y()+200);

//    BuildPauseButton * lt = new BuildPauseButton();
//    lt->setPos(x()+675,y());
//    scene->addItem(lt);

//    scene->addItem(bt);
//    scene->addItem(gt);
//    scene->addItem(rt);


}

void Game::startGame() {
    scene->clear();

    BuildBackground * background1 = new BuildBackground();
    background1->setPos(0,0);
    scene->addItem(background1);
	
    //initialize coins
    coinAmnt = new coins();
    std::cout << "Coins value is " << coinAmnt->getCoinBalance() << std::endl;
    scene->addItem(coinAmnt);

    shop = new Shop();
    legend = new Legend();
    scene->addItem(legend);
    /*
    //Adds game logo
    StartScreen *logo = new StartScreen();
    logo->setPos(x() + 90,y() + 85);
    scene -> addItem(logo);
    */

    // create enemy
    spawnTimer = new QTimer(this);
    drinksSpawned = 0;
    maxNumberOfDrinks = 0;
    pointsToFollow << QPointF(500,160) << QPointF(250,160) << QPointF(210, 290) << QPointF(465, 290)
                   << QPointF(500, 420) << QPointF(180, 420) << QPointF(130, 550) << QPointF(560, 550);

    createDrinks(5);//5

    // create Bar
    createBar();

    // test code
    BuildEngineerIcon * bt = new BuildEngineerIcon();
    BuildFRECIcon * gt = new BuildFRECIcon();
    BuildFroshIcon * rt = new BuildFroshIcon();
    bt->setPos(30,  30);
    gt->setPos(30, 130);
    rt->setPos(30, 230);

    BuildPauseButton * lt = new BuildPauseButton();
    lt->setPos(620, 50);
    scene->addItem(lt);

    scene->addItem(bt);
    scene->addItem(gt);
    scene->addItem(rt);
}

void Game::displayMainMenu(){
    scene->clear();

    BuildBackground * background1 = new BuildBackground();
    background1->setPos(0,0);
    scene->addItem(background1);

    // pop up semi transparent panel
    drawPanel(0,0,700,656,Qt::black,0.5);

    // draw panel
    drawPanel(150,120,400,400,Qt::lightGray,0.75);

    // create play button
    Button * play = new Button(QString("Play"));
    play->setPos(260,300);
    scene->addItem(play);
    connect(play,SIGNAL(clicked()),this,SLOT(startGame()));

    // create rules button
    Button * rules = new Button(QString("How to Play"));
    rules->setPos(260, 375);
    scene->addItem(rules);
    connect(rules, SIGNAL(clicked()), this, SLOT(displayRules()));

    // create quit button
    Button * quit = new Button(QString("Quit"));
    quit->setPos(260,450);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QString message = "Welcome to Clark Hall Tower Defense!";
    QGraphicsTextItem* overText = new QGraphicsTextItem(message);
    overText->setPos(245,225);
    scene->addItem(overText);
    std::cout << "Main menu complete " << std::endl;
}

void Game::displayRules() {
    scene->clear();

    BuildBackground * background1 = new BuildBackground();
    background1->setPos(0,0);
    scene->addItem(background1);

    // pop up semi transparent panel
    drawPanel(0,0,700,656,Qt::black,0.5);

    // draw panel
    drawPanel(150,120,400,400,Qt::lightGray,0.75);

    // create back button
    Button * back = new Button(QString("Return to main menu"));
    back->setPos(260,375);
    scene->addItem(back);
    connect(back,SIGNAL(clicked()),this,SLOT(displayMainMenu()));


    QString rulesMsg = "\tHow to play:\n\n"
                       "Place your choice of engineer, FREC, and\n"
                       "frosh on the table to drink the drinks!\n\n"
                       "Engineers drink beer quickly, FRECs drink\n"
                       "kegs quickly, and the silly forsh drink\n"
                       "shots quickly!\n"
                       "If any drink reaches the end of the table,\n"
                       "you LOSE!";
    QGraphicsTextItem* overText = new QGraphicsTextItem(rulesMsg);
    overText->setPos(245,175);
    scene->addItem(overText);
    std::cout << "Main menu complete " << std::endl;
}

void Game::setCursor(QString filename){
    // if there is already a cursor, remove it first
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}


void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // if we are building
    if (building){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Character*>(items[i])){
                return;
            }
        }

        // otherwise, build at the clicked location
        scene->addItem(building);
        building->setPos(event->pos());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}

void Game::createDrinks(int numberOfDrinks){
    drinksSpawned = 0;
    maxNumberOfDrinks = numberOfDrinks;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1000);
}


void Game::createBar(){
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++){
        // create a line connecting the two points
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(10);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);

    }
}

bool Game::getPauseFlag(){
    return pauseFlag;
}

void Game::spawnEnemy(){
    if(!getPauseFlag()){
        // spawn an enemy (Keg, Shot, or Beer (not Drink))
        /*
        int drinkTypeOdds = getRandNum();

        if(drinkTypeOdds == 6 || drinkTypeOdds == 7){
            Drink * drink = new Shot(pointsToFollow);
            drink->setPos(pointsToFollow[0]);
            scene->addItem(drink);
            drinksSpawned += 1;
        }
        else if(drinkTypeOdds == 8 || drinkTypeOdds == 9){
            Drink * drink = new Keg(pointsToFollow);
            drink->setPos(pointsToFollow[0]);
            scene->addItem(drink);
            drinksSpawned += 1;
        }
        else{
            Drink * drink = new Beer(pointsToFollow);
            drink->setPos(pointsToFollow[0]);
            scene->addItem(drink);
            drinksSpawned += 1;
        }
        */

        Drink * drink = new Beer(pointsToFollow);
        drink->setPos(pointsToFollow[0]);
        scene->addItem(drink);
        drinksSpawned += 1;

        if (drinksSpawned >= maxNumberOfDrinks){
            spawnTimer->disconnect();
        }
    }
}

int Game::getRandNum(){
    int random = rand() % 10;
    return random;
}

void Game::gameOver(){
    //scene->clear();

    BuildBackground * background1 = new BuildBackground();
    background1->setPos(0,0);
    scene->addItem(background1);

    // pop up semi transparent panel
    drawPanel(0,0,700,656,Qt::black,0.5);

    // draw panel
    drawPanel(150,120,400,400,Qt::lightGray,0.75);

    // create playAgain button
    Button * playAgain = new Button(QString("Play Again"));
    playAgain->setPos(260,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button * quit = new Button(QString("Quit"));
    quit->setPos(260,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QString gameOverMessage = "\tGame Over! \nA drink has made it to the end of the track";
    QGraphicsTextItem* overText = new QGraphicsTextItem(gameOverMessage);
    overText->setPos(245,225);
    scene->addItem(overText);
}

void Game::pauseScreen(){
    // pop up semi transparent panel
    pscreen1 = drawPanel(0,0,700,656,Qt::black,0.5);

    // draw panel
    pscreen2 = drawPanel(150,120,400,400,Qt::lightGray,0.75);

    // create restart button
    Button * restartB = new Button(QString("Restart"));
    restartB->setPos(260,325);
    scene->addItem(restartB);
    pbutton1 = restartB;
    connect(restartB,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button * quit = new Button(QString("Quit"));
    quit->setPos(260,400);
    scene->addItem(quit);
    pbutton2 = quit;
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create continue button
    Button * continueB = new Button(QString("Continue"));
    continueB->setPos(260, 250);
    scene->addItem(continueB);
    pbutton3 = continueB;
    connect(continueB,SIGNAL(clicked()),this,SLOT(unPause()));

    QString gameOverMessage = "\tTime for some more turbo?";
    QGraphicsTextItem* overText = new QGraphicsTextItem(gameOverMessage);
    QFont f;
    f.setBold(true);
    f.setPixelSize(20);
    overText->setFont(f);
    overText->setPos(150,175);
    scene->addItem(overText);
    ptext1 = overText;

}

QGraphicsRectItem* Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
    return panel;
}

void Game::restartGame(){
    QProcess process;
    process.startDetached("Test1",QStringList());

    close();
}

void Game::pause(){
    pauseFlag = true;
}

void Game::unPause(){
    scene->removeItem(pscreen1);
    scene->removeItem(pscreen2);
    scene->removeItem(pbutton1);
    scene->removeItem(pbutton2);
    scene->removeItem(pbutton3);
    scene->removeItem(ptext1);
    pauseFlag = false;
}
