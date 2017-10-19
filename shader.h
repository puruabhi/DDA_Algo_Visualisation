#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader
{
public:
    // program ID
    unsigned int ID;
    
    //constructor reads and builds the shader
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    
    //use/activate the shader
    void use();
    
    //utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec4(const std::string &name, const glm::vec4 &vector) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
};

#endif