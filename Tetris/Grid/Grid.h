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
#include "Block.h"
class Grid
{
public:
    
    /**
     Grid default constructor sets all Grid indicies to EMPTY CELL.
     
     Grid constructor will be only called in the beginning of the game and so no block is placed in the grid and the grid is initiated to be empty.
     
     Block pointer is initially pointed to NULL
     
     Boundaries will be directly printed and not set to any index
     */
    Grid();
    
    
    //Grid Destructor deletes the dynamically allocated block pointer that points to the active block
    ~Grid();
    
    
    /**
     Prints a grid displaying information stored in different grid indicies and the boundary
     
     Grid indicies are displayed in boxes created using ASCII characters
     */
    void printGrid();
    
    //TODO:2nd parameter is just to undo the hardcoded block
    /**
     Encodes settled block in m_grid indicies
     
     Once a Block is settled the corresponding location of the block on the grid is stored by setting the respective EMPTY CELLS to OCCUPIED CELLS
     
     @param block_ptr pointer to the settled block
     
     @param info which character must be used to hardcode the block
     */
    void hardcodeBlock(Block *block_ptr, char info);
    
    
    /**
     Eliminates a saturated row from the grid
     
     Called by class Engine .
     
     This function shifts all the rows down by 1 row (excluding the buffer rows)
     
     @param row_number the row which is to be eliminated
     */
    void eliminateRow(const int row_number);
    
    
    /**
     INLINE FUNCTION : Checks if the Desired cell is empty or occupied
     
     @param x_coord X coordinate of cell being investigated
     
     @param y_coord Y coordinate of cell being investigated
     */
    bool isEmpty(int x_coord,int y_coord);
    
    
    int isMovable(Block* moving_block ,Direction direction);
    
    /**
     INLINE FUNCTION : Sets the block pointer passed in parameter to be the Active Block
     
     @param active_block pointer to the block we wish should be active
     */
    void setActiveBlock(Block* active_block);
    
//    /**
//     Places the Upcoming block in the grid buffer
//
//     The placed block becomes active and starts to descend as soon the current active block is settled
//
//     @param upcoming_block pointer to the block which is in the top of the upcoming_block queue in Engine class
//     */
//    void placeUpcomingBlock(Block* upcoming_block);
private:
    
    //Variables
    Block *m_activeBlock;
    char m_grid[MAX_ROWS][MAX_COLS];
    
    //Functions
    ///Prints the top boundary of the grid
    void printBoundary();
    
    ///Prints the row dividers used to create the grid 
    void printRowDivider();
    
    ///Determines the grid's indentation from the top
    void topMargin();
    
    ///Determines the grid's indentation from the left
    void leftMargin();
};

/* INLINE FUNCTIONS */

inline bool Grid::isEmpty(int x_coord,int y_coord)
{
    return m_grid[x_coord][y_coord] == EMPTY_CELL;
}

inline void Grid::setActiveBlock(Block* active_block)
{
    m_activeBlock = active_block;
}

#endif /* Grih_h */
