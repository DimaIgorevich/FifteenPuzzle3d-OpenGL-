//
//  Dirrection.cpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "Dirrection.hpp"
#define YES true
#define NO false

DirrectionStruct Dirrection::byIndex(int indexEmptyCell){
    DirrectionStruct dirrection;
    dirrection.downDirrect = dirrection.upDirrect = dirrection.leftDirrect = dirrection.rightDirrect = dirrection.forwardDirrect = dirrection.backDirrect = NO;
    
    if(indexEmptyCell == 22 || indexEmptyCell == 23 || indexEmptyCell == 26 || indexEmptyCell == 27 || indexEmptyCell == 38 || indexEmptyCell == 39 || indexEmptyCell == 42 || indexEmptyCell == 43){
        dirrection = allDirection();
    } else if(indexEmptyCell == 18 || indexEmptyCell == 19 || indexEmptyCell == 34 || indexEmptyCell == 35){
        dirrection.backDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 30 || indexEmptyCell == 31 || indexEmptyCell == 46 || indexEmptyCell == 47){
        dirrection.backDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.leftDirrect = dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 20 || indexEmptyCell == 36){
        dirrection.backDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 17 || indexEmptyCell == 33){
        dirrection.forwardDirrect = YES;
        dirrection.backDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 29 || indexEmptyCell == 45){
        dirrection.backDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 32 || indexEmptyCell == 48){
        dirrection.forwardDirrect = YES;
        dirrection.backDirrect = YES;
        dirrection.downDirrect= YES;
        dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 24 || indexEmptyCell == 28 || indexEmptyCell == 40 || indexEmptyCell == 44){
        dirrection.forwardDirrect = YES;
        dirrection.backDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 21 || indexEmptyCell == 25 || indexEmptyCell == 37 || indexEmptyCell == 41){
        dirrection.backDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 1){
        dirrection.backDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 13){
        dirrection.downDirrect = YES;
        dirrection.backDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 4){
        dirrection.backDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 16){
        dirrection.backDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 6 || indexEmptyCell == 7 || indexEmptyCell == 10 || indexEmptyCell == 11){
        dirrection.backDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
    } else if(indexEmptyCell == 54 || indexEmptyCell == 55 || indexEmptyCell == 58 || indexEmptyCell == 59){
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
    } else if(indexEmptyCell == 2 || indexEmptyCell == 3){
        dirrection.leftDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.backDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 14 || indexEmptyCell == 15){
        dirrection.downDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.backDirrect = YES;
    } else if(indexEmptyCell == 5 || indexEmptyCell == 9){
        dirrection.backDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 8 || indexEmptyCell == 12){
        dirrection.backDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.rightDirrect = YES;
    } else if(indexEmptyCell == 49){
        dirrection.forwardDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 52){
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 61){
        dirrection.forwardDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.downDirrect = YES;
    } else if(indexEmptyCell == 64){
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.downDirrect = YES;
    } else if(indexEmptyCell == 62 || indexEmptyCell == 63){
        dirrection.forwardDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.downDirrect = YES;
    } else if(indexEmptyCell == 50 || indexEmptyCell == 51){
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
        dirrection.leftDirrect = YES;
        dirrection.upDirrect = YES;
    } else if(indexEmptyCell == 53 || indexEmptyCell == 57){
        dirrection.forwardDirrect = YES;
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.leftDirrect = YES;
    } else if(indexEmptyCell == 56 || indexEmptyCell == 60){
        dirrection.upDirrect = YES;
        dirrection.downDirrect = YES;
        dirrection.forwardDirrect = YES;
        dirrection.rightDirrect = YES;
    }
    
    return dirrection;
}

DirrectionStruct Dirrection::allDirection(){
    DirrectionStruct dirrection;
    dirrection.downDirrect = YES;
    dirrection.leftDirrect = YES;
    dirrection.rightDirrect = YES;
    dirrection.upDirrect = YES;
    dirrection.backDirrect = YES;
    dirrection.forwardDirrect = YES;
    return dirrection;
}
