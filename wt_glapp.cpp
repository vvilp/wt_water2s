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
}

void display(void)
{
    app->display();
}

void update(void)
{
    app->update();
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
    init();
    Wt_OpenGL gl;
    gl.init(600, 600);
    gl.run(display, update);
}

