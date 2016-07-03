//
//  Game.cpp
//  MIC++
//
//  Created by dRumyankov on 6/7/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "Game.hpp"

Game::Game():
    kCountCellSection(64),
    kCountCellInSection(4),
    kEmptyCell(0)
{
        container_ = new vector<int>(kCountCellSection);
        
        initGameState();
        
}

void Game::start(){
    gameGraph_ = new Graph(*container_);
    gameGraph_->drawGraph();
}

//private

void Game::initGameState(){
    *container_ = { 1,6,2,4,
                    9,5,7,8,
                    13,11,15,12,
                    14,10,16,32,
        
                    17,18,3,20,
                    21,23,19,24,
                    25,22,0,27,
                    29,30,31,28,
        
                    33,34,35,36,
                    37,38,39,40,
                    41,26,43,44,
                    45,42,46,48,
        
                    49,50,51,52,
                    53,54,55,56,
                    57,58,59,60,
                    61,62,47,63};
}