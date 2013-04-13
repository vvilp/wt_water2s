//
//  wt_LB_Grid.cpp
//  wt_water3
//
//  Created by vvilp on 4/13/13.
//  Copyright (c) 2013 vvilp. All rights reserved.
//

#include "wt_LB_Grid.h"
#include "wt_config.h"
int   Wt_LB_Grid::c[9][2] = {{0,0}, {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
float Wt_LB_Grid::w[9]    = {0.44, 0.11, 0.11, 0.11, 0.11, 0.02, 0.02, 0.02, 0.02};
float Wt_LB_Grid::omga    = 0.75;
void Wt_LB_Grid::init(int grid_count)
{
    this -> grid_count = grid_count;
    density = new float*[grid_count];
          f = new float**[grid_count];
        vel = new float**[grid_count];
    for (int i = 0; i < grid_count; i++) {
        density[i] = new float[grid_count];
              f[i] = new float*[grid_count];
            vel[i] = new float*[grid_count];
        for (int j = 0 ; j < grid_count; j++) {  
            density[i][j]    = 0.0;
                  f[i][j]    = new float[9];
                vel[i][j]    = new float[2];
                vel[i][j][0] = 0.0;
                vel[i][j][1] = 0.0;
            
            for(int k = 0 ; k < 9 ; k++) {
                f[i][j][k] = 0.0;
            }
        }
    }
}
//
float Wt_LB_Grid::feq(int index, float density, float vel[2])
{
    float civi = c[index][0] * vel[0] + c[index][1] * vel[1];
    float vivi = vel[0] * vel[0] + vel[1] * vel[1];
    return w[index] * density * (1.0 + 3.0 * civi + 4.5 * civi * civi - 1.5 * vivi);
}

void Wt_LB_Grid::update_density_vel()
{
    for (int x = 0; x < grid_count; x++) {
        for(int y = 0 ; y < grid_count ; y++) {
            
            for(int i = 0 ; i < 9 ; i++) {
                density[x][y] += f[x][y][i];
                vel[x][y][0]  += f[x][y][i] * c[i][0];
                vel[x][y][1]  += f[x][y][i] * c[i][1];

            }
            vel[x][y][0] /= density[x][y];
            vel[x][y][1] /= density[x][y];
        }
    }
}


void Wt_LB_Grid::collide()
{
    for (int x = 0; x < grid_count; x++) {
        for (int y = 0; y < grid_count; y++) {
            for(int i = 0 ; i < 9 ; i++) {
                f[x][y][i] = (1 - omga) * f[x][y][i] + omga * feq(i,density[x][y],vel[x][y]);
            }
        }
    }
}

void Wt_LB_Grid::stream()
{
    for (int x = 0; x < grid_count; x++) {
        for (int y = 0; y < grid_count; y++) {
            for(int i = 0 ; i < 9 ; i++) {
                int nx = x + c[i][0];
                int ny = y + c[i][1];
                
                if(nx >=0 && nx < grid_count && ny >=0 && ny < grid_count) {
                    f[nx][ny][i] = f[x][y][i];
                }
            }
        }
    }
}















