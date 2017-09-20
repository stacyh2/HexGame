#ifndef HEX_SUBBOARD_H
#define HEX_SUBBOARD_H

#include <vector>
#include "boardL.h"

/**
 * Data structure representing a subset of the tile positions of
 * a hex board and the colour of the piece at each of those positions.
 */
struct SubBoard
{
    // 1d coordinates of the empty tiles
    std::vector<int> coords;

    // tile pieces of the sub_board
    std::vector<TileColour> pieces;
};

//destroys both coords and pieces vectors.
void destroySubBoard(SubBoard& sub_board);


/* Insert the pieces and corresponding tiles of a sub-board
 * param sub_board - A sub-board of tiles with pieces to be inserted into the Board
 * returns hex board updated with the positions from the sub-board.
 */
void insertSubBoard(const SubBoard& sub_board, Board& board);


/* Create a sub-board from all the empty positions from a hex board.
 * param board - A hex board
 * returns a sub-board of the empty positions in board.
 */
SubBoard getEmptySubBoard(const Board& board);

#endif 
