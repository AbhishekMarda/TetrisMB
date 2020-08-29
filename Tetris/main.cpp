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

//    Block b;
//    b.rotate(CLOCKWISE);
//
//    return 0;
    
    Grid g;
    
    std::vector<Unit> my;
    my.push_back(Unit(10,4));
    my.push_back(Unit(10,5));
    my.push_back(Unit(10,6));
    my.push_back(Unit(9,5));
    
    Block b(my);
    
//    g.hardcodeBlock(&b);
    g.printGrid();
    
    g.eliminateRow(9);
    g.printGrid();

}
