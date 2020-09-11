//
//  Utilities.cpp
//  Tetris
//
//  Created by Sanchit Agarwal on 9/11/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include <stdio.h>
#include "Utilities.h"



// utilities.cpp
#include <random>
#include <utility>
using namespace std;

static random_device rd;
static default_random_engine generator(rd());



// Return a uniformly distributed random integer from lowest to highest inclusive

int randInt(int lowest, int highest)
{
    if (highest < lowest)
        swap(highest, lowest);
    uniform_int_distribution<> distro(lowest, highest);
    return distro(generator);
}



// Return a uniformly distributed random integer from 0 to limit-1 inclusive
int randInt(int limit)
{
    return randInt(0, limit-1);
}


// return true with a given probability
bool trueWithProbability(double p)
{
    uniform_real_distribution<> distro(0, 1);
    return distro(generator) < p;
}


int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}



#ifdef _MSC_VER  //  Microsoft Visual C++
#include <windows.h>
#include <conio.h>

void clearScreen()

{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,&dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>

using namespace std;
static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal escape sequence:  ESC [
static const char* ESC_SEQ_X = "\xEF\x9C";  // Xcode Console arrow key escape sequence
class TerminalModeSetter
{
public:
    TerminalModeSetter()
    {
        tcgetattr(STDIN_FILENO, &m_old);
        m_new = m_old;
        m_new.c_lflag &= ~(ICANON | ECHO);
        m_new.c_cc[VMIN] = 1;
        m_new.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &m_new);
    }
    ~TerminalModeSetter()
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &m_old);
    }
    
private:
    
    termios m_old;
    termios m_new;
    
};




// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.  (The Xcode output window doesn't have the capability
// of being cleared.)



void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
}



#endif


