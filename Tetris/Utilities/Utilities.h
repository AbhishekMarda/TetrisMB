//
//  utilities.hpp
//  Tetris
//
//  Created by Sanchit Agarwal on 9/11/20.
//  WE DO NOT CLAIM OWNERSHIP OVER ANY OF THE FILES IN UTILITIES.H AND UTILITIES.CPP. WE HAVE PUT TOGETHER THIS CODE FROM VARIOUS SOURCES INCLUDING UCLA CS DEPARTMENT
//  AND OTHER ONLINE AUTHORS
//
//

#ifndef UTILITIES_INCLUDED
#define UTILITIES_INCLUDED
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

void clearScreen();

int randInt(int lowest, int highest);  // random int from lowest to highest

int randInt(int limit);                // random int from 0 to limit-1

bool trueWithProbability(double p);    // return true with probability p


int kbhit(void);


#endif // UTILITIES_INCLUDED
