//
//  lattice boltzmann Method simulate the Flow
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_FluidLB__
#define __wt_water3__wt_FluidLB__

#include "wt_app_interface.h"

#ifdef MAC
#include <GLUT/glut.h>
#endif

#ifdef LINUX
#include <GL/glut.h>
#endif

#include "wt_config.h"
#include <cmath>
#include "wt_LB_Grid.h"

struct wt_partical
{
    float x;
    float y;
};
class Wt_FluidLB : public Wt_App_Interface
{
public:
    Wt_FluidLB(){}
    ~Wt_FluidLB(){}
    virtual void init();
    virtual void display();
    virtual void update();
    virtual void mouse(int button, int state, int x, int y);
    virtual void motion(int x, int y);
    void particals_update();
private:
    Wt_LB_Grid *lb;
    int grid_count;
    wt_partical *particals;
    bool is_add_vel;
    int pre_mouse_x;
    int pre_mouse_y;
    int partical_count;
};

#endif 