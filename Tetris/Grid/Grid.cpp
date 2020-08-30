//
//  Grid.cpp
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include "Grid.h"

Grid::Grid()
{
    for(int row_i = 0; row_i < MAX_ROWS; row_i++)
    {
        for(int col_i = 0; col_i < MAX_ROWS; col_i++)
        {
            m_grid[row_i][col_i] = EMPTY_CELL;
        }
    }
    
    m_activeBlock = nullptr;
}

Grid::~Grid()
{
    if (m_activeBlock)
        delete m_activeBlock;
    
}

void Grid::printGrid()
{
    using namespace std;
    //modify grid info according to active block position
    if(m_activeBlock != nullptr)
    {
        hardcodeBlock(m_activeBlock,OCCUPIED_CELL);
    }
    
    //Margin from the top
    topMargin();
    
    //print Top Boundary
    leftMargin();
    printBoundary();
    
    //print the grid with side boundaries
    for(int row_i = PRINT_ROW_INDEX; row_i < PRINT_ROWS; row_i++)
    {
        printRowDivider();
        
        leftMargin();
        
        cout << GRID_BOUNDARY << EMPTY_CELL;
        
        for(int col_i = 0; col_i < PRINT_COLS; col_i++)
        {
            cout << GRID_COL_DIVIDER << EMPTY_CELL;
            cout << m_grid[row_i][col_i];
            cout << EMPTY_CELL;
        }
        
        cout << GRID_COL_DIVIDER;
        
        cout << EMPTY_CELL << GRID_BOUNDARY << endl;
    }
    
    //print last row Divider
    printRowDivider();
    
    //print the bottom boundary
    leftMargin();
    printBoundary();
    
    //remove the harcoded active block from the grid
    //cause it will move down till the next delay
    if(m_activeBlock != nullptr)
    {
        hardcodeBlock(m_activeBlock,EMPTY_CELL);
    }
    
}

void Grid::hardcodeBlock(Block *block_ptr , char info)
{
    //retrieve the position of all the units composing the block
    std::vector<Unit> settled_block = block_ptr -> getPositions();
    
    int unit_row;
    int unit_col;
    
    for(size_t i = 0; i < settled_block.size(); i++)
    {
        unit_row = (settled_block.at(i)).m_row;
        unit_col = (settled_block.at(i)).m_col;
        
        m_grid[unit_row][unit_col] = info;
    }
    
}


void Grid::eliminateRow(const int row_number)
{
    //delete targeted row and shift information
    for(int row_i = row_number; row_i > PRINT_ROW_INDEX; row_i--)
    {
        for(int col_i = 0; col_i < MAX_COLS; col_i++)
        {
            m_grid[row_i][col_i] = m_grid[row_i - 1][col_i];
        }
    }
    
    //set top row to be empty
    for(int i = 0; i < MAX_COLS; i++)
    {
        m_grid[PRINT_ROW_INDEX][i] = EMPTY_CELL;
    }
}

//int Grid::isMovable(Block* moving_block , Direction direction)
//{
//    
//}





/* PRIVATE FUNCTIONS */
void Grid::printBoundary()
{
    //TODO:used because its obvious that cout statements belond to std namespace
    using namespace std;
    //loop runs for more than just the number of columns for alignment according to spaces out grid boxes
    for(int i = 0; i < 4 * PRINT_COLS + 5; i++)
    {
        cout << GRID_BOUNDARY;
    }
    
    cout << endl;
}


void Grid::printRowDivider()
{
    //TODO:used because its obvious that cout statements belond to std namespace
    using namespace std;
    
    //Margin from left
    leftMargin();
    
    //Grid's Left Boundary
    cout << GRID_BOUNDARY << EMPTY_CELL;
    
    for(int i = 0; i < PRINT_COLS; i++)
    {
        cout << GRID_ROW_DIVIDER;
    }
    
    cout << GRID_CORNER;
    
    //Grid's Right Boundary
    cout << EMPTY_CELL << GRID_BOUNDARY << endl;
}


void Grid::topMargin()
{
    //TODO:used because its obvious that cout statements belond to std namespace
    using namespace std;
    
    for(int i = 0; i < GRID_TOP_MARGIN; i++)
    {
        cout << endl;
    }
}


void Grid::leftMargin()
{
    //TODO:used because its obvious that cout statements belond to std namespace
    using namespace std;
    
    for(int i = 0; i < GRID_LEFT_MARGIN; i++)
    {
        cout << EMPTY_CELL;
    }
}
