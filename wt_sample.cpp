//
//  wt_sample.cpp
//  wt_water3
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#include "wt_sample.h"
#include <GLUT/glut.h>
#include "wt_config.h"
#include <cmath>
void Wt_Sample::display()
{
    int i; double angle;
    glClear(GL_COLOR_BUFFER_BIT);
    for (i=0; i<360; i+=4) {
        
        glColor3f(float(i)/360.0,1.0,1.0);
        glBegin(GL_LINES);
        glVertex2d(cos(i/57.25779),sin(i/57.25779));
        glVertex2d(cos((i+90)/57.25779),sin((i+90)/57.25779));
        glEnd();
        
        glColor3f(1.0,float(i)/360.0,1.0);
        glBegin(GL_LINES);
        glVertex2d(cos(i/57.25779),sin(i/57.25779));
        glVertex2d(cos((i*2)/57.25779),sin((i+90)/57.25779));
        glEnd();
    }
    glLoadIdentity();
    glutSwapBuffers();
}

void Wt_Sample::update()
{
    
}

void Wt_Sample::mouse(int button, int state, int x, int y)
{
    //app->mouse(button, state, x, y);
}

void Wt_Sample::motion(int x, int y)
{
    //app->mouse_motion(x, y);
}