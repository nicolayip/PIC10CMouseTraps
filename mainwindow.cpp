/**@file mainwindow.cpp
 * @brief should implement beginner, intermediate, expert buttons but does nothing
  */

#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"

/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}*/

// constructs 9x9 board for beginner game
void MainWindow::beginner_game() {
    //board = new Gameboard(this, 9);
    //this->setCentralWidget(board);
}

// constructs 16x16 board for beginner game
void MainWindow::intermediate_game(){
    //board = new Gameboard(this, 16);
    //this->setCentralWidget(board);
}

// constructs 22x22 board for beginner game
void MainWindow::expert_game(){
    //board = new Gameboard(this, 22);
    //this->setCentralWidget(board);
}

void MainWindow::game_over(){
    // Take the current board game out of the central widget of MainWindow
    QWidget* wid = this->centralWidget();
    wid->setParent(NULL);
    // Line above will delete the widget with no memory errors

    QLabel *end = new QLabel("GAME OVER");
    QFont endFont;
    endFont.setPointSize(30);
    end->setFont(endFont);
    end->show();

    // Reset the MainWindow with the initial startup screen
    //ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    //delete ui;
}
