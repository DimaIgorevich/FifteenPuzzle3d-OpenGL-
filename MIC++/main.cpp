//
//  main.cpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include <stdlib.h>
#include <iostream>

#include "OpenGLWindow.hpp"
#include "Game.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    
    Game *game = new Game();
    game->start();
    
    OpenGLWindow *glWindow = new OpenGLWindow(argc, argv);
    glWindow->show();
    
    return 0;
}
