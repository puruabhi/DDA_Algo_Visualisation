#version 330 core

out vec4 FragColor;
uniform vec4 Color;
uniform int chk_color = 0;

void main()
{
    FragColor = Color;
}