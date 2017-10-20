//
// Created by abhisheikh on 19/10/17.
//

#ifndef OPENGL_PRACTICE_SQUARE_H
#define OPENGL_PRACTICE_SQUARE_H

#include <glm/glm.hpp>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"

class Square{
private:
    std::vector<glm::vec3> vertices;

public:
    Square();
    Square(glm::vec3 bottom_left, glm::vec3 top_right);
    std::vector<glm::vec3> get_vertices();
    void draw(int VAO, Shader shader);
    void color(int VAO, Shader &shader, glm::vec3 color);
};

#endif //OPENGL_PRACTICE_SQUARE_H
