#include <iostream>
#include "boardL.h"
#include "hexL.h"

void Hex :: gameLoop()
{
	startGame_();

	printBoard_();
	
	//main game loop
	for (;;)
	{
		game_.movePlayer1();
        if (game_.isFinished()) break;	
		clearScreen_();
		printBoard_();
		game_.movePlayer2();
		clearScreen_();
		printBoard_();
        if (game_.isFinished()) break;
	}

	// print the winner
	clearScreen_();
	printBoard_();
	TileColour winner = game_.winner();
	printWinner_(winner);
}

inline void Hex :: startGame_()
{
	char player;
	std::cout << "------- HEX GAME -------" << std::endl;
	std::cout << std::endl;
	
	//Ask if playing against AI or a second Player. Accordingly, call constructor of HexGame.
	while(true)
	{
		std::cout << "Choose to play against another Player(p) or AI(a): " << std::endl;
		std::cin >> player;
		std::cin.clear();
	
		if(player == 'a')
		{
			game_ = HexGame(5, std::unique_ptr<Player>(new HumanPlayer(TileColour::RED)),
						std::unique_ptr<Player>(new ComputerPlayer(TileColour::BLUE, false)));
			break;			
		}
		else if(player =='p')
		{
			game_ = HexGame(5, std::unique_ptr<Player>(new HumanPlayer(TileColour::RED)),
						std::unique_ptr<Player>(new HumanPlayer(TileColour::BLUE)));
			break;				
		}
		else
		{
			std::cout << "Invalid Input. Try Again." << std::endl << std::endl;
			std::cin.clear();
			continue;
		}
	}									
}

//Print Board
inline void Hex :: printBoard_()
{
	auto board = game_.get_main_board();

	std::cout << "   ";
	for (int col = 0; col < board_side_; ++col)
    {
        std::cout.width(3);
        std::cout << std::left << col + 1;
    }
	std::cout << std::endl;

	for (int row=0; row < board_side_; ++row)
	{
        std::cout.width(4);
        std::cout << std::left << row+1;

		for (int col=0; col < board_side_; ++col)
		{
			TileColour tile = board[row*board_side_+col];
			if (tile == TileColour::RED)
				std::cout << "R  ";
			else if (tile == TileColour::BLUE)
				std::cout << "B  ";
			else
				std::cout << "-  ";
		}
		std::cout << " " << row+1 << std::endl;
		std::cout << std::string(row+1,' ');	
	}
	std::cout << "    ";
	for (int col = 0; col < board_side_; ++col)
    {
        std::cout.width(3);
        std::cout << std::left << col + 1;
    }
    std::cout << std::endl;
}

//Print Winner.
inline void Hex :: printWinner_(TileColour winner)
{
	switch (winner)
	{
		case TileColour::RED:
			std::cout << "Winner is RED!" << std::endl;
			break;
		case TileColour::BLUE:
			std::cout << "Winner is BLUE!" << std::endl;
			break;
		default:
			std::cout << "No Winner" << std::endl;
			break;
	}
}

//Clear screen.
inline void Hex :: clearScreen_()
{
    std::cout << std::string (2, '\n');
}
