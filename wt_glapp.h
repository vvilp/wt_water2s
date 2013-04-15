//
//  Wt_GLApp.h
//  wt_water3
//
//  Created by vvilp on 4/12/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__Wt_GLApp__
#define __wt_water3__Wt_GLApp__

#include "wt_config.h"
#include "wt_app_interface.h"
#include "wt_opengl.h"
#include "wt_sample.h"
#include "wt_FluidLB.h"
class Wt_GLApp
{
public:
    Wt_GLApp();
    ~Wt_GLApp();

    
    void run();
private:

};

#endif /* defined(__wt_water3__Wt_GLApp__) */
