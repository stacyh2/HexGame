#ifndef HEX_COMPUTERPLAYER_H
#define HEX_COMPUTERPLAYER_H

#include <memory>
#include <utility>
#include "boardL.h"
#include "AI.h"
#include "MonteCarlo.h"
#include "TreeSearchMC.h"
#include "Player.h"

/*
 * ComputerPlayer inherits from Player. Plays according to AIStrategy picked.
 */ 

class ComputerPlayer : public Player
{
	private:
		TileColour colour_; //Colour choosen for player.
		std::unique_ptr<AIStrategy> strategy_; //AIStrategy picked to use.
		bool is_first_; //computer player goes first or not?

	public:
		//Constructor for ComputerPLayer. Creates new instance of AIStrategy choosen.
		ComputerPlayer(TileColour colour, bool is_first) : colour_(colour), is_first_(is_first)
		{
		    strategy_ = std::unique_ptr<AIStrategy>(new PureMonteCarlo());
		}
		
		//Overriden Player functions.
		std::pair<int, int> nextMove(Board &board) const override;
		bool playPieRule(Board &board) const override;
};

#endif 
