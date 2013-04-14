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
    static int win_w;
    static int win_h;
    
    static bool mouse_right_press;
    static bool mouse_left_press;
    static int mouse_press_x;
    static int mouse_press_y;
    static int mouse_x;
    static int mouse_y;
    
public:
    void init(int win_w, int win_h);
    void run(void display(void), void update(void), void mouse(int , int , int , int), void motion(int , int));
    static void draw_partical(float x, float y);
};



#endif /* defined(__wt_water3__wt_opengl__) */
