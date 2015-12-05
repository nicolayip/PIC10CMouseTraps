#include "gameboard.h"
#include "ui_gameboard.h"
#include "mainwindow.h"
#include <QPushButton>

gameboard::gameboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameboard)
{
    ui->setupUi(this);
}

gameboard::~gameboard()
{
    delete ui;
}
