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
	Wt_App_Interface(){}
	~Wt_App_Interface(){}
public:
     virtual void init()    = 0;
     virtual void display() = 0;
     virtual void update()  = 0;
     virtual void mouse(int button, int state, int x, int y) = 0;
     virtual void motion(int x, int y) = 0;
};

#endif /* defined(__wt_water3__wt_app_interface__) */
