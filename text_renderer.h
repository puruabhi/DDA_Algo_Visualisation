//
// Created by abhisheikh on 1/11/17.
//

#ifndef OPENGL_TEXT_RENDERING_TEXT_RENDERER_H
#define OPENGL_TEXT_RENDERING_TEXT_RENDERER_H

#include <iostream>
//#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include <map>
#include FT_FREETYPE_H
#include "shader.h"

class TextRender{
private:
    struct Character{
        GLuint TextureID;   // ID handle of the glyph texture
        glm::ivec2 Size;    // Size of glyph
        glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
        GLuint Advance;    // Horizontal offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;
    Shader shader;
    int WIDTH, HEIGHT;
    GLuint VAO, VBO;
    GLuint texture;

public:
    TextRender(Shader &shader, const GLchar* fontPath);
    void renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale_x, GLfloat scale_y, glm::vec3 color);
};

#endif //OPENGL_TEXT_RENDERING_TEXT_RENDERER_H
