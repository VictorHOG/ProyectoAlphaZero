#include "horse.h"

Horse::Horse(QString team) {
    side = team;
    setImage();
}

void Horse::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/images/horse1.png"));
    else
        setPixmap(QPixmap(":/images/horse.png"));
}
