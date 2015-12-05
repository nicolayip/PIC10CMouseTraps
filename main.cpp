/**@file main.cpp
 * @brief creates start menu
  */

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <iostream>
#include <QTextEdit>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    w.setFixedSize(550,270);

    // creates layouts
    QVBoxLayout *vert = new QVBoxLayout;
    QWidget* topWidget = new QWidget;
    QWidget* bottomWidget = new QWidget;

    // creates header
    QHBoxLayout *horiz = new QHBoxLayout(topWidget);
    QFont headerFont;
    headerFont.setPointSize(30);
    headerFont.setBold(true);
    QLabel *header = new QLabel("Avoid the Mouse Traps!");
    header->setStyleSheet("QLabel { color : red; }");
    header->setAlignment(Qt::AlignCenter);
    header->setFont(headerFont);
    horiz->addWidget(header);
    topWidget->setFixedHeight(100);

    // creates QPushButtons
    QHBoxLayout *horiz2 = new QHBoxLayout(bottomWidget);
    QVBoxLayout *vert2 = new QVBoxLayout;
    QPushButton *instructions = new QPushButton("Instructions");
    QPushButton *clickMe = new QPushButton("Click Me!");
    QPushButton *beginner = new QPushButton("Beginner Game");
    QPushButton *intermediate = new QPushButton("Intermediate Game");
    QPushButton *expert = new QPushButton("Expert Game");
    instructions->setFixedWidth(120);
    clickMe->setFixedWidth(120);
    beginner->setFixedWidth(120);
    intermediate->setFixedWidth(120);
    expert->setFixedWidth(120);
    vert2->addWidget(instructions);
    vert2->addWidget(clickMe);
    vert2->addWidget(beginner);
    vert2->addWidget(intermediate);
    vert2->addWidget(expert);
    horiz2->addLayout(vert2);

    // creates instructions widget
    QWidget *instructionsWid = new QWidget;
    QTextEdit *instructionsText = new QTextEdit("There are a certain number of mousetraps placed randomly on the board, and the number of mousetraps varies depending on which level difficulty you choose. The harder the level, the more mousetraps there are. The board size also gets bigger the harder the level is. You can see how many traps there are on the board in the upper right hand corner. If you click on a mousetrap, the game is over. Otherwise, when you click on a square in the board, the square then displays the number of mousetraps it is touching. For example, if there is one mousetrap diagonally above to the left of the square and another one directly to the right, the number displayed would be 2. If there are no mousetraps touching the square the user clicked, the square does not display any number. You can right click on a square where you believe there is a mousetrap, and the number of traps displayed in the upper right hand corner of window will decrease by one. If you successfully click on all of the squares on the board that are not a mousetrap, you win!");
    instructionsText->setReadOnly(true);
    QVBoxLayout *vert4 = new QVBoxLayout;
    vert4->addWidget(instructionsText);
    instructionsWid->setLayout(vert4);

    // creates clickMe widget
    QWidget *clickMeWid = new QWidget;
    QFont clickMeFont;
    clickMeFont.setPointSize(100);
    clickMeFont.setBold(true);
    QLabel *clickMeText = new QLabel("WOW FACTOR");
    clickMeText->setStyleSheet("QLabel { color : pink; }");
    clickMeText->setFont(clickMeFont);
    QVBoxLayout *vert5 = new QVBoxLayout;
    vert5->addWidget(clickMeText);
    clickMeWid->setLayout(vert5);

    vert->addWidget(topWidget);
    vert->addWidget(bottomWidget);

    // constructs beginner gameboard when button is pressed
    Gameboard *beginnerBoard = new Gameboard(0, 10);
    QObject::connect(beginner, SIGNAL(pressed()), &w, SLOT(close()));
    QObject::connect(beginner, SIGNAL(released()), beginnerBoard, SLOT(show()));

    // constructs intermediate gameboard when button is pressed
    Gameboard *intermediateBoard = new Gameboard(0, 16);
    QObject::connect(intermediate, SIGNAL(pressed()), &w, SLOT(close()));
    QObject::connect(intermediate, SIGNAL(released()), intermediateBoard, SLOT(show()));

    // constructs expert gameboard when button is pressed
    Gameboard *expertBoard = new Gameboard(0, 22);
    QObject::connect(expert, SIGNAL(pressed()), &w, SLOT(close()));
    QObject::connect(expert, SIGNAL(released()), expertBoard, SLOT(show()));

    // shows instructions when button is pressed
    QObject::connect(instructions, SIGNAL(released()), instructionsWid, SLOT(show()));

    // shows clickMeWid when button is pressed
    QObject::connect(clickMe, SIGNAL(released()), clickMeWid, SLOT(show()));


    w.setLayout(vert);
    w.show();

    return a.exec();
}
