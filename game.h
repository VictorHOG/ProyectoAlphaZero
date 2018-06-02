#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Game :public QGraphicsView {

    Q_OBJECT

public:
    Game(QWidget *parent = 0);

    bool validarItems();
    void displayMainMenu();
    void drawChessBoard(int x, int y);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    void addHorses();
    void addItems();

public slots:
    void start();

private:
    QGraphicsScene *gameScene;
    QLabel *numberItems;
    QLineEdit *appleLine;
    QGraphicsRectItem *boardRects[6][6];
    QList <QGraphicsItem *> listG;
};

#endif // GAME_H
