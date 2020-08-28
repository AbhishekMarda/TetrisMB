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
}

Block::Block(std::vector<Unit> units):m_units(units)
{
    m_maxRight = MAX_COLS;
    m_maxLeft = 0;
    m_maxUp = 0;
    m_maxDown = MAX_ROWS;
    for (Unit u : m_units)
    {
        if (m_maxRight > u.m_col)   m_maxRight = u.m_col;
        if (m_maxLeft < u.m_col)    m_maxLeft = u.m_col;
        if (m_maxDown > u.m_row)    m_maxDown = u.m_row;
        if (m_maxUp < u.m_row)      m_maxUp = u.m_row;
    }
}

Block::Block(const Block& other):m_units(other.m_units), m_maxLeft(other.m_maxLeft), m_maxRight(other.m_maxRight), m_maxUp(other.m_maxUp), m_maxDown(other.m_maxDown)
{
    
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
            --m_maxUp;
            break;
        }
        case LEFT :
        {
            for (Unit& unit : m_units)
                --unit.m_col;
            --m_maxLeft;
            ++m_maxRight;
            break;
        }
        case RIGHT :
        {
            for (Unit& unit : m_units)
                ++unit.m_col;
            ++m_maxLeft;
            --m_maxRight;
            break;
        }
        case UP: break;
    }
}

void Block::rotate(const Rotation rotation)
{
    
}


std::vector<Unit> Block::getPositions() const
{
    return m_units;
}
