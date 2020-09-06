//
//  globals.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef globals_h
#define globals_h
//TODO: documentation of global functions
#include <iostream>
#include <string>
const int /*could also be chrono*/ TICK_INTERVAL = -1;
const int /*could also be chrono*/ BLOCK_DROP_INTERVAL = -1;
const char OCCUPIED_CELL = '#';
const char EMPTY_CELL = ' ';
const char GRID_BOUNDARY = 'X';
const std::string GRID_ROW_DIVIDER = ".---";
const char GRID_CORNER = '.';
const char GRID_COL_DIVIDER = '|';
const int MAX_ROWS = 35;    // +5 for upcomingBlock
const int MAX_COLS = 11;
const int BUFFER_ROWS = 5;
const int BUFFER_COLS = 5;
const int PRINT_ROWS = MAX_ROWS - BUFFER_ROWS;
const int PRINT_COLS = MAX_COLS;
const int PRINT_ROW_INDEX = 5;  //the row index in the grid from which printing must begin
const int GRID_LEFT_MARGIN = 5;
const int GRID_TOP_MARGIN = 1;


enum Direction
{
    UP, LEFT, DOWN, RIGHT
};

enum Rotation
{
    CLOCKWISE, CTRCLOCKWISE
};

struct Unit
{
    Unit(int row, int col):m_row(row), m_col(col){};
    Unit():m_row(0),m_col(0){};
    int m_row;
    int m_col;
};

#endif /* globals_h */
