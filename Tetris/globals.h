//
//  globals.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef globals_h
#define globals_h

const int /*could also be chrono*/ TICK_INTERVAL = -1;
const int /*could also be chrono*/ BLOCK_DROP_INTERVAL = -1;
const char OCCUPIED_CELL = '#';
const char EMPTY_CELL = ' ';
const char GRID_BOUNDARY = 'X';
const int MAX_ROWS = 35;
const int MAX_COLS = 10;
const int BUFFER_ROWS = 5;
const int PRINT_ROWS = MAX_ROWS - BUFFER_ROWS;
const int PRINT_COLS = MAX_COLS;

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
    int m_row;
    int m_col;
};

#endif /* globals_h */
