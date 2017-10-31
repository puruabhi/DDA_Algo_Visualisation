#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "square.h"
#include "grid.h"

void init_glfw();
GLFWwindow* createWindow(int width, int height, std::string title);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void add_points(std::vector<glm::vec3>&, glm::vec3, glm::vec3, float);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

int isDrawing = 1;
int step = 0;

int main() {
    std::cout << "Hello, World!" << std::endl;

    init_glfw();
    GLFWwindow *window = createWindow(600,600, "OpenGL Project");
    if(!window){
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    Shader shader("../Shaders/vShader.vs","../Shaders/fShader.fs");

//    std::vector<glm::vec3> vertices = {
//            glm::vec3(-0.5f, -0.5f, 0.0f),
//            glm::vec3(0.5f, -0.5f, 0.0f),
//            glm::vec3(0.0f,  0.5f, 0.0f)
//    };

    std::vector<glm::vec3> vertices;
    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

//    Square sq(glm::vec3(0,0,0), glm::vec3(0.8,0.8,0));
//    vertices = sq.get_vertices();
//    for (int i = 0; i < vertices.size(); ++i) {
//        std::cout<< (vertices[i].x) <<" "<< vertices[i].y <<std::endl;
//    }
    Grid grid(10,10);

    clock_t start = clock();

    std::vector<std::pair<int,int> > cells;

    float time = 0, end_time = 7.0f;

    while(!glfwWindowShouldClose(window)){

        glClearColor(0.2f,0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //shader.use();
        //glBindVertexArray(VAO);

        //glDrawArrays(GL_TRIANGLES, 0, 3);
//        sq.draw(VAO, shader);
        grid.draw_grid(VAO, shader);
//        grid.draw_line(VAO, shader,glm::vec2(0,0), glm::vec2(23,10));
        clock_t now = clock();
        float t= (float)(now - start)/(float)CLOCKS_PER_SEC;
        start = now;
        if(isDrawing && time < end_time)
            time += t;
        grid.draw_cell_with_time(cells, VAO, shader,glm::vec2(0,0), glm::vec2(7,3),time,end_time, isDrawing, step);
//        add_points(vertices,glm::vec3(-0.5f,-0.3f,0.0f), glm::vec3(0.6f,0.7f,0.0f), time);
//        shader.use();
//        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(), GL_STATIC_DRAW);
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void init_glfw(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* createWindow(int width, int height, std::string title){
    GLFWwindow *window = glfwCreateWindow(width,height,title.c_str(),NULL,NULL);
    if(window == NULL){
        std::cout<< "Failed to create GLFW window" <<std::endl;
        glfwTerminate();
    }
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }

    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        std::cout<<"Hi"<<std::endl;
        if(isDrawing == 0){
            isDrawing = 1;
        }
        else{
            isDrawing = 0;
        }

    }
}

void add_points(std::vector<glm::vec3> &vertices, glm::vec3 point1, glm::vec3 point2, float time){
    if(time<=5.0){
        vertices.push_back(point1 + (point2-point1)*(time/5));
    }
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
    switch(key){
        case GLFW_KEY_ESCAPE:
            if(action == GLFW_PRESS){
                glfwSetWindowShouldClose(window,true);
            }
            break;

        case GLFW_KEY_SPACE:
            if(action == GLFW_PRESS){
                step = 0;
                isDrawing = isDrawing^1;
            }
            break;

        case GLFW_KEY_RIGHT:
            if(action == GLFW_PRESS){
                isDrawing = 0;
                step = 1;
            }
            break;

        case GLFW_KEY_LEFT:
            if(action == GLFW_PRESS){
                isDrawing = 0;
                step = -1;
            }
            break;
    }
}