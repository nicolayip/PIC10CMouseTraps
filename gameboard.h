/**@file gameboard.h
 * @brief implements the game board
  */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <random>
#include <chrono>
#include <QDialog>
#include <QTimer>
#include <iostream>
#include "traps.h"

/*! \class Gameboard
    \brief a class for the variables that create the gameboard

    class implements the gameboard
*/
class Gameboard : public QWidget
{
    Q_OBJECT

signals:
    void game_over();

public:
    explicit Gameboard(QWidget *parent = 0, size_t board_size = 10);
    ~Gameboard();

    traps* traps;

private:

    const QPixmap* mouse_image;

    // Top bar variables
    QLabel* level_value;
    QWidget* Top;
    unsigned int lives_remaining;
    QLabel** lives;

    // Board Variables
    QWidget *Board;
    size_t board_size;
    QPushButton** buttons;
    int* values;
    int numTrapsAdjacent;

};

#endif // GAMEBOARD_H
