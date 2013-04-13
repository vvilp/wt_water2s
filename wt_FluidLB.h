//
//  lattice boltzmann Method simulate the Flow
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_FluidLB__
#define __wt_water3__wt_FluidLB__

#include "wt_app_interface.h"

class Wt_FluidLB : public Wt_App_Interface
{
public:
    
    virtual void display();
    virtual void update();
};

#endif /* defined(__wt_water3__wt_FluidLB__) */
