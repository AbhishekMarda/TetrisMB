//
//  Engine.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef Engine_h
#define Engine_h

#include <queue>
#include "globals.h"
#include "Grid.h"
class Block;
class Engine
{
public:
    
    ///Constructor initialiezes grid and queues block for use
    Engine();
    
    ///Destructor calls delete on queued blocks
    ~Engine();
    
    void run(); //FIXME: implement run
    
    /**
     Moves all blocks and prepares the grid for the next iteration.
     
     This funciton will move the active block in the required direction (LEFT, RIGHT, DOWN, or UP), where UP means that the block is rotated by a 90 degree angle. This also will take care of setting a new block as active, generating a new block, and updating points.
     
     @param dir the direction for movement of the block
     
     @returns 1 if all successful, 0 if unsuccessful (i.e. new block has been called), -1 if game is over
     */
    int move(Direction dir);
    
    ///Print instructions of the game to the user
    void printInstructions() const;
    
    /**
     Ends the game.
     
     This method will only output the final number of points. It is the responsibility of the run() method to ensure that after this method is called, the game is successfully exited.
     */
    void gameOver() const;
    
    /**
     Prints the board
     
     Prints the Main Grid , Upcoming Blocks and Score 
     */
    void printBoard();
    
    /**
     Checks rows that have to be eliminated, eliminates them, and moves them down.
     
     @returns number of points due to the elimination
     */
    int checkAndEliminateRows();
    
    /**
     Generates a new random block of num_blocks size.
     
     @param num_blocks the number of untis that must constitue the upcoming block
     */
    Block* generateNewBlock(int num_blocks); //TBA
    
    ///Add block to the Engine's queue of upcoming blocks
    void queueBlock(Block* new_block);
    
    /**
     Update the users' points.
     
     @param points the positive number of points by which the users points will increase
     */
    void updatePoints(size_t points);
    
    ///Returns the user's points
    size_t getPoints() const;
    
    /**
     Get a premade block instead of a randomly generated one
     
     Use this function to get equal probability of a block appearing instead of having skewed probabilities in a random block generator
     
     @param code the code of the hardcoded block, from 0 to 5
     */
    Block* getHardcodedBlockOfSizeFour(int code) const;
    
private:
    Grid m_grid;
    size_t m_points; 
    std::queue<Block *> m_upcomingBlocks;
    const int POSSIBLE_BLOCKS_OF_4 = 10;
    
};

#endif /* Engine_h */
