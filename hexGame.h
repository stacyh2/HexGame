#pragma once

#include <memory>
#include "boardL.h"
#include "graphL.h"
#include "Player.h"
#include "hmPlayer.h"
#include "compPlayer.h"

class HexGame
{
	private:
        // The board representing the current state of play. 
		Board main_board_;
		std::unique_ptr<Player> p1_;
		std::unique_ptr<Player> p2_;
		TileColour p1_colour_ = TileColour::RED;
		TileColour p2_colour_ = TileColour::BLUE;

	public:
        
        //Creates an instance of HexGame with a board of side size s.
		HexGame(int s) : main_board_(s)
        {
			p1_ = std::unique_ptr<Player>(new HumanPlayer(p1_colour_));
            p2_ = std::unique_ptr<Player>(new ComputerPlayer(p2_colour_, true));
        }

        HexGame(int s, std::unique_ptr<Player> p1, std::unique_ptr<Player> p2) : main_board_(s)
        {
            p1_ = std::move(p1);
            p2_ = std::move(p2);
        }
		
		//Moves Player1
		void movePlayer1();

		//Moves Player2
		void movePlayer2();

        //return True if the game has a winner, else false.
		bool isFinished() const;


        /* returns The colour of the winning player. If there is no
         * winner returns TileColour::Empty
         */
		TileColour winner() const;


        // return Reference of Board stored in this.
		const Board& get_main_board() const
		{
			return main_board_;
		}
};
