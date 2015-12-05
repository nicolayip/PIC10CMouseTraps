/**@file traps.cpp
 * @brief should implement traps but does nothing
  */

#include "traps.h"
#include <QLabel>

traps::traps()
{/*
    if(beginner_game()){
        numTraps = 10;
    }
    else if(intermediate_game()){
        numTraps = 40;
    }
    else numTraps = 99;*/
}

void traps::decrease()
{
    numTraps--;

}

int traps::get_num_traps()
{
    return numTraps;
}
