//
//  Block.cpp
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include "Block.h"
#include <vector>
#include "Grid.h"


Block::Block()
{
    int midCol = MAX_COLS/2 - MAX_COLS%2;
    m_units.push_back(Unit(0, midCol));
    m_units.push_back(Unit(0, midCol+1));
    m_units.push_back(Unit(1, midCol));
    m_units.push_back(Unit(1, midCol+1));
    m_maxUp = 0;
    m_maxDown=1;
    m_maxLeft = midCol;
    m_maxRight = midCol + 1;
    setGrid(blockGrid);
}

Block::Block(std::vector<Unit> units):m_units(units)
{
    m_maxRight = 0;
    m_maxLeft = MAX_COLS;
    m_maxUp = MAX_ROWS;
    m_maxDown = 0;
    for (Unit u : m_units)
    {
        if (m_maxRight < u.m_col)   m_maxRight = u.m_col;
        if (m_maxLeft > u.m_col)    m_maxLeft = u.m_col;
        if (m_maxDown < u.m_row)    m_maxDown = u.m_row;
        if (m_maxUp > u.m_row)      m_maxUp = u.m_row;
    }
    setGrid(blockGrid);
}


Block::Block(const Block& other):m_units(other.m_units), m_maxLeft(other.m_maxLeft), m_maxRight(other.m_maxRight), m_maxUp(other.m_maxUp), m_maxDown(other.m_maxDown)
{
    
}

Block& Block::operator=(const Block &other)
{
    if (this == &other)
        return *this;
    m_units = other.m_units;
    m_maxLeft = other.m_maxLeft;
    m_maxRight = other.m_maxRight;
    m_maxUp = other.m_maxUp;
    m_maxDown = other.m_maxDown;
    return *this;
}

void Block::move(const Direction dir)
{
    switch (dir)
    {
        case DOWN :
        {
            for (Unit& unit : m_units)
                ++unit.m_row;
            ++m_maxDown;
            ++m_maxUp;
            break;
        }
        case LEFT :
        {
            for (Unit& unit : m_units)
                --unit.m_col;
            --m_maxLeft;
            --m_maxRight;
            break;
        }
        case RIGHT :
        {
            for (Unit& unit : m_units)
                ++unit.m_col;
            ++m_maxLeft;
            ++m_maxRight;
            break;
        }
        case UP :
        {
            rotate(CLOCKWISE);
            break;
        }
    }
}

void Block::rotate(const Rotation rotation)
{
    int row_offset = m_units[0].m_row - 2;
    int col_offset = m_units[0].m_col - 2;
    
    for(const Unit& u : m_units)
    {
        blockGrid[u.m_row - row_offset][u.m_col - col_offset] = OCCUPIED_CELL;
    }
    

    char temp_grid[5][5];
    setGrid(temp_grid);

    m_units.clear();
    for(int r1 = 0 , r2 = 4; r1 < 5; r1++ , r2--)
    {
        for(int c1 = 0 , c2 = 0; c1 < 5; c1++ , c2++)
        {
            if(blockGrid[r2][c2] == OCCUPIED_CELL)
            {
                m_units.push_back(Unit(c1 + row_offset, r1 + col_offset));
                size_t size = m_units.size();
                if(r2 == 2 && c2 == 2 && size != 0)
                {
                    Unit temp = m_units[0];
                    m_units[0] = m_units[size - 1];
                    m_units[size - 1] = temp;
                }
            }
            temp_grid[c1][r1] = blockGrid[r2][c2];
        }
    }
    
    m_maxRight = 0;
    m_maxLeft = MAX_COLS;
    m_maxUp = MAX_ROWS;
    m_maxDown = 0;
    
    for (Unit u : m_units)
    {
        if (m_maxRight < u.m_col)   m_maxRight = u.m_col;
        if (m_maxLeft > u.m_col)    m_maxLeft = u.m_col;
        if (m_maxDown < u.m_row)    m_maxDown = u.m_row;
        if (m_maxUp > u.m_row)      m_maxUp = u.m_row;
    }
}


std::vector<Unit> Block::getPositions() const
{
    return m_units;
}


void Block::setGrid(char grid[5][5])
{
    for(int i_r = 0; i_r < 5; i_r++)
    {
        for(int i_c = 0; i_c < 5; i_c++)
        {
                grid[i_r][i_c] = EMPTY_CELL;
        }
    }
}

int Block::getMax(Direction dir)
{
    switch(dir)
    {
        case DOWN: return m_maxDown;
        case UP: return m_maxUp;
        case LEFT : return m_maxLeft;
        case RIGHT : return m_maxRight;
    }
}
