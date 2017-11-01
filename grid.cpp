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
    glfwGetWindowSize(glfwGetCurrentContext(), &this->WIDTH, &this->HEIGHT);

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

void Grid::draw_grid(int VAO, int VBO, Shader &shader, TextRender textRender) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size()-2; ++j) {
            glm::vec3 center = get_cell_center(grid[i][j]);
            GLfloat scale_x =  ((float)(WIDTH/(grid[0].size()*48.0f)))*0.4f;
            GLfloat scale_y = ((float)(HEIGHT/(grid.size()*48.0f)))*0.4f;
            if(i==0 && j!=0){
                textRender.renderText(std::to_string(j - 1).c_str(), center.x-0.015, center.y-0.015, scale_x, scale_y,
                                      glm::vec3(0.5, 0.8f, 0.2f));
            }
            if(j==0 && i!=0){
                textRender.renderText(std::to_string(i - 1).c_str(), center.x-0.015, center.y-0.015, scale_x, scale_y,
                                      glm::vec3(0.5, 0.8f, 0.2f));
            }
            grid[i][j].draw(VAO, VBO, shader);
        }
    }
}

void Grid::draw_line(int VAO, int VBO,Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2) {
    std::vector<glm::vec3> vertices;
    vertices.push_back(get_cell_center(grid[point1.x+1][point1.y+1]));
    vertices.push_back(get_cell_center(grid[point2.x+1][point2.y+1]));
    shader.use();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);
    shader.setVec4("Color", glm::vec4(0.2, 1.0, 0.6, 1.0));
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}

void swap_axis(float &x, float &y){
    float temp = x;
    x = y;
    y = temp;
}

void Grid::draw_line(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2, glm::vec4 Color) {
    std::vector<glm::vec3> vertices;
    vertices.push_back(get_cell_center(grid[point1.x+1][point1.y+1]));
    vertices.push_back(get_cell_center(grid[point2.x+1][point2.y+1]));
    shader.use();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);
    shader.setVec4("Color", Color);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}

void Grid::draw_line(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec3 point1, glm::vec3 point2, glm::vec4 Color) {
    std::vector<glm::vec3> vertices = {point1, point2};
    shader.use();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);
    shader.setVec4("Color", Color);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}

