//
// Created by abhisheikh on 19/10/17.
//

#ifndef OPENGL_PRACTICE_GRID_H
#define OPENGL_PRACTICE_GRID_H

#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include "square.h"
#define default_rows 20
#define default_cols 20

class Grid{
private:
    std::vector<std::vector<Square> > grid;
public:
    Grid():Grid(default_cols,default_rows){};
    Grid(int cols, int rows);
    std::vector<std::vector<Square> > get_grid();
    void draw_grid(int VAO, Shader &shader);
    void draw_line(int VAO, Shader shader, glm::vec2 point1, glm::vec2 point2);
    void draw_line_with_time(std::vector<std::pair<int, int> > &vertices, int VAO, Shader shader,
                             glm::vec2 point1, glm::vec2 point2, float &curr_time, float end_time, int isDrawing, int &step);
};

#endif //OPENGL_PRACTICE_GRID_H
