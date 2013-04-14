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


void Wt_OpenGL_Mouse_Func(int button, int state, int x, int y)
{
    Wt_OpenGL::mouse_press_x = Wt_OpenGL::mouse_x = x;
    Wt_OpenGL::mouse_press_y = Wt_OpenGL::mouse_y = Wt_OpenGL::win_h - y;
    if (button == 0) {
        Wt_OpenGL::mouse_left_press = state == GLUT_DOWN;
    }else if (button == 2) {
        Wt_OpenGL::mouse_right_press = state == GLUT_DOWN;
    }
    Dbg("button : %d | x : %d , y : %d | view_x : %d , view_y : %d | state : %d \n", button, x, y, Wt_OpenGL::mouse_x, Wt_OpenGL::mouse_y, state);
}

void Wt_OpenGL_Mouse_Motion_Func(int x, int y)
{
    Dbg("Motion : x : %d , y : %d \n", x, y);
    Wt_OpenGL::mouse_x = x;
    Wt_OpenGL::mouse_y = Wt_OpenGL::win_h - y;
}

//----------------------------------------------------------------------------
bool Wt_OpenGL::mouse_right_press = false;
bool Wt_OpenGL::mouse_left_press = false;
int  Wt_OpenGL::mouse_press_x = 0;
int  Wt_OpenGL::mouse_press_y = 0;
int  Wt_OpenGL::mouse_x = 0;
int  Wt_OpenGL::mouse_y = 0;
int  Wt_OpenGL::win_w = 0;
int  Wt_OpenGL::win_h = 0;
Wt_OpenGL::Wt_OpenGL()
{
    
}

Wt_OpenGL::~Wt_OpenGL()
{
    
}

void Wt_OpenGL::init(int win_w, int win_h)
{
    this -> win_w = win_w;
    this -> win_h = win_h;
    int argc = 0;
    char ** argv = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (win_w, win_h);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OpenGL WaterZ3");

}

void Wt_OpenGL::run(void display(void), void update(void), void mouse(int , int , int , int), void motion(int , int))
{
    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    //glutMouseFunc(Wt_OpenGL_Mouse_Func);
    //glutMotionFunc(Wt_OpenGL_Mouse_Motion_Func);
    glutMainLoop();
}

void Wt_OpenGL::draw_partical(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}