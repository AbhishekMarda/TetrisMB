//
//  globals.h
//  Tetris
//
//  Created by Abhishek Marda on 8/28/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#ifndef globals_h
#define globals_h
#include <iostream>
#include <string>

#define TRUE_RANDOM_SIZE_4_DISTRIBUTION 0

/* TIME CONSTANTS*/
const double /*could also be chrono*/ TICK_INTERVAL = 0.01;
const double /*could also be chrono*/ BLOCK_DROP_INTERVAL = 0.75;

/* CELL VALUES */
const char OCCUPIED_CELL = '#';
const char EMPTY_CELL = ' ';
const char GRID_BOUNDARY = 'X';

/* GRID CONSTRUCTORS */
const std::string GRID_ROW_DIVIDER = ".---";
const char GRID_CORNER = '.';
const char GRID_COL_DIVIDER = '|';

/* GRID SIZE */
const int MAX_ROWS = 30;    // +5 for upcomingBlock
const int MAX_COLS = 11;
const int BUFFER_ROWS = 5;
const int UPBLK_COLS = 5;
const int UPBLK_ROWS = 17;
const int PRINT_ROWS = MAX_ROWS - BUFFER_ROWS;
const int PRINT_COLS = MAX_COLS;
const int PRINT_ROW_INDEX = 5;  //the row index in the grid from which printing must begin

/* GRID ALIGNMENT */
const int GRID_LEFT_MARGIN = 5;
const int GRID_TOP_MARGIN = 1;

/* BLOCK SIZE */
const int BLOCK_SIZE = 4;

/* MOVE DIRECTIONS */
const char L = 'a';
const char R = 'd';
const char U = 'w';
const char D = 's';

/* TEXT COLORS IN LINUX CLI */
const char BEGIN_CYAN_REGULAR[] = "\033[;36m";
const char BEGIN_GREEN_REGULAR[] = "\033[;32m";
const char BEGIN_MAGENTA_REGULAR[] = "\033[;35m";
const char BEGIN_RED_BGBLACK[] = "\033[31;40m";
const char RESET_FORMAT[] = "\033[0m";


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
