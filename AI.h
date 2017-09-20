#ifndef HEX_AISTRATEGY_H
#define HEX_AISTRATEGY_H

#include <utility>
#include "boardL.h"

/*Used interface for AIStrategy that can be exteneded in the future. Right now only uses pure Monte Carlo
 *AIStrategy but later can add Min-Max/Alpha-Beta Optimizations.
*/ 

class AIStrategy
{
public:
    virtual std::pair<int, int> nextMove(Board &board, TileColour ai_colour, bool is_first) const = 0;
};

#endif 
