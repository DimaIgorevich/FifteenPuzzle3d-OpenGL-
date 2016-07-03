//
//  OpenGLWindow.cpp
//  MIC++
//
//  Created by Admin on 08.06.16.
//  Copyright © 2016 DimaRumyankov. All rights reserved.
//

#include "OpenGLWindow.hpp"
#include "Container.hpp"
#include "GLShape.hpp"

#define NULL_POSITION 0

static GLfloat whiteLight[3] = {1.0f, 1.0f, 1.0f};
static GLfloat lightPosition[4] = {0.0f, 0.0f, 0.0f, 1.0f};

bool OpenGLWindow::isAnimated_ = false;

GLfloat OpenGLWindow::xPos_ = NULL_POSITION;
GLfloat OpenGLWindow::yPos_ = NULL_POSITION;
GLfloat OpenGLWindow::zPos_ = NULL_POSITION;

GLfloat OpenGLWindow::xRotate_ = NULL_POSITION;
GLfloat OpenGLWindow::yRotate_ = NULL_POSITION;
GLfloat OpenGLWindow::zRotate_ = NULL_POSITION;

static int indexStep = 0;

OpenGLWindow::OpenGLWindow(int argc, char * argv[]){
    indexStep = (int)Container::sharedManager().getPathNodes()->size()-1;
    
    argc_ = argc;
    argv_ = argv;
    
    isAnimated_ = false;
    
    xRotate_ = yRotate_ = zRotate_ = NULL_POSITION;
    xPos_ = yPos_ = NULL_POSITION;
    zPos_ = -4.0f;
}

void OpenGLWindow::show(){
    glutInit(&argc_, argv_);
    createGlutWindow();
    createGlutCallbacks();
    initOpenGL();
    glutSpecialFunc(processPressKeys);
    
    glutMainLoop();
    
    exitGlut();
}

//private methods

//Glut methods
void OpenGLWindow::initOpenGL(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, 1.0, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    
    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteLight);
    glEnable(GL_LIGHT0);
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void OpenGLWindow::createGlutWindow(){
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition (10, 10);
    glutInitWindowSize (512, 512);
    win_ = glutCreateWindow ("Cube");
}

void OpenGLWindow::createGlutCallbacks(){
    glutDisplayFunc(display);
    glutIdleFunc(idle);
}

void OpenGLWindow::exitGlut(){
    glutDestroyWindow(win_);
    exit(0);
}

//GLOpenGLWindow private methods
void OpenGLWindow::setCamera(){
    //Postion
    glTranslatef(xPos_,yPos_,zPos_);
    
    //Rotation
    glRotatef(20.0f, 1.0, 0.0, 0.0);
    glRotatef(yRotate_, 1.0, 0.0, 0.0);
    glRotatef(xRotate_, 0.0, 1.0, 0.0);
}
void OpenGLWindow::drawScene(){
    GLShape::drawOrtogonalLines();
    
    Node *currentNode = Container::sharedManager().getPathNodes()->at(indexStep);
    
    int index = 0;
    int interval = 4;
    for(int z = 2; z > -2; z--){
        for(int y = 2; y > -2; y--){
            for(int x = -2; x < 2; x++){
                if(currentNode->nodeContainer_->at(index) != 0){
                    string name = to_string(currentNode->nodeContainer_->at(index));
                    GLShape::drawCube3i(interval*x, interval*y, interval*z, name);
                }
                index++;
            }
        }
        
    }
}

void OpenGLWindow::display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glPopMatrix();
    
    setCamera();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    drawScene();
    
    glutSwapBuffers();
}

void OpenGLWindow::idle(){
    if(isAnimated_){
        xRotate_ += 0.2;
    }
    glutPostRedisplay();
}

void OpenGLWindow::processPressKeys(int key, int x, int y){
    printf("GLUT_KEY_NEXT(ENTER) %d\n",key);
    
    float delta = 0.5f;
    
    switch (key)
    {
        case 3: {
            printf("GLUT_KEY_NEXT(ENTER) %d\n",key);
            if(indexStep > 0){
                indexStep--;
            }
        };break;
        case 27 :      break;
        case 43:{
            printf("GLUT_KEY_+ %d\n",key);
            zPos_ += delta;
        };break;
        case 45:{
            printf("GLUT_KEY_- %d\n",key);
            zPos_ -= delta;
        };break;
        case 52:{
            xRotate_ += 2.2f;
        };break;
        case 54:{
            xRotate_ -= 2.2f;
        };break;
        case 50:{
            yRotate_ -= 2.2f;
        };break;
        case 56:{
            yRotate_ += 2.2f;
        };break;
        case 97:{
            isAnimated_ = !isAnimated_;
        };break;
        case 100 : {
            printf("GLUT_KEY_LEFT %d\n",key);
            xPos_ += delta;
        }; break;
        case 102:{
            
            printf("GLUT_KEY_RIGHT %d\n",key);
            xPos_ -= delta;
        }; break;
        case 101:{
            printf("GLUT_KEY_UP %d\n",key);
            yPos_ -= delta;
        }; break;
        case 103 :{
            printf("GLUT_KEY_DOWN %d\n",key);
            yPos_ += delta;
        }; break;
    }
    
    glutPostRedisplay();
}