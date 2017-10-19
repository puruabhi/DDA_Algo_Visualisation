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
    void draw(int VAO, Shader shader);
};

#endif //OPENGL_PRACTICE_GRID_H
