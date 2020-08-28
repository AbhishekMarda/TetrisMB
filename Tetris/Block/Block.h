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
     Block default constructor creates a 49x49 block in the middle.
     
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
     
     Rotates the block clockwise or counter clockwise. This function will not have information about bounds of the grid, thus it must be ensured that when it is called, the corresponding grid checks for boundary errors beforehand.
     
     @param rotation can be CLOCKWISE or CTRCLOCKWISE
     */
    void rotate(const Rotation rotation);
    
    /**
     Retrieves all the units that constitute a block.
     
     @returns std::vector<Unit>, the list of units of a block
     */
    std::vector<Unit> getPositions() const;
    
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
