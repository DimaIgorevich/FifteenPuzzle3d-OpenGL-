//
//  Node.hpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#define FIRST_NODE 0

#include <stdio.h>

#include "Dirrection.hpp"
#include <vector>

#include <iostream>
using namespace std;

#define terminalPattern "1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162630"


typedef enum{
    kStartNode,
    kLeftNode,
    kRigthNode,
    kDownNode,
    kUpNode,
    kBackNode,
    kForwardNode,
    kNanNode
}typeNode;

class Node{
    void initVector(vector<int>* nodeContainer);
    void solveColission();
    void debug(Node *node);
    void generateContainer();
    
    int func();
    int height();
    
    
public:
    int g_;
    int h_;
    int f_;
    
    typeNode type_;
    Node *parrentNode_;
    
    Node *leftNode_;
    Node *rightNode_;
    Node *downNode_;
    Node *upNode_;
    Node *forwardNode_;
    Node *backNode_;
    
    vector<int>* nodeContainer_;
    
    Node();
    Node(Node *parrentNode, typeNode type, int down);
    
    void drawChild();
    
    string *getCurrentState();
    
};

#endif /* Node_hpp */
