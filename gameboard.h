#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <iostream>

namespace Ui {
class gameboard;
}

class gameboard : public QWidget
{
    Q_OBJECT

public:
    explicit gameboard(QWidget *parent = 0);
    ~gameboard();

private:
    Ui::gameboard *ui;
};

#endif // GAMEBOARD_H
