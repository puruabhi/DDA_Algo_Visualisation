//
// Created by abhisheikh on 19/10/17.
//

#include <iostream>
#include "square.h"

Square::Square(glm::vec3 bottom_left, glm::vec3 top_right) {
    vertices.push_back(bottom_left);
    glm::vec3 bottom_right(top_right.x, bottom_left.y, 0);
    vertices.push_back(bottom_right);
    vertices.push_back(top_right);
    glm::vec3 top_left(bottom_left.x, top_right.y, 0);
    vertices.push_back(top_left);
}

void Square::draw(int VAO, Shader shader) {
    std::vector<glm::vec3> vertices = this->get_vertices();
    vertices.push_back(vertices[0]);
    shader.use();
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(), GL_STATIC_DRAW);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}

std::vector<glm::vec3> Square::get_vertices() {
    return vertices;
}

void Square::color(int VAO, Shader shader, glm::vec3 color) {
    std::vector<glm::vec3> vertices = this->get_vertices();
    shader.use();
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(), GL_STATIC_DRAW);
    shader.setVec4("Color", glm::vec4(color,1.0f));
    shader.setInt("chk_color", 0);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}