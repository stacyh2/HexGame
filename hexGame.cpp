#include <iostream>
#include "hexGame.h"


bool HexGame :: isFinished() const
{
	bool REDWon = HexGraph::REDWon(main_board_);
	bool BLUEWon = HexGraph::BLUEWon(main_board_);
	return (REDWon || BLUEWon);
}

TileColour HexGame :: winner() const
{
	if ( HexGraph::REDWon(main_board_) )
		return TileColour::RED;
	else if ( HexGraph::BLUEWon(main_board_) )
		return TileColour::BLUE;
	else 
		return TileColour::EMPTY;
}

void HexGame::movePlayer1()
{
	auto pos = p1_->nextMove(main_board_);
    main_board_(pos.first, pos.second) = p1_colour_;
}

void HexGame::movePlayer2()
{
    auto pos = p2_->nextMove(main_board_);
    main_board_(pos.first, pos.second) = p2_colour_;
}
