#include <QPixmap>
#include <QLineEdit>
#include <QLabel>

#include "game.h"

Game::Game(QWidget *parent ): QGraphicsView(parent) {

    //
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1024,768);

    //
    setFixedSize(1024,768);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);

}

void Game::drawChessBoard() {

}


void Game::start() {

}

void Game::addToScene(QGraphicsItem *item) {

    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item) {

    gameScene->removeItem(item);
}

void Game::displayMainMenu() {

    //
    QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/images/a.jpg"));
    p->setPos(0,0);
    addToScene(p);

    //
    QGraphicsTextItem *titleText = new QGraphicsTextItem("AlphaZero");
    QFont titleFont("Algerian" , 50);
    titleText->setFont(titleFont);
    int xPosTitle = width()/2 - titleText->boundingRect().width()/2;
    int yPosTitle = 150;
    titleText->setPos(xPosTitle,yPosTitle);
    addToScene(titleText);

    //
    QLineEdit *appleLine = new QLineEdit(this);
    appleLine->setObjectName(QString("appleLine"));
    appleLine->setToolTip("Enter apple number");
    int widthLineEdit = 200;
    int heightLineEdit = 25;
    int xPosLineEdit = width()/2 - widthLineEdit/2;
    int yPosLineEdit = 450;
    appleLine->setGeometry(QRect(xPosLineEdit, yPosLineEdit, widthLineEdit, heightLineEdit));
    appleLine->show();

    QLabel *numberApple = new QLabel(this);
 //   numberApple->setFont(font);
    numberApple->setText("numberApple");
    numberApple->setObjectName(QString("numberApple"));
    numberApple->setGeometry(QRect(430, 420, 100, 25));
    numberApple->show();

}
