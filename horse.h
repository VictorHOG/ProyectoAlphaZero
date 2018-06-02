#ifndef HORSE_H
#define HORSE_H

#include <QGraphicsPixmapItem>

class Horse:public QGraphicsPixmapItem {
public:
    Horse(QString team = "");

  //  Knight(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void moves();

protected:

    QString side;
};

#endif // HORSE_H
