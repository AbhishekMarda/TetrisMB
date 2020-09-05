//
//  Engine.cpp
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include "Engine.h"
#include "Grid.h"
#include <iostream>
Engine::Engine() : m_points(0)
{
    printInstructions();
    
    const int MAX_QUEUED_BLOCKS = 3;
    
    for (int i =0; i< MAX_QUEUED_BLOCKS; ++i)
        queueBlock(generateNewBlock());
        
}

Engine::~Engine()
{
    while (!m_upcomingBlocks.empty())
    {
        if (m_upcomingBlocks.front())
            delete m_upcomingBlocks.front();
        m_upcomingBlocks.pop();
    }
    
}

void Engine::printInstructions() const
{
    using namespace std;
    std::cout << "                 #####  #####  #####  #####  #####  ####     #       #  ####"<<std::endl;
    std::cout << "                   #    #        #    #   #    #   #         ##     ##  #   #" <<std::endl;
    std::cout << "                   #    ###      #    ####     #   ####      # #   # #  ####" <<std::endl;
    std::cout << "                   #    #        #    #  #     #       #     #  # #  #  #   #" <<std::endl;
    std::cout << "                   #    #####    #    #   #  ##### ####      #   #   #  ####\n\n" <<std::endl;
    cout << "Welcome to TetrisMB © Abhishek Marda and Sanchit Bawri 2020." << endl;
    
    cout <<"The objective of the game is to score the maximum points possible." << endl;
    cout <<endl<< "How to play:" <<endl;
    
    cout << "A block will advance from the top of the grid to the bottom. You must place the block in such a way that maximum eliminations are possible. An elimination occurs when an entire row is filled. That row is then deleted, giving you more space to place blocks."<<endl;
    
    cout<<"More the eliminations, more your points. Consecutive eliminations will lead to more points, so place your blocks wisely!"<<endl;
    cout <<"You can place the block using the following methods:"<<endl;
    cout <<"1. By pressing the left and right arrow keys to move the block left or right."<<endl;
    cout <<"2. By pressing the up arrow key to rotate the block."<<endl;
    cout <<"3. By pressing the down arrow key to push the block down faster."<<endl;
    
    cout << endl<<"In the case that a block is not able to enter the grid completely, game will be over!"<<endl;
    
    cout <<"Enjoy!"<<endl;
}

void Engine::printBoard()
{
    
    for(int i = 0; i < 4 * PRINT_COLS + 5; i++)
    {
        std::cout << EMPTY_CELL;
    }
    
    std::cout << "          UPCOMING BLOCKS   \n";
    
    Block *temp;
    
    for(int i = 0; i < 3; i++)
    {
        temp = m_upcomingBlocks.front();
        m_grid.placeUpcomingBlock(temp, i);
        m_upcomingBlocks.pop();
        m_upcomingBlocks.push(temp);
    }
    
//    for(int i = 0; i < 5; i++)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            std::cout << m_upcomingBlocks.front()->blockGrid[i][j];
//        }
//        
//        std::cout << std::endl;
//    }
    m_grid.printGrid();
    
}

void Engine::queueBlock(Block *new_block)
{
    if (m_upcomingBlocks.size() >= 3)
        return;
    
    m_upcomingBlocks.push(new_block);
}

void Engine::updatePoints(size_t points)
{
    m_points+=points;
}

size_t Engine::getPoints() const
{
    return m_points;
}

//FIXME: documentation and implementation
Block* Engine::generateNewBlock()
{
   return new Block();
}

