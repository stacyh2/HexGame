#include <utility>
#include "boardL.h"
#include "AI.h"
#include "compPlayer.h"

//returns coordinates of next move.
std::pair<int, int> ComputerPlayer::nextMove(Board &board) const
{
    return strategy_->nextMove(board, colour_, is_first_);
}

bool ComputerPlayer::playPieRule(Board &board) const
{
    return false;
}
