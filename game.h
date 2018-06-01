#ifndef GAME_H
#define GAME_H


#include <QGraphicsScene>
#include <QGraphicsView>

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Game :public QGraphicsView {

    Q_OBJECT

public:
    Game(QWidget *parent = 0);

public slots:
    void start();

    void displayMainMenu();
    void drawChessBoard();

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

private:
    QGraphicsScene *gameScene;

};

#endif // GAME_H
