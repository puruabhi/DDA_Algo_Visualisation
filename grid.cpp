//
// Created by abhisheikh on 19/10/17.
//

#include "grid.h"

//Grid::Grid() {
//    this->Grid(default_rows,default_cols);
//}

glm::vec3 get_cell_center(Square sq){
    glm::vec3 center(0.0f,0.0f,0.0f);
    std::vector<glm::vec3> vertices = sq.get_vertices();
    for (int i = 0; i < vertices.size(); ++i) {
        center += vertices[i];
    }
    return center/(float)vertices.size();
}

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

void Grid::draw_grid(int VAO, Shader &shader) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j].draw(VAO, shader);
        }
    }
}

void Grid::draw_line(int VAO, Shader shader, glm::vec2 point1, glm::vec2 point2) {
    std::vector<glm::vec3> vertices;
    vertices.push_back(get_cell_center(grid[point1.x][point1.y]));
    vertices.push_back(get_cell_center(grid[point2.x][point2.y]));
    shader.use();
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}

void Grid::draw_line_with_time(std::vector<std::pair<int,int> > &vertices,int VAO, Shader shader, glm::vec2 point1,
                               glm::vec2 point2, float time, float end_time, int isDrawing) {
    time = time/end_time;
//    glm::vec3 p1 = get_cell_center(grid[point1.x][point1.y]), p2 = get_cell_center(grid[point2.x][point2.y]);
    int x = point1.x + (point2.x-point1.x)*time;
    double y1 = ((point2.y-point1.y)/(point2.x-point1.x))*(float)x + ((point1.y*point2.x)-(point1.x*point2.y))/(point2.x-point1.x);
    int y = round(y1);
    if(time<=1 && isDrawing)
        vertices.push_back(std::make_pair(x,y));
    for (int i = 0; i < vertices.size(); ++i) {
        grid[vertices[i].first+1][vertices[i].second+1].color(VAO, shader, glm::vec3(0.5f, 0.25f, 0.75f));
    }
}