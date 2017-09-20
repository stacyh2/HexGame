#include <vector>
#include "boardL.h"
#include "boardExt.h"

SubBoard getEmptySubBoard(const Board& board)
{
    // count # of empty tiles
    int n_empty = 0;
    for (int tile = 0; tile < board.ntiles(); ++tile)
    {
        if (board[tile] == TileColour::EMPTY)
        {
            n_empty++;
        }
    }

    std::vector<int> coords(n_empty);
    std::vector<TileColour> colours(n_empty, TileColour::EMPTY);

    // coords of emtpy tiles
    int side = board.side();
    int k=0;
    for (int i=0; i<side; i++)
    {
        for (int j=0; j<side; j++)
        {
            const int addr = i*side+j;
            if (board[addr] == TileColour::EMPTY)
            {
                coords[k] = addr;
                k++;
            }
        }
    }

    SubBoard sb;
    sb.coords = std::move(coords);
    sb.pieces = std::move(colours);

    return sb;
}

void destroySubBoard(SubBoard& sub_board)
{	
	sub_board.coords.clear();
	std::vector<int>().swap(sub_board.coords);
	
	sub_board.pieces.clear();
	std::vector<TileColour>().swap(sub_board.pieces);
	
}

void insertSubBoard(const SubBoard& sub_board, Board& board)
{
    // gather subboard into board
    int size = sub_board.pieces.size();

    for (int i = 0; i < size; ++i)
    {
        const int addr = sub_board.coords[i];
        board[addr] =  sub_board.pieces[i];
    }
}
