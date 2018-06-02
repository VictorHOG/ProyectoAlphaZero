#include <QPixmap>

#include <QMessageBox>
#include <QLabel>
#include <QIntValidator>
#include <iostream>
using namespace std;

#include "button.h"
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

bool Game::validarItems() {

    int number = 0;
    QString string;

    if(appleLine->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("You must enter a number.   ");
        msgBox.setWindowTitle("Warning");
        msgBox.exec();
        return false;
    } else {
        string = appleLine->text();
        number = string.toInt();
        if (number%2==0) {
            QMessageBox msgBox;
            msgBox.setText("You must enter a odd number.   ");
            msgBox.setWindowTitle("Warning");
            msgBox.exec();
            appleLine->clear();
            return false;
        } else {
            appleLine->clear();
            return true;
        }
    }
    return false;
}

void Game::start() {

    if (validarItems()) {

    }


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
    QFont font( "Bavaria" );
    font.setPointSize( 12 );
    font.setWeight( QFont::Bold );

    //
    QLabel *numberItems = new QLabel(this);
    numberItems->setFont(font);
    numberItems->setText("Cantidad de ítems");
    numberItems->setObjectName(QString("numberItems"));
    numberItems->setGeometry(QRect(440, 300, 200, 25));
    numberItems->show();

    //
    appleLine = new QLineEdit(this);
    appleLine->setObjectName(QString("appleLine"));
    appleLine->setToolTip("Debe ser un número impar");
    appleLine->setValidator( new QIntValidator(1, 34, this) );
    int widthLineEdit = 200;
    int heightLineEdit = 25;
    int xPosLineEdit = width()/2 - widthLineEdit/2;
    int yPosLineEdit = 330;
    appleLine->setGeometry(QRect(xPosLineEdit, yPosLineEdit, widthLineEdit, heightLineEdit));
    appleLine->show();

    //Create Play Button
    Button *playButton = new Button("Play");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 375;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);

    //Create Quit Button
    Button *quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 450;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
}