void Grid::draw_cell_with_time(std::vector<std::pair<int,int> > &vertices,int VAO, int VBO, Shader shader, TextRender textRender,
                               glm::vec2 point1, glm::vec2 point2, float &curr_time, float end_time, int isDrawing, int &step) {

    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;
    float x_steps = (dx)/(dx>dy ? dx:dy);
    float y_steps = (dy)/(dx>dy ? dx:dy);

    GLfloat scale_x =  ((float)(WIDTH/(20*48.0f)))*0.6f;
    GLfloat scale_y = ((float)(HEIGHT/(20*48.0f)))*0.6f;
    textRender.renderText("P1: ("+std::to_string(int(point1.x))+","+std::to_string(int(point1.y))+")", 0.5f,0.95f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
    textRender.renderText("P2: ("+std::to_string(int(point2.x))+","+std::to_string(int(point2.y))+")", 0.5f,0.85f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));

    bool swapped = false;
    if((point2.y-point1.y)>(point2.x-point1.y)) {
        swap_axis(point1.x, point1.y);
        swap_axis(point2.x, point2.y);
        swapped = true;
    }
    float time = curr_time/end_time;
    if(isDrawing){
//        std::cout<<"Drawing: "<<curr_time<<std::endl;
        int x = point1.x + (point2.x-point1.x)*time;
        float y1 = ((point2.y - point1.y) / (point2.x - point1.x)) * (float) x +
                    ((point1.y * point2.x) - (point1.x * point2.y)) / (point2.x - point1.x);
        int y = round(y1);
        if(vertices.size()!=0) {
            if ((time <= 1 && x != vertices[vertices.size()-1].first) || (time >=1 && x <= point2.x)) {
                vertices.push_back(std::make_pair(x, y));
            }
        }
        else{
            vertices.push_back(std::make_pair(x,y));
        }
    }
    else{
        if(step<0 && vertices.size()!=0){
            std::cout<<"Stepping: "<<curr_time<<std::endl;
            int x = vertices[vertices.size()-1].first;
            while(vertices.size()>0 && x == vertices[vertices.size()-1].first){
                vertices.pop_back();
            }
            step = 0;
            if(vertices.size() != 0){
                x = vertices[vertices.size()-1].first;
                float time = ((float)x - point1.x)/(point2.x - point1.x);
                curr_time = time*end_time;
            }
            else{
                curr_time = 0;
            }
        }
        else if(step>0){
            std::cout<<"Stepping: "<<curr_time<<std::endl;
            int x,y;
            if(vertices.size()>0){
                if(vertices[vertices.size()-1].first != point2.x){
                    x = vertices[vertices.size()-1].first+1;
                    float y1 = ((point2.y - point1.y) / (point2.x - point1.x)) * (float) x +
                                ((point1.y * point2.x) - (point1.x * point2.y)) / (point2.x - point1.x);
                    int y = round(y1);
                    vertices.push_back(std::make_pair(x,y));
                    float time = ((float)x - point1.x)/(point2.x - point1.x);
                    curr_time = time*end_time;
                }
            }
            else{
                x = point1.x;
                y = point1.y;
                vertices.push_back(std::make_pair(x,y));
                curr_time = 0;
            }
            step = 0;
        }
    }
    for (int i = 0; i < vertices.size(); ++i) {
        if(swapped) {
            grid[vertices[i].second + 1][vertices[i].first + 1].color(VAO, VBO, shader, glm::vec4(0.5f, 0.25f, 0.75f, 1.0f));
            if(i == vertices.size()-1){
                glm::vec3 center = get_cell_center(grid[vertices[i].second+1][vertices[i].first+1]);
                center.x -= (2.0f*0.25f/grid[0].size());
                center.y -= (2.0f*0.1f/grid.size());
//                std::cout<<center.x<<" "<<center.y<<std::endl;
                GLfloat scale_x =  ((float)(WIDTH/(grid[0].size()*48.0f)))*0.4f;
                GLfloat scale_y = ((float)(HEIGHT/(grid.size()*48.0f)))*0.4f;
                textRender.renderText("x, y", center.x, center.y, scale_x, scale_y, glm::vec3(0.8f, 0.4f, 0.2f));
            }
        }
        else {
            grid[vertices[i].first + 1][vertices[i].second + 1].color(VAO, VBO, shader,
                                                                      glm::vec4(0.5f, 0.25f, 0.75f, 1.0f));
            if(i == vertices.size()-1){
                glm::vec3 center = get_cell_center(grid[vertices[i].first+1][vertices[i].second+1]);
                center.x -= (2.0f*0.25f/grid[0].size());
                center.y -= (2.0f*0.1f/grid.size());
//                std::cout<<center.x<<" "<<center.y<<std::endl;
                scale_x =  ((float)(WIDTH/(grid[0].size()*48.0f)))*0.4f;
                scale_y = ((float)(HEIGHT/(grid.size()*48.0f)))*0.4f;
                textRender.renderText("x, y", center.x, center.y, scale_x, scale_y, glm::vec3(0.8f, 0.4f, 0.2f));
            }

        }
    }
    if(swapped) {
        swap_axis(point1.x, point1.y);
        swap_axis(point2.x, point2.y);
        this->draw_line(VAO, VBO, shader, textRender, point1, point2);
        swap_axis(point1.x, point1.y);
        swap_axis(point2.x, point2.y);
    }
    else {
        this->draw_line(VAO, VBO, shader, textRender, point1, point2);
    }

    if(curr_time<end_time && vertices.size()>0) {
        float current_x = vertices[vertices.size() - 1].first;
        float next_x = current_x + 1.0f;
        float current_y = float(vertices[vertices.size() - 1].second);
        float next_y = current_y + 1.0f;
        grid[next_x + 1][current_y + 1].color(VAO, VBO, shader, glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
        grid[next_x + 1][next_y + 1].color(VAO, VBO, shader, glm::vec4(0.0f, 1.0f, 0.0f, 0.5f));

        scale_x =  ((float)(WIDTH/(20*48.0f)))*0.5f;
        scale_y = ((float)(HEIGHT/(20*48.0f)))*0.5f;
        float show_curr_x = floor(point1.x + (point2.x-point1.x)*time);
        float show_curr_y = point1.y + (show_curr_x-point1.x)*(point2.y-point1.y)/(point2.x-point1.x);
        textRender.renderText("x: "+std::to_string(show_curr_x),-0.95f,0.95f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
        textRender.renderText("y: "+std::to_string(show_curr_y),-0.95f, 0.85f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
        textRender.renderText("x_steps: "+std::to_string(x_steps), -0.6f, 0.95f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
        textRender.renderText("y_steps: "+std::to_string(y_steps), -0.6f, 0.85f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
        textRender.renderText("next_x: round("+std::to_string(show_curr_x+x_steps)+")",-0.15f, 0.95f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
        textRender.renderText("next_y: round("+std::to_string(show_curr_y+y_steps)+")",-0.15f, 0.85f, scale_x, scale_y, glm::vec3(1.0f,1.0f,1.0f));
//        std::cout << next_x << " " << current_y << " " << next_y << " " << grid.size() << std::endl;
//        next_x = (next_x + 1.5f) * (2.0f / (grid[0].size() - 1)) - 1.0f;
//        next_y = (next_y + 1.5f) * (2.0f / (grid.size() - 1)) - 1.0f;
//        current_y = (current_y + 1.5f) * (2.0f / (grid.size() - 1)) - 1.0f;
//    float mid_y = (y1 + 1.5f)*(2.0f/grid.size())
//        this->draw_line(VAO, VBO, shader, textRender, glm::vec3(next_x, current_y, 0), glm::vec3(next_x, next_y, 0),
//                        glm::vec4(0.7f, 0.5f, 0.3f, 1.0f));
    }
}

void Grid::draw_line_with_time(int VAO, int VBO, Shader shader, TextRender textRender, glm::vec2 point1, glm::vec2 point2, float time) {
    std::vector<glm::vec3> vertices;
//    vertices.push_back(get_cell_center(grid[point1.x+1][point1.y+1]));
//    vertices.push_back(get_cell_center(grid[point2.x+1][point2.y+1]));
    glm::vec3 p1 = get_cell_center(grid[point1.x+1][point1.y+1]);
    glm::vec3 p2 = get_cell_center(grid[point2.x+1][point2.y+1]);
    glm::vec3 p_t = p1 + (p2-p1)*time;
    vertices.push_back(p1);
    vertices.push_back(p_t);
    shader.use();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(typeof(vertices[0])), vertices.data(),GL_STATIC_DRAW);
    shader.setVec4("Color", glm::vec4(0.2, 1.0, 0.6, 1.0));
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
}