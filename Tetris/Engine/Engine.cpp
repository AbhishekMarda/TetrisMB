//
//  Engine.cpp
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include "Engine.h"
#include "Grid.h"
#include "Block.h"
#include "Utilities.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>


Engine::Engine() : m_points(0)
{
    printInstructions();
    
    m_grid.setActiveBlock(generateNewBlock(BLOCK_SIZE));
    const int MAX_QUEUED_BLOCKS = 3;
    
    for (int i =0; i< MAX_QUEUED_BLOCKS; ++i)
        queueBlock(generateNewBlock(BLOCK_SIZE));
        
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
    std::cout<<BEGIN_MAGENTA_REGULAR;
    std::cout << "                 #####  #####  #####  #####  #####  ####     #       #  ####"<<std::endl;
    std::cout << "                   #    #        #    #   #    #   #         ##     ##  #   #" <<std::endl;
    std::cout << "                   #    ###      #    ####     #   ####      # #   # #  ####" <<std::endl;
    std::cout << "                   #    #        #    #  #     #       #     #  # #  #  #   #" <<std::endl;
    std::cout << "                   #    #####    #    #   #  ##### ####      #   #   #  ####\n\n" <<std::endl;
    std::cout<<RESET_FORMAT;
    cout << "Welcome to TetrisMB © Abhishek Marda and Sanchit Bawri 2020." << endl;
    
    cout <<"The objective of the game is to score the maximum points possible." << endl;
    cout <<endl<< "How to play:" <<endl;
    
    cout << "A block will advance from the top of the grid to the bottom. You must place the block in such a way that maximum eliminations are possible.\n An elimination occurs when an entire row is filled. That row is then deleted, giving you more space to place blocks.\n"<<endl;
    
    cout<<"More the eliminations, more your points. Consecutive eliminations will lead to more points, so place your blocks wisely!\n"<<endl;
    cout <<"You can place the block using the following methods:"<<endl;
    cout <<"1. By pressing the 'a' and 'd' arrow keys to move the block left or right respectively."<<endl;
    cout <<"2. By pressing the up 'w' key to rotate the block in a clockwise direction."<<endl;
    cout <<"3. By pressing the 's' arrow key to push the block down faster."<<endl;
    
    cout << endl<<"In the case that a block is not able to enter the grid completely, game will be over!"<<endl;
    
    cout << endl <<"Press 'q' to quit at any time during the game. ";
    
    cout <<"Enjoy!"<<endl<<endl;
    
    cout<<"Type 'start' to start or 'quit' to quit now.\n";
    char c[10];
    cin >> c;
    if (strncmp(c, "quit", 4)==0)
        exit(0);
    else if (strncmp(c, "start", 5)!=0)
    {
        cout<<"Try spelling another day"<<endl;
        exit(0);
    }
    
}

void Engine::printBoard()
{
    clearScreen();
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
    
    m_grid.updatePoints(getPoints());
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


Block* Engine::generateNewBlock(int num_blocks)
{
#if TRUE_RANDOM_SIZE_4_DISTRIBUTION

    int code = randInt(0, POSSIBLE_BLOCKS_OF_4 - 1);
    
    Block* new_block = getHardcodedBlockOfSizeFour(code);
//
//    int random_rotate = randInt(0, 3);
//    for (int i=0; i<random_rotate; ++i)
//        new_block->rotate();
    return new_block;
    
#else
    

    bool board[num_blocks][num_blocks];
    for(int i=0; i<num_blocks; ++i)
        for (int j=0; j<num_blocks; ++j)
            board[i][j]=0;
    board[num_blocks/2][num_blocks/2] = 1;
    std::vector<Unit> units(num_blocks);
    units[0] = Unit(num_blocks/2, num_blocks/2);
     
    std::vector<std::pair<int, int>> possibilities;
    
    //blocks around the middle
    possibilities.push_back(std::make_pair(units[0].m_row, units[0].m_col-1));
    possibilities.push_back(std::make_pair(units[0].m_row, units[0].m_col+1));
    possibilities.push_back(std::make_pair(units[0].m_row-1, units[0].m_col));
    possibilities.push_back(std::make_pair(units[0].m_row+1, units[0].m_col));

    for(int blocks_remaining = num_blocks-1; blocks_remaining>0; --blocks_remaining)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::minstd_rand0 generator (seed);
        int index = generator()%possibilities.size();
        std::pair<int, int> curr_coords = possibilities[index];
        units[blocks_remaining] = Unit(curr_coords.first, curr_coords.second);
        board[curr_coords.first][curr_coords.second] = 1;
        possibilities.erase(possibilities.begin()+index);
        
        curr_coords.first +=1; //one above mid position
        
        if(curr_coords.first<num_blocks &&
           !board[curr_coords.first][curr_coords.second] &&
           std::find(possibilities.begin(),possibilities.end(),curr_coords)==possibilities.end()
           )
            possibilities.push_back(std::make_pair(curr_coords.first, curr_coords.second));
        
        curr_coords.first-=2; //one below mid position
        
        if(curr_coords.first>0 &&
           !board[curr_coords.first][curr_coords.second] &&
           std::find(possibilities.begin(),possibilities.end(),curr_coords)==possibilities.end()
           )
            possibilities.push_back(std::make_pair(curr_coords.first, curr_coords.second));
        
        curr_coords.first+=1;
        curr_coords.second+=1; //right of the mid position
        
        if(curr_coords.second<num_blocks &&
           !board[curr_coords.first][curr_coords.second] &&
           std::find(possibilities.begin(),possibilities.end(),curr_coords)==possibilities.end()
           )
            possibilities.push_back(std::make_pair(curr_coords.first, curr_coords.second));
        
        curr_coords.second-=2; //left of the mid position
        
        if(curr_coords.second>0 &&
           !board[curr_coords.first][curr_coords.second] &&
           std::find(possibilities.begin(),possibilities.end(),curr_coords)==possibilities.end()
           )
            possibilities.push_back(std::make_pair(curr_coords.first, curr_coords.second));
        
    }
    Block* ptr = new Block(units);

    for (const Unit& u : units)
    {
        ptr->blockGrid[u.m_row][u.m_col] = OCCUPIED_CELL;
    }
    
   return ptr;
#endif

}

int Engine::checkAndEliminateRows()
{
    using namespace std::chrono;
    std::vector<int> rows_to_eliminate = m_grid.findRowsToEliminate();
    printBoard();
    
    std::this_thread::sleep_for(0.4s);
    
    int len = (int) rows_to_eliminate.size();
    for(int i=len-1; i>=0; --i)
    {
        m_grid.fillEliminatedGapAt(rows_to_eliminate[i]);
    }
    
    return 100 * len; //FIXME: create the point system
}

int Engine::move(Direction dir)
{
    int status = m_grid.moveActiveBlock(dir);
    if (status == 0 && dir == DOWN)
    {
        if (m_grid.activeBlockFullyAppeared())
        {
            m_grid.hardcodeActiveBlock(OCCUPIED_CELL);
            m_grid.setActiveBlock(m_upcomingBlocks.front());
            m_upcomingBlocks.pop();
            queueBlock(generateNewBlock(BLOCK_SIZE));
            int points = checkAndEliminateRows();
            updatePoints(points);
            return 0;
        }
        else //game over
        {
            return -1;
        }
    }
    else //move successful!
    {
        return 1;
    }
}


void Engine::run()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    
    printBoard();
    
    double delay;
    while(move(DOWN) != -1)
    {
        delay = BLOCK_DROP_INTERVAL;
        while(delay >= 0)
        {
            sleep_for(0.01s);
            delay -= TICK_INTERVAL;
            if(kbhit())
            {
                switch ((char)getchar())
                {
                    case L:
                        move(LEFT);
                        break;
                    case R:
                        move(RIGHT);
                        break;
                    case D:
                        move(DOWN);
                        break;
                    case U:
                        move(UP);
                        break;
                    case QUIT:
                        goto GAMEOVER;
                    default:
                        break;
                }
                
                printBoard();
            }
        }
        
        printBoard();
    }

    sleep_for(0.4s);
GAMEOVER:
    gameOver();
}
void Engine::gameOver() const
{
    clearScreen();
    std::cout << BEGIN_RED_BGBLACK;
    std::cout << "   ####      #       #     #      ######      #####    #        #    ######    #####  \n";
    std::cout << "  #         # #     # #   # #     #          #     #    #      #     #         #    # \n";
    std::cout << "  #  ##    #####    #  # #  #     ######     #     #     #    #      ######    #####  \n";
    std::cout << "  #   #   #     #   #   #   #     #          #     #      #  #       #         ###    \n";
    std::cout << "   ####   #     #   #       #     ######      #####        ##        ######    #  ### \n";
    std::cout << RESET_FORMAT;
    
    std::cout << BEGIN_CYAN_REGULAR;
    std::cout << std::endl << "You scored "<< getPoints() << " points"<<std::endl;
    std::cout << RESET_FORMAT;
}


Block* Engine::getHardcodedBlockOfSizeFour(int code) const
{
    std::vector<Unit> units;
    switch (code)
    {
        case 0:
            /*
                ####
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 0));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(2, 3));
            break;

        case 1:
            /*
                 #
                ###
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(3, 1));
            units.push_back(Unit(3, 2));
            units.push_back(Unit(3, 3));
            break;

        case 2:
            /*
                ###
                  #
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(2, 3));
            units.push_back(Unit(3, 3));
            break;

        case 3:
            /*
                    #
                  ###
             */

            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(2, 3));
            units.push_back(Unit(1, 3));
            break;

        case 4:
            /*
                ##
                ##
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(3, 1));
            units.push_back(Unit(3, 2));
            break;

        case 5:
            /*
                 ##
                ##
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 3));
            units.push_back(Unit(3, 1));
            units.push_back(Unit(3, 2));
            break;

        case 6:
            /*
                  ##
                   ##
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(3, 2));
            units.push_back(Unit(3, 3));
            break;

        case 7:
            /*
                #
                #
                #
                #
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(0, 2));
            units.push_back(Unit(1, 2));
            units.push_back(Unit(3, 2));
            break;

        case 8:
            /*
                 #
                ##
                 #
             */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(3, 2));
            units.push_back(Unit(1, 2));
            break;
        
        case 9:
            /*
                ##
                ##
            */
            units.push_back(Unit(2, 2));
            units.push_back(Unit(2, 1));
            units.push_back(Unit(3, 1));
            units.push_back(Unit(3, 2));
            break;

        default: return nullptr;

    }
    Block* new_block = new Block(units);
    for (const Unit& u : units)
    {
        new_block->blockGrid[u.m_row][u.m_col] = OCCUPIED_CELL;
    }
    return new_block;
}
