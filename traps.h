/**@file traps.h
 * @brief should implement traps but does nothing
  */

#ifndef TRAPS_H
#define TRAPS_H

#include <QGraphicsTextItem>

/*! \class traps
    \brief a class for numTraps

    class stores number of mousetraps left on board
*/
class traps: public QGraphicsTextItem
{
public:
    traps();
    void decrease();
    int get_num_traps();
private:
    int numTraps;
};

#endif // TRAPS_H
