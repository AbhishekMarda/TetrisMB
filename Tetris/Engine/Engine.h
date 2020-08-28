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
    Engine();
    ~Engine();
    void run();
    void printInstructions() const;
    int move(Direction direction);
    bool gameOver();
    void printBoard(); //calls m_grid->printGrid() , can remove this func
    bool isBlockSet() const; //can remove
    bool checkElimination(); //if necessary, calls m_grid->eliminate
    Block* generateNewBlock();
    void queueBlock(Block* new_block);
private:
    Grid* m_grid;
    std::queue<Block *> m_upcomingBlocks;
};

#endif /* Engine_h */
