//
//  GLShape.cpp
//  MIC++
//
//  Created by Admin on 08.06.16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "GLShape.hpp"
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void GLShape::drawOrtogonalLines(){
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3i(0, 0, 0);
    glVertex3i(50, 0, 0);
    glVertex3i(0, 0, 0);
    glVertex3i(0, 50, 0);
    glVertex3i(0, 0, 0);
    glVertex3i(0, 0, 50);
    glEnd();
}

void GLShape::drawCube3i(int x, int y, int z, string nameCube){
    drawText3i(x, y, z, nameCube);
    
    glColor4f(0.5f, 0.5f, 1.0f, 0.6f);
    glPushMatrix();
    glBegin (GL_QUADS);
    glNormal3f(0.0+x, 0.0+y, 1.0+z);
    glVertex3f(1.0+x, 1.0+y, 1.0+z);
    glVertex3f(-1.0+x, 1.0+y, 1.0+z);
    glVertex3f(-1.0+x, -1.0+y, 1.0+z);
    glVertex3f(1.0+x, -1.0+y, 1.0+z);
    glEnd();
    
    glBegin (GL_QUADS);
    glNormal3f(0.0+x, 0.0+y, -1.0+z);
    glVertex3f (1.0+x, 1.0+y, -1.0+z);
    glVertex3f (1.0+x, -1.0+y, -1.0+z);
    glVertex3f (-1.0+x, -1.0+y, -1.0+z);
    glVertex3f (-1.0+x, 1.0+y, -1.0+z);
    glEnd();
    
    glBegin (GL_QUADS);
    glNormal3f(-1.0+x, 0.0+y, 0.0+z);
    glVertex3f (-1.0+x, 1.0+y, 1.0+z);
    glVertex3f (-1.0+x, 1.0+y, -1.0+z);
    glVertex3f (-1.0+x, -1.0+y, -1.0+z);
    glVertex3f (-1.0+x, -1.0+y, 1.0+z);
    glEnd();
    
    glBegin (GL_QUADS);
    glNormal3f(1.0+x, 0.0+y, 0.0+z);
    glVertex3f (1.0+x, 1.0+y, 1.0+z);
    glVertex3f (1.0+x, -1.0+y, 1.0+z);
    glVertex3f (1.0+x, -1.0+y, -1.0+z);
    glVertex3f (1.0+x, 1.0+y, -1.0+z);
    glEnd();
    
    glBegin (GL_QUADS);
    glNormal3f(0.0+x, 1.0+y, 0.0+z);
    glVertex3f (-1.0+x, 1.0+y, -1.0+z);
    glVertex3f (-1.0+x, 1.0+y, 1.0+z);
    glVertex3f (1.0+x, 1.0+y, 1.0+z);
    glVertex3f (1.0+x, 1.0+y, -1.0+z);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0+x, -1.0+y, 0.0+z);
    glVertex3f (-1.0+x, -1.0+y, -1.0+z);
    glVertex3f (1.0+x, -1.0+y, -1.0+z);
    glVertex3f (1.0+x, -1.0+y, 1.0+z);
    glVertex3f (-1.0+x, -1.0+y, 1.0+z);
    glEnd();
    glPopMatrix();
}

void GLShape::drawText3i(int x, int y, int z, string text){
    glColor3f(0.0f, 1.0f, 0.0f);
    glDisable(GL_LIGHTING);
    glRasterPos3f(x, y, z);
    for(int i = 0; i < text.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
    }
    glEnable(GL_LIGHTING);
}