#include "game.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Add icon
    a.setWindowIcon(QIcon(":/images/iconAppleHorseChess"));

    Game *game;
    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
