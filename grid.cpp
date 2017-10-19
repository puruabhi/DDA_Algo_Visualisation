//
// Created by abhisheikh on 19/10/17.
//

#include "grid.h"

//Grid::Grid() {
//    this->Grid(default_rows,default_cols);
//}

Grid::Grid(int cols, int rows) {
    float step_rows = 2.0f/(float)rows, step_cols = 2.0f/(float)cols;
    //std::cout<<step_rows<<" "<<step_cols<<std::endl;
    int i_prev = 0, j_prev;
    for (float i = -1; i <1 ; i+=step_rows) {
        std::vector<Square> grid_row;
        j_prev = 0;
        for (float j = -1; j <1 ; j+=step_cols) {
            //std::cout<<i<<" "<<j<<std::endl;
            Square sq(glm::vec3(i,j,0),glm::vec3(i+step_rows,j+step_cols,0));
            grid_row.push_back(sq);
            j_prev = j;
        }
        grid.push_back(grid_row);
        i_prev = i;
    }
    //std::cout<<grid.size()<<std::endl;
}

std::vector<std::vector<Square> > Grid::get_grid() {
    return grid;
}

void Grid::draw(int VAO, Shader shader) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j].draw(VAO, shader);
        }
    }
}