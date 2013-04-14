//
//  Wt_GLApp.cpp
//  wt_water3
//
//  Created by vvilp on 4/12/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#include "Wt_glapp.h"
#include "wt_opengl.h"
#include "wt_sample.h"
#include "wt_FluidLB.h"
Wt_App_Interface *app;

void init()
{
    app = new Wt_FluidLB();
    app->init();
}

void display(void)
{
    app->display();
}

void update(void)
{
    app->update();
}

void mouse(int button, int state, int x, int y)
{
    app->mouse(button, state, x, y);
}

void motion(int x, int y)
{
    app->motion(x, y);
}

//-------------------------------
Wt_GLApp::Wt_GLApp()
{

}
Wt_GLApp::~Wt_GLApp()
{
    
}
void Wt_GLApp::run()
{
    
    Wt_OpenGL gl;
    gl.init(600, 600);
    init();
    gl.run(display, update, mouse, motion);
}

