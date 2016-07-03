//
//  Container.hpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include <vector>
#include <string.h>
#include <cstring>

#include "Node.hpp"

using namespace std;

class Container;

class ContainerDestroyer
{
private:
    Container* p_instance;
public:
    ~ContainerDestroyer();
    void initialize(Container* p );
};

class Container{
    static Container* p_instance;
    static ContainerDestroyer destroyer;
    
    static void initTerminmate();
    
    //fields:
    static vector<int>* terminatePattern_;
    
    static vector< string* > *nodes_;
    static vector<Node *> *pathNodes_;
    static vector<Node *> *openNodes_;
    static vector<Node *> *closeNodes_;
    
protected:
    Container() { }
    Container( const Container& );
    Container& operator=( Container& );
    ~Container() { }
    friend class ContainerDestroyer;
public:
    static Container& sharedManager();
    static vector< string* >* getNodes();
    static vector<Node *>* getOpenNodes();
    static vector<Node *>* getPathNodes();
    static vector<int>* getTerminatePattern();
};

#endif /* Container_hpp */
