//
//  main.cpp
//  Tetris
//
//  Created by Abhishek Marda on 8/26/20.
//  Copyright © 2020 Abhishek Marda. All rights reserved.
//

#include <iostream>
#include "globals.h"
#include "Block.h"
#include "Engine.h"
#include "Grid.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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

int doSomething(int temp = 0)
{
    if (temp)
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {

    while(true)
    {
        if(kbhit())
        {
            std::cout << "You pressed " << (char)getchar() <<std::endl;
        }
    }
        
/*
 What the main function will look like:
 
 Engine engine;
 engine.run();
 
 NOTE: we could also probably add optional parameters to run() from argc and argv later on in case we want the user to customize the game.
 */

//    Engine e;
//
//    delete e.generateNewBlock(5);
    
    
    

}
