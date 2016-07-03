//
//  Container.cpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "Container.hpp"

#define SIZE_AREA 64

Container * Container::p_instance = 0;
ContainerDestroyer Container::destroyer;
vector< string* > *Container::nodes_ = new vector< string* >(0);
vector<int> *Container::terminatePattern_ = new vector<int>(0);
vector<Node *> *Container::openNodes_ = new vector<Node*>(0);
vector<Node *> *Container::closeNodes_ = new vector<Node*>(0);
vector<Node *> *Container::pathNodes_ = new vector<Node*>(0);

ContainerDestroyer::~ContainerDestroyer() {
    delete p_instance;
}

void ContainerDestroyer::initialize( Container* p ) {
    p_instance = p;
}

Container& Container::sharedManager() {
    if(!p_instance){
        nodes_ = new vector< string*  >(0);
        openNodes_ = new vector<Node*>(0);
        closeNodes_ = new vector<Node*>(0);
        pathNodes_ = new vector<Node*>(0);
        
        terminatePattern_ = new vector<int>(SIZE_AREA);
        initTerminmate();
        
        p_instance = new Container();
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}

vector< string* >* Container::getNodes(){
    return nodes_;
}

vector<int>* Container::getTerminatePattern(){
    return terminatePattern_;
}

vector<Node *>* Container::getOpenNodes(){
    return openNodes_;
}

vector<Node *>* Container::getPathNodes(){
    return pathNodes_;
}

void Container::initTerminmate(){
    for(int i = 0; i < SIZE_AREA; i++){
        terminatePattern_->at(i) = i+1;
    }
    
    terminatePattern_->at(SIZE_AREA-1) = 0;
}