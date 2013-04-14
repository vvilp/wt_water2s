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
    grid_count = 256;
    lb = new Wt_LB_Grid();
    lb->init(grid_count);
    
    srand(unsigned(time(0)));
    
    partical_count = 2000;
    particals = new wt_partical[partical_count];
    for(int i = 0 ; i < partical_count ; i++) {
        particals[i].x = rand() % grid_count;
        particals[i].y = rand() % grid_count;
    }
}

void Wt_FluidLB::display()
{
    glViewport ( 0, 0, Wt_OpenGL::win_w , Wt_OpenGL::win_h );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluOrtho2D ( 0.0, Wt_OpenGL::win_w, 0.0, Wt_OpenGL::win_h );
    glClearColor ( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear ( GL_COLOR_BUFFER_BIT );
    
    glBegin(GL_POINTS);
    for(int i = 0 ; i < partical_count ; i++) {
        //Wt_OpenGL::draw_partical(particals[i].x * Wt_OpenGL::win_w/grid_count, particals[i].y * Wt_OpenGL::win_h/grid_count);
        glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i((int)(particals[i].x*Wt_OpenGL::win_w/grid_count), (int)(particals[i].y*Wt_OpenGL::win_h/grid_count));
    }
    glEnd();
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
            //Dbg("GLUT_LEFT_BUTTON \n");
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
        u[0] /= (1+2*m);
        u[1] /= (1+2*m);
        
        lb->set_vel(gridx, grid_count - gridy, u);
        Dbg("set x : %d , y : %d , u[0] : %f , u[1] : %f \n", gridx , grid_count - gridy, u[0], u[1]);
    }
}


void Wt_FluidLB::particals_update()
{
//    for(int i = 0 ; i < partical_count ; i++) {
//       //int x = (int)particals[i].x;
//       //int y = (int)particals[i].y;
//        particals[i].x += 0.5;
//        particals[i].y += 0.5;
//    }
    
    for(int i = 0 ; i < partical_count ; i++) {
        //wt_partical p = particals[i];
        //int gridx = particals[i].x * grid_count / Wt_OpenGL::win_w;
        //int gridy = particals[i].y * grid_count / Wt_OpenGL::win_h;
        int x = (int)particals[i].x;
		int y = (int)particals[i].y;
        if(x >=0 && x < grid_count && y >=0 && y < grid_count) {
            float *vel = lb->get_vel(x, y);
            
            //if(vel[0] > 0.0 && vel[1] > 0) {
                particals[i].x += 50 * vel[0];
                particals[i].y += 50 * vel[1];
            //    Dbg("x : %d , y : %d , vel[0] : %f , vel[1] : %f \n",x , y ,  vel[0], vel[1]);
            //}

            
            //
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