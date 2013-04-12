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
Wt_GLApp::Wt_GLApp()
{
    
}
Wt_GLApp::~Wt_GLApp()
{
    
}

void display(void)
{
    Wt_Sample sample;
    sample.display();
}

void Wt_GLApp::run()
{
    Wt_OpenGL gl;
    gl.init(600, 600);
    gl.run(display);
}

