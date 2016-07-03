//
//  Graph.cpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(vector<int> gameState){
    startNode_ = new Node();
    startNode_->parrentNode_ = NULL;
    startNode_->type_ = kStartNode;
    startNode_->g_ = kStartNode;
    
    initGameState(gameState);
}

void Graph::drawGraph(){
    startNode_->drawChild();
}

//private:

void Graph::initGameState(vector<int> gameState){
    startNode_->nodeContainer_ = new vector<int>(gameState.size());
    for(int i = 0; i < gameState.size(); i++){
        startNode_->nodeContainer_->at(i) = gameState.at(i);
    }
}