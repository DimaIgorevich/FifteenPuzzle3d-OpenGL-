//
//  GLShape.hpp
//  MIC++
//
//  Created by Admin on 08.06.16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef GLShape_hpp
#define GLShape_hpp

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class GLShape{
public:
    static void drawOrtogonalLines();
    static void drawCube3i(int x, int y, int z, string nameCube);
    static void drawText3i(int x, int y, int z, string text);
};

#endif /* GLShape_hpp */
