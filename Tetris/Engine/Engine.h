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
    
    ///Destructor calls delete on grid
    ~Engine();
    
    
    void run();//TBA
    
    ///print instructions of the game to the user
    void printInstructions() const;
    
    /**
     Move the block in the specified direction.
     
     This function will only move the active block. To move all of the other elements of the grid, use moveBoardDown().
     
     @param direction will move active block in direction LEFT, RIGHT, or DOWN. If UP is input, then the block will be rotated.
     
     @returns true if successful. false if unsuccessful.
     */
    bool moveActiveBlock(Direction direction); //TBA
    
    /**
     Shift all elements in the grid down, wherever possible.
     
     @returns true if there was any element that was shifted down. false if no element was shifted down.
     */
    bool moveBoardDown(); //TBA
    
    
    /**
     Ends the game.
     
     This method will only output the final number of points. It is the responsibility of the run() method to ensure that after this method is called, the game is successfully exited.
     */
    void gameOver() const;
    void printBoard();
    bool isBlockSet() const;
    bool checkElimination(); //TBA
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
private:
    Grid m_grid;
    size_t m_points; 
    std::queue<Block *> m_upcomingBlocks;
};

#endif /* Engine_h */
