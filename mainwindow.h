/**@file mainwindow.h
 * @brief should implement beginner, intermediate, expert buttons but does nothing
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameboard.h"

/*! \class MainWindow
    \brief a class for board

    class should implement beginner, intermediate, expert buttons
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void beginner_game();
    void intermediate_game();
    void expert_game();

    void game_over();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Gameboard* board;
};

#endif // MAINWINDOW_H
