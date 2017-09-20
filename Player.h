#ifndef HEX_PLAYER_H
#define HEX_PLAYER_H

#include <utility>
#include "boardL.h"

class Player
{
public:
    virtual std::pair<int,int> nextMove(Board &board) const = 0;
    virtual bool playPieRule(Board &board) const = 0;
    virtual ~Player() = default;
};
#endif 
