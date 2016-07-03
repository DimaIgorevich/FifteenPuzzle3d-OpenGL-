//
//  Node.cpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "Node.hpp"
#include "Container.hpp"
#include <algorithm>

Node::Node(){
    parrentNode_ = NULL;
}

Node::Node(Node *parrentNode, typeNode type, int down){
    parrentNode_ = parrentNode;
    type_ = type;
    nodeContainer_ = new vector<int>(parrentNode_->nodeContainer_->size());
    initVector(parrentNode_->nodeContainer_);
    
    g_ = down;
    generateContainer();
    
    h_ = height();
    f_ = func();
}

string *Node::getCurrentState(){
    string *state = new string("");
    
    for(int i = 0; i < nodeContainer_->size(); i++){
        *state += std::to_string(nodeContainer_->at(i));
    }
    
    return state;
}

void Node::drawChild(){
    h_ = height();
    f_ = func();
    
    cout<<"g: "<<g_<<" h: "<<h_<<" f: "<<f_<<"\n";
    
    //add self to open list
    Container::sharedManager().getOpenNodes()->push_back(this);
    
    //check terminal state
    string *currentState  = getCurrentState();
    
    if(currentState->compare(terminalPattern) != 0){
        cout<<"not terminate\n";
        
        const vector<string*>::const_iterator position = find(Container::sharedManager().getNodes()->begin(), Container::sharedManager().getNodes()->end(), currentState);
        
        if(position == Container::sharedManager().getNodes()->end()){
            
            const vector<int>::const_iterator position = find(nodeContainer_->begin(), nodeContainer_->end(), kStartNode);
            
            const vector<int>::size_type index = position - nodeContainer_->begin();
            
            DirrectionStruct direction = Dirrection::byIndex((int)index+1);
            
            vector<Node *>* currentNodes = new vector<Node *>(0);
            
            int newG = 1;
            newG += g_;
            
            if(direction.leftDirrect){
                leftNode_ = new Node(this, kLeftNode, newG);
                currentNodes->push_back(leftNode_);
            }
            if(direction.rightDirrect){
                rightNode_ = new Node(this, kRigthNode, newG);
                currentNodes->push_back(rightNode_);
            }
            if(direction.downDirrect){
                downNode_ = new Node(this, kDownNode, newG);
                currentNodes->push_back(downNode_);
            }
            if(direction.upDirrect){
                upNode_ = new Node(this, kUpNode, newG);
                currentNodes->push_back(upNode_);
            }
            if(direction.backDirrect){
                backNode_ = new Node(this, kBackNode, newG);
                currentNodes->push_back(backNode_);
            }
            if(direction.forwardDirrect){
                forwardNode_ = new Node(this, kForwardNode, newG);
                currentNodes->push_back(forwardNode_);
            }
            
            //check contain nodes in closeList and add to open
            for(int i = 0; i < currentNodes->size(); i++){
                const vector<string*>::const_iterator position = find(Container::sharedManager().getNodes()->begin(), Container::sharedManager().getNodes()->end(), currentNodes->at(i)->getCurrentState());
                if(position == Container::sharedManager().getNodes()->end()){
                    if(currentNodes->at(i)->g_ < 30){
                        Container::sharedManager().getOpenNodes()->push_back(currentNodes->at(i));
                    }
                }
            }
            
            //delete parrent node from open list and add to close list
            const vector<Node*>::const_iterator deleteIterator = find(Container::sharedManager().getOpenNodes()->begin(), Container::sharedManager().getOpenNodes()->end(), this);

            Container::sharedManager().getOpenNodes()->erase(deleteIterator);
            
            Container::sharedManager().getNodes()->push_back(getCurrentState());
            
            //check TUPIC SOLVE
            
            
            //set first object NODE*
            Node *nextNode = NULL;
            
            int indexObject = 0;
            while((nextNode == NULL) && (indexObject < currentNodes->size())){
                const vector<string*>::const_iterator position = find(Container::sharedManager().getNodes()->begin(), Container::sharedManager().getNodes()->end(), currentNodes->at(indexObject)->getCurrentState());
                if(position == Container::sharedManager().getNodes()->end()){
                    nextNode = currentNodes->at(indexObject);
                }
                indexObject++;
            }
            
            if((nextNode == NULL) || (g_ > 30)){
                solveColission();
            } else {
                //get optimal variant from all set
                for(int i = indexObject; i < currentNodes->size(); i++){
                    if(nextNode->f_ > currentNodes->at(i)->f_){
                        const vector<string*>::const_iterator position = find(Container::sharedManager().getNodes()->begin(), Container::sharedManager().getNodes()->end(), currentNodes->at(i)->getCurrentState());
                        if(position == Container::sharedManager().getNodes()->end()){
                            nextNode = currentNodes->at(i);
                        }
                    }
                }
            
                //show Next Node
                debug(nextNode);
                
                //remove nextNode from openList
                const vector<Node*>::const_iterator position = find(Container::sharedManager().getOpenNodes()->begin(), Container::sharedManager().getOpenNodes()->end(), nextNode);
                
                Container::sharedManager().getOpenNodes()->erase(position);
                
                //to next optimal Node
                nextNode->drawChild();
            }
            
        } else {
            const vector<Node*>::const_iterator position = find(Container::sharedManager().getOpenNodes()->begin(), Container::sharedManager().getOpenNodes()->end(), this);
            
            Container::sharedManager().getOpenNodes()->erase(position);
            
            solveColission();
        }
        
    } else {
        cout<<"end\n";
        //create resultative path
        Container::sharedManager().getPathNodes()->push_back(this);
        
        while((Node *)(*(Container::sharedManager().getPathNodes()->end() - 1))->parrentNode_ != NULL){
            Container::sharedManager().getPathNodes()->push_back((Node *)(*(Container::sharedManager().getPathNodes()->end()-1))->parrentNode_);
        }
        
        
        //remove start state
        //Container::sharedManager().getPathNodes()->erase((Container::sharedManager().getPathNodes()->end()-1));
        
        cout<<"step count: "<<Container::sharedManager().getPathNodes()->size()<<"\n";
        
        //send message
        cout<<"ready!!!\n";
        
    }
    
}

