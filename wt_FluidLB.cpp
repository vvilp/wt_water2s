//
//  lattice boltzmann Method simulate the Flow 
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#include "wt_FluidLB.h"
#include "wt_opengl.h"
#include <ctime>
#include <cstdlib>
void Wt_FluidLB::init()
{
    grid_count = 100;
    lb = new Wt_LB_Grid();
    lb->init(grid_count);
    
    srand(unsigned(time(0)));
    
    partical_count = 50000;
    particals = new wt_partical[partical_count];
    for(int i = 0 ; i < partical_count ; i++) {
        particals[i].x = rand() % Wt_OpenGL::win_w;
        particals[i].y = rand() % Wt_OpenGL::win_h;
    }
}

void Wt_FluidLB::display()
{
    glViewport ( 0, 0, Wt_OpenGL::win_w , Wt_OpenGL::win_h );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluOrtho2D ( 0.0, Wt_OpenGL::win_w, 0.0, Wt_OpenGL::win_h );
    glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
    glClear ( GL_COLOR_BUFFER_BIT );
    
    for(int i = 0 ; i < partical_count ; i++) {
        Wt_OpenGL::draw_partical(particals[i].x, particals[i].y);
    }
    glLoadIdentity();
    glutSwapBuffers();
}


void Wt_FluidLB::update()
{
    lb->update();
    //mouse_update();
    particals_update();
    glutPostRedisplay();
}

void Wt_FluidLB::mouse(int button, int state, int x, int y)
{
    is_add_vel = false;
    
    int gridx = x * grid_count / Wt_OpenGL::win_w;
    int gridy = y * grid_count / Wt_OpenGL::win_h;
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            if(gridx >= 0 && gridx < grid_count && gridy >= 0 && gridy < grid_count) {
                is_add_vel = true;
                pre_mouse_x = gridx;
                pre_mouse_y = gridy;
            }
        }
    }
}

void Wt_FluidLB::motion(int x, int y)
{
    int gridx = x * grid_count / Wt_OpenGL::win_w;
    int gridy = y * grid_count / Wt_OpenGL::win_h;
    if(is_add_vel && gridx >= 0 && gridx < grid_count && gridy >= 0 && gridy < grid_count) {
        float u[2] = {0, 0};
        u[0] = gridx - pre_mouse_x;
        u[1] = pre_mouse_y - gridy;
        float m = sqrt(u[0]*u[0]+u[1]*u[1]);
        u[0] /= 1+m;//(1+2*m);
        u[1] /= 1+m;//(1+2*m);
        lb->set_vel(gridx, grid_count - gridy, u);
    }
}


void Wt_FluidLB::particals_update()
{
    for(int i = 0 ; i < partical_count ; i++) {
        //particals[i].y -= 1;
        
        int gridx = particals[i].x * grid_count / Wt_OpenGL::win_w;
        int gridy = particals[i].y * grid_count / Wt_OpenGL::win_h;
        if(gridx >=0 && gridx < grid_count && gridy >=0 && gridy < grid_count) {
            float *vel = lb->get_vel(gridx, gridy);
                particals[i].x += 100 * vel[0];
                particals[i].y += 100 * vel[1];
            
                
        }
    }

}

//void Wt_FluidLB::mouse_update()
//{
//    static int pre_x = 0 ;
//    static int pre_y = 0 ;
//    if(Wt_OpenGL::mouse_left_press) {
//        //pre_x = Wt_OpenGL::mouse_press_x;
//        //pre_y = Wt_OpenGL::mouse_press_y;
//        int gridx = Wt_OpenGL::mouse_x * grid_count / Wt_OpenGL::win_w;
//        int gridy = Wt_OpenGL::mouse_y * grid_count / Wt_OpenGL::win_h;
//        Dbg("set gridx : %d , gridy : %d \n", gridx, gridy);
//        if(gridx >=0 && gridx < grid_count && gridy >=0 && gridy < grid_count) {
//            float u[2] ;
//            u[0] = 0.5;
//            u[1] = 0.5;
//            if(u[0]!= 0.0 || u[1]!= 0.0)
//            {
//                lb->set_vel(gridx, gridy, u);
//            }
//            pre_x = Wt_OpenGL::mouse_x;
//            pre_y = Wt_OpenGL::mouse_y;
//            //Dbg("set u[0] : %f , u[1] : %f \n", u[0], u[1]);
//        }
//
//    }
//}