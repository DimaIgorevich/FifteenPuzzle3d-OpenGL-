//
//  Dirrection.hpp
//  MIC++
//
//  Created by dRumyankov on 6/6/16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef Dirrection_hpp
#define Dirrection_hpp

#include <stdio.h>
#include "DirrectionStruct.h"

class Dirrection{
    static DirrectionStruct allDirection();
public:
    static DirrectionStruct byIndex(int indexEmptyCell);
    
};

#endif /* Dirrection_hpp */
