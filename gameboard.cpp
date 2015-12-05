/**@file gameboard.cpp
 * @brief implements the game board
  */

#include "gameboard.h"
#include "ui_gameboard.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "traps.h"

// set seed for random number generation
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

// Gameboard constructor
Gameboard::Gameboard(QWidget *parent, size_t board_sz) : QWidget(parent), board_size(board_sz){

    Top = new QWidget;

    // This code sets up the Top bar
    //
    // Level:    Traps:

    // This layout will space out the elements above
    QHBoxLayout *top_bar = new QHBoxLayout(Top);

/*
    QString fileName(":/Images/mouse.jpeg");
    mouse_image = new QPixmap(fileName);
    setStyleSheet("background-image: url(:/Images/mouse.jpeg");*/

    // One life is currently playing, the others are listed above
    lives_remaining = 3;
    lives = new QLabel*[lives_remaining-1];

    // Set the labels to have the muncher image, add to the top bar layout.
    for(size_t i=0;i<lives_remaining-1;i++) {
        lives[i] = new QLabel;
        //lives[i]->setPixmap(*mouse_image);
        lives[i]->setMinimumSize(20,20);
        lives[i]->setMaximumSize(20,20);
        lives[i]->setScaledContents(true);
        top_bar->addWidget(lives[i]);
    }


    QLabel* level_text = new QLabel("Level: ");
    if(this->board_size==10){
        level_value = new QLabel("Beginner");
    }
    else if(this->board_size==16){
        level_value = new QLabel("Intermediate");
    }
    else{
        level_value = new QLabel("Expert");
    }


    top_bar->addWidget(level_text);
    top_bar->addWidget(level_value);

    QSpacerItem* horizontal_space = new QSpacerItem(100,100);

    top_bar->addSpacerItem(horizontal_space);

    QLabel* traps_text = new QLabel("Traps: ");
    //traps_value = new QLabel(get_num_traps());

    QSpacerItem* horizontal_space_2 = new QSpacerItem(*horizontal_space);
    // Add in some horizontal space before next labels
    top_bar->addSpacerItem(horizontal_space_2);
    top_bar->addWidget(traps_text);
    //top_bar->addWidget(traps_value);

    // This code Creates the Board
    Board = new QWidget;
    buttons = new QPushButton*[board_size*board_size];
    values = new int[board_size*board_size];
    QGridLayout *SquareGrid = new QGridLayout(Board);

    SquareGrid->setGeometry(QRect());
    SquareGrid->setSpacing(0);

    // Random number generator for C++11
    std::uniform_int_distribution<int> distribution(1,9);

    // Create each label for the board, initialize with random value.
    for(size_t i=0; i<board_size;i++){
        for(size_t j=0; j<board_size;j++){

            // Random values
            values[i*board_size+j] = distribution(generator);

            // Create label and set properties
            buttons[i*board_size+j] = new QPushButton();
            buttons[i*board_size+j]->setText(QString::number( values[i*board_size+j]));
            buttons[i*board_size+j]->setMinimumSize(20,20);
            buttons[i*board_size+j]->setMaximumSize(20,20);
            buttons[i*board_size+j]->setStyleSheet("QLabel { background-color : black; color : white; }");

            // Add label to the layout
            SquareGrid -> addWidget(buttons[i*board_size+j] ,i,j);
        }

        /*if(buttons[i]==1){
            buttons[i]=trap;
        }*/
    }

    // Now piece everything together
    // Central Widget composed of Top and Board
    //    Top
    // --------
    //   Board
    QVBoxLayout *piece_together = new QVBoxLayout;

    piece_together->addWidget(Top,0,Qt::AlignCenter);
    piece_together->addWidget(Board,0,Qt::AlignCenter);

    QPushButton* quit = new QPushButton("Quit");
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    //QObject::connect(quit, SIGNAL(released()), this, SLOT(show()));

    piece_together->addWidget(quit);

    this->setLayout(piece_together);

}

// destructor
Gameboard::~Gameboard()
{
    delete [] values;
    //delete ui;
}

/*
void GameBoard::keyPressEvent(QKeyEvent *event){

}*/
