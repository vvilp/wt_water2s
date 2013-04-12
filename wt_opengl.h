//
//  wt_opengl.h
//  wt_water3
//
//  Created by vvilp on 4/12/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#ifndef __wt_water3__wt_opengl__
#define __wt_water3__wt_opengl__


class Wt_OpenGL {
public:
    Wt_OpenGL();
    ~Wt_OpenGL();
    
public:
    int win_w;
    int win_h;
    
public:
    void init(int win_w, int win_h);
    void run(void display_func(void));
};



#endif /* defined(__wt_water3__wt_opengl__) */
