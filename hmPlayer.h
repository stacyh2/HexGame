#ifndef HEX_HUMANPLAYER_H
#define HEX_HUMANPLAYER_H

#include <utility>
#include "boardL.h"
#include "Player.h"

class HumanPlayer : public Player
{
private:
    TileColour colour_;
    bool validInput_(Board &board, int x, int y) const;
    std::pair<int, int> cliInput_(Board &board) const;

public:
    HumanPlayer(TileColour colour) : colour_(colour) {}
	
    std::pair<int, int> nextMove(Board &board) const override;
    bool playPieRule(Board &board) const override;
};

#endif //HEX_HUMANPLAYERCLI_H
