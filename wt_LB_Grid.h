//
//  wt_LB_Grid.h
//  wt_water3
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_LB_Grid__
#define __wt_water3__wt_LB_Grid__

class Wt_LB_Grid
{
    
public:
    static int c[9][2];
    static float w[9];
    static float omga;
public:
    int grid_count;
    float **density;
    float ***vel;
    float ***f;
    float ***f_;
public:
    void   init(int grid_count);
    float  feq(int index, float density, float vel[2]);
    void   update_density_vel();
    void   stream();
    void   collide();
    void   update();
    void   set_vel(int x, int y, float vel[2]);
    float* get_vel(int x, int y);
};

#endif