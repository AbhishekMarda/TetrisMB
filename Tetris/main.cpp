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
#include "Utilities.h"
#include <stdlib.h>

using namespace std;
int main()
{
    

//cout << "\033[;32mGreen Text\033[0m\n";
//cout << "\033[4;33mYellow underlined text\033[0m\n";
//cout << "\033[;34mBlue text\033[0m\n";
    
    Engine engine;
    engine.run();
/*
 What the main function will look like:
 
 Engine engine;
 engine.run();
 
 NOTE: we could also probably add optional parameters to run() from argc and argv later on in case we want the user to customize the game.
 */
//
//    Engine e;
//
//    delete e.generateNewBlock(5);
    
    
    

}
