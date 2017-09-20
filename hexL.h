#pragma once

#include "hexGame.h"

/**
 * UI to the Hex game.
 */
class Hex
{
	private:
		HexGame game_;
		int board_side_;
		void startGame_();
		void userInputMove_();
		void printBoard_();
		void printWinner_(TileColour winner);
		void clearScreen_();

	public:
		Hex() : game_(5), board_side_(5) {}
		void gameLoop();
};
