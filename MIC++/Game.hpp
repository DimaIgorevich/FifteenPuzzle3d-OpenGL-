//
//  Game.hpp
//  MIC++
//
//  Created by dRumyankov on 6/7/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Graph.hpp"

class Game{
    Graph *gameGraph_;
    bool isReadyPath_;
    
    vector<int>* container_;
    
    const int kCountCellSection;
    const int kCountCellInSection;
    const int kEmptyCell;
    
    void initGameState();
    
public:
    Game();
    
    void start();
};

#endif /* Game_hpp */
