//
//  wt_sample.h
//  wt_water3
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_sample__
#define __wt_water3__wt_sample__

#include "wt_app_interface.h"

class Wt_Sample : public Wt_App_Interface{
    
    
public:
	virtual void init();
    virtual void display();
    virtual void update();
    virtual void mouse(int button, int state, int x, int y);
    virtual void motion(int x, int y);

};

#endif /* defined(__wt_water3__wt_sample__) */
