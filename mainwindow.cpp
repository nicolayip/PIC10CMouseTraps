#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::beginner_game() {
    board = new gameboard(this);
    this->setCentralWidget(board);
}

void MainWindow::intermediate_game(){
    board = new gameboard(this);
    this->setCentralWidget(board);
}

void MainWindow::expert_game(){
    board = new gameboard(this);
    this->setCentralWidget(board);
}

void MainWindow::game_over(){
    QWidget* wid = this->centralWidget();
    wid->setParent(NULL);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
