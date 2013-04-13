//
//  wt_app_interface.h
//  wt_water3
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_app_interface__
#define __wt_water3__wt_app_interface__

class Wt_App_Interface
{
public:
     virtual void init()    = 0;
     virtual void display() = 0;
     virtual void update()  = 0;
    
};

#endif /* defined(__wt_water3__wt_app_interface__) */
