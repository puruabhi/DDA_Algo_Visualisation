cmake_minimum_required(VERSION 3.8)
project(OpenGL_Practice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp glad.c shader.cpp square.cpp grid.cpp text_renderer.cpp)
add_executable(OpenGL_Practice ${SOURCE_FILES})
target_link_libraries(OpenGL_Practice GL glfw dl GLEW freetype)