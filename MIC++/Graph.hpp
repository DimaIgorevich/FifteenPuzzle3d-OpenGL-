//
//  Graph.hpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "Node.hpp"

class Graph{
    Node *startNode_;
    
    void initGameState(vector<int> gameState);
public:
    Graph(vector<int> gameState);
    void drawGraph();
};

#endif /* Graph_hpp */
