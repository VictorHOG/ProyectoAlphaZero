#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Game :public QGraphicsView {

    Q_OBJECT

public:
    Game(QWidget *parent = 0);

    bool validarItems();
    void displayMainMenu();
    void drawChessBoard();

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

public slots:
    void start();

private:
    QGraphicsScene *gameScene;
    QLineEdit *appleLine;
};

#endif // GAME_H
