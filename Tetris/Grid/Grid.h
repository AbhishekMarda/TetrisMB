//
//  Grid.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef Grid_h
#define Grid_h

#include "globals.h"
class Block;
class Grid
{
public:
    Grid();
    ~Grid();
    void printGrid();
    void deactivateBlock(Block *block_ptr);
    void eliminateRow(const int row_number);
    bool isEmpty(int x_coord,int y_coord);
    int isMovable(Direction direction);
    void setActiveBlock(Block* active_block);
    void placeUpcomingBlock(); //place upcoming block in grid buffer
private:
    Block *m_activeBlock;
    char m_grid[MAX_ROWS][MAX_COLS];
};

#endif /* Grih_h */
