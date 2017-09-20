#pragma once

#include <vector>
#include "boardL.h"

namespace HexGraph
{
	/**
	 * Get the neighbours of a board tile.
	 *
	 * param t - board tile index
	 * param side - board side length
	 * returns vector of indices of t's neighbours. 
	*/
	void neighbourNodesFast(int t, int side, std::vector<int> &neighbours);

	//returns bool true if RED has won; else false
	bool REDWon(const Board& board);

	//returns bool true if BLUE has won; else false
	bool BLUEWon(const Board& board);

	/**
	 * Calculate the winning colour in the case
	 * where board has no empty tiles.
	 *
	 * returns the colour of the winning player.
	 */
	TileColour fullBoardWinner(const Board& board);
};


