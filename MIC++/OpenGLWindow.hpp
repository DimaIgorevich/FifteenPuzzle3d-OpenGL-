//
//  OpenGLWindow.hpp
//  MIC++
//
//  Created by Admin on 08.06.16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#ifndef OpenGLWindow_hpp
#define OpenGLWindow_hpp

#include <stdio.h>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

class OpenGLWindow{
    int win_;
    static bool isAnimated_;
    
    int argc_;
    char **argv_;
    
    //Rotate-coordinate
    static GLfloat xRotate_;
    static GLfloat yRotate_;
    static GLfloat zRotate_;
    
    //Position-coordinate
    static GLfloat xPos_;
    static GLfloat yPos_;
    static GLfloat zPos_;
    
    //Glut methods
    void initOpenGL();
    void createGlutWindow();
    void createGlutCallbacks();
    void exitGlut();
    
    //GLOpenGLWindow private methods
    static void setCamera();
    static void drawScene();
    static void display();
    static void idle();
    static void processPressKeys(int key, int x, int y);
    
public:
    
    OpenGLWindow(int argc, char * argv[]);
    void show();
};


#endif /* OpenGLWindow_hpp */
