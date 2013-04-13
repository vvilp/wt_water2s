//
//  wt_opengl.cpp
//  wt_water3
//
//  Created by vvilp on 4/12/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#include "wt_opengl.h"
#include "wt_config.h"
#include <GLUT/glut.h>

Wt_OpenGL::Wt_OpenGL()
{
    
}

Wt_OpenGL::~Wt_OpenGL()
{
    
}

void Wt_OpenGL::init(int win_w, int win_h)
{
    int argc = 0;
    char ** argv = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    this -> win_w = win_w;
    this -> win_h = win_h;
    glutInitWindowSize (win_w,win_h);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OpenGL WaterZ3");

}

void Wt_OpenGL::run(void display(void), void update(void))
{
    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutMainLoop();
}