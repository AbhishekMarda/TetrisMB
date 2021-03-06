//
//  Block.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef Block_h
#define Block_h
#include <vector>
#include "globals.h"
//class Grid;
class Block
{
public:
    /**
     Block default constructor creates a 2x2 block in the middle.
     
     This assumes row 0 is the top row, at the beginning of the buffer. Col 0 is the first column from the left.
     */
    Block();
    
    /**
     Block constructor given information of its constituent units.
     @param units vector of units with which Block has to be constructed.
     */
    Block(std::vector<Unit> units);
    
    ///Copy constructor
    Block(const Block& other);
    
    ///Assignment operator
    Block& operator=(const Block& other);
    
    ///Destructor, does nothing
    ~Block(){};
    
    /**
     Move the block left, right, or down.
     
     Moves the block in the provided direction. This function will not have information about bounds of the grid, thus it must be ensured that when it is called, the corresponding grid checks for boundary errors beforehand.
     
     @param dir can be LEFT, DOWN, or RIGHT
     */
    void move(const Direction dir);
    
    /**
     Roates the block in specified direction.
     
     Rotates the block clockwise. This function will not have information about bounds of the grid, thus it must be ensured that when it is called, the corresponding grid checks for boundary errors beforehand.
     
     */
    void rotate();
    
    /**
     Retrieves all the units that constitute a block.
     
     @returns std::vector<Unit>, the list of units of a block
     */
    std::vector<Unit> getPositions() const;
    
    ///returns a pointer to m_blockGrid
    char **getGrid() const;
    
    ///Block Holder
    char blockGrid[5][5];
    
    ///initializes a grid to hold a square block
    void setGrid(char grid[5][5]);
    
    ///Return the max bound in that direction
    int getMax(Direction dir);
    
    void printGrid(char g[5][5])
    {
        for(int r = 0; r < 5; r++)
        {
            for(int c = 0; c < 5; c++)
            {
                std::cout << g[r][c] << " ";
            }
            
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    
    
private:
    std::vector<Unit> m_units;
    ///Left most column of the block
    int m_maxLeft;
    ///Right most column of the block
    int m_maxRight;
    ///Highest row of the block
    int m_maxUp;
    ///Lowest row of the block
    int m_maxDown;
};


#endif /* Block_h */
