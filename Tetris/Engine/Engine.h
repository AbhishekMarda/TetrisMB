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
class Block;
class Grid;

class Engine
{
public:
    Engine(); //me
    ~Engine(); //me
    void run();
    void printInstructions() const; //me
    int move(Direction direction);
    bool gameOver();
    void printBoard();
    bool isBlockSet() const; //me
    bool checkElimination(); //if necessary, calls m_grid->eliminate
    Block* generateNewBlock();
    void queueBlock(Block* new_block);
private:
    Grid* m_grid;
    std::queue<Block *> m_upcomingBlocks;
};

#endif /* Engine_h */
