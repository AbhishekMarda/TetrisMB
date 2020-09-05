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

int main(int argc, const char * argv[]) {

/*
 What the main function will look like:
 
 Engine engine;
 engine.run();
 
 NOTE: we could also probably add optional parameters to run() from argc and argv later on in case we want the user to customize the game.
 */

    Engine e;
    e.printBoard();
}
