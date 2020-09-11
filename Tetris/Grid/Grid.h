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
#include <vector>
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
    
    /**
     Encodes settled block in m_grid indicies
     
     Once a Block is settled the corresponding location of the block on the grid is stored by setting the respective EMPTY CELLS to OCCUPIED CELLS
     
     */
    void hardcodeActiveBlock(char info);
    
    /**
     Locate all the rows to eliminate and remove them.
     
     @returns: number of rows removed
     */
    std::vector<int> findRowsToEliminate();
    
    /**
     Eliminates a saturated row from the grid
     
     This function blanks out a row.
     
     @param row_number the row which is to be eliminated
     */
    void eliminateRow(const int row_number);
    
    /**
     Moves down all rows above an eliminated row.
     
     Should be typically called after findRowsToEliminate().
     
     @param row_number the row above which the rows are to be moved down
     */
    
    void fillEliminatedGapAt(const int row_number);
    /**
     INLINE FUNCTION : Checks if the Desired cell is empty or occupied
     
     @param x_coord X coordinate of cell being investigated
     
     @param y_coord Y coordinate of cell being investigated
     */
    bool isEmpty(int x_coord,int y_coord);
    
    /**
     Checks the possibility of movement
     
     Checks if the proposed move is valid
     
     @param direction UP , DOWN , LEFT , RIGHT
     
     @returns True if movable, otherwise false
     */
    bool isMovable(Direction direction);
    
    /**
     INLINE FUNCTION : Sets the block pointer passed in parameter to be the Active Block
     
     @param active_block pointer to the block we wish should be active
     */
    void setActiveBlock(Block* active_block);
    
    /**
     Places the upcoming block in the sidebar adjacent to the Grid
     
     This function is called by Engine and this updates the buffer columns to print upcoming blocks
     
     @param block_p Block that is to be placed
     
     @param position Position of the Upcoming Block from the Top (Possible 0 , 1 , 2)
     */
    void placeUpcomingBlock(Block* block_p, int position);//FIXME: Implement placeUpcomingBlock
    
    /**
     Checks if the active block has completely entered the grid
     
     @returns true if block has completely entered the grid, false if it hasn't
     */
    bool activeBlockFullyAppeared();
    
    /**
     Move the block in the specified direction
     
     @param dir Direction to move the block in
     @returns true if move was successfully moved, false if there was an obstruction
     */
    bool moveActiveBlock(Direction dir);
    
private:
    
    //Variables
    Block *m_activeBlock;
    char m_grid[MAX_ROWS][MAX_COLS];
    char m_upblk_grid[UPBLK_ROWS][UPBLK_COLS];
    
    //Functions
    ///Prints the top boundary of the grid
    void printBoundary();
    
    ///Prints the row dividers used to create the grid 
    void printRowDivider();
    
    ///Determines the grid's indentation from the top
    void topMargin();
    
    ///Determines the grid's indentation from the left
    void leftMargin();
    
    ///Prints a particular row from m_upblk_grid
    void printUpcomingRow(const int& row);
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