//private

void Node::solveColission(){
    Node *nextNode = NULL;
    
    //get first node from open list
    nextNode = Container::sharedManager().getOpenNodes()->at(FIRST_NODE);

    //remove node from open list
    Container::getOpenNodes()->erase(Container::sharedManager().getOpenNodes()->begin()+FIRST_NODE);

    //show Next Node
    debug(nextNode);

    //draw next node
    cout<<"count node in open list: "<<Container::sharedManager().getOpenNodes()->size()<<"\n";

    nextNode->drawChild();
}

void Node::debug(Node *node){
    for(int i = 0; i < node->nodeContainer_->size(); i++){
        if(i % 16 == 0){
            cout<<"\n\n"<<node->nodeContainer_->at(i);
        } else if(i % 4 == 0){
            cout<<"\n"<<node->nodeContainer_->at(i);
        } else {
            cout<<node->nodeContainer_->at(i);
        }
    }
}

void Node::initVector(vector<int>* nodeContainer){
    for(int i = 0; i < nodeContainer->size(); i++){
        nodeContainer_->at(i) = nodeContainer->at(i);
    }
}

int Node::func(){
    return h_ + g_;
}

int Node::height(){
    int h = 0;
    for(int i = 0; i < nodeContainer_->size(); i++){
        if(Container::sharedManager().getTerminatePattern()->at(i) != nodeContainer_->at(i)){
            h++;
        }
    }
    return h;
}

void Node::generateContainer(){
    const vector<int>::const_iterator position = find(parrentNode_->nodeContainer_->begin(), parrentNode_->nodeContainer_->end(), kStartNode);
    
    const vector<int>::size_type indexEmptyCell = position - parrentNode_->nodeContainer_->begin();
    
    if(type_ == kLeftNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell+1);
        nodeContainer_->at(indexEmptyCell+1) = kStartNode;
    }
    if(type_ == kRigthNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell-1);
        nodeContainer_->at(indexEmptyCell-1) = kStartNode;
    }
    if(type_ == kUpNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell+4);
        nodeContainer_->at(indexEmptyCell+4) = kStartNode;
    }
    if(type_ == kDownNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell-4);
        nodeContainer_->at(indexEmptyCell-4) = kStartNode;
    }
    if(type_ == kForwardNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell-16);
        nodeContainer_->at(indexEmptyCell-16) = kStartNode;
    }
    if(type_ == kBackNode){
        nodeContainer_->at(indexEmptyCell) = nodeContainer_->at(indexEmptyCell+16);
        nodeContainer_->at(indexEmptyCell+16) = kStartNode;
    }
}