//
// Created by abhisheikh on 19/10/17.
//

#ifndef OPENGL_PRACTICE_GRID_H
#define OPENGL_PRACTICE_GRID_H

#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include "square.h"
#include "shader.h"
#include "text_renderer.h"
#define default_rows 20
#define default_cols 20

class Grid{
private:
    std::vector<std::vector<Square> > grid;
    int WIDTH, HEIGHT;
public:
    Grid():Grid(default_cols,default_rows){};
    Grid(int cols, int rows);
    std::vector<std::vector<Square> > get_grid();
    void draw_grid(int VAO, int VBO, Shader &shader, TextRender textRender);
    void draw_line(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2);
    void draw_line(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2, glm::vec4 Color);
    void draw_line(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec3 point1, glm::vec3 point2, glm::vec4 Color);
    void draw_cell_with_time(std::vector<std::pair<int, int> > &vertices, int VAO, int VBO, Shader shader, TextRender textRender,
                             glm::vec2 point1, glm::vec2 point2, float &curr_time, float end_time, int isDrawing, int &step);
    void draw_line_with_time(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2, float time);
};

#endif //OPENGL_PRACTICE_GRID_H
