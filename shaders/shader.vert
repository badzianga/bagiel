#version 460 core

layout (location = 0) in vec2 a_position;
layout (location = 1) in vec4 a_color;

uniform mat4 u_projection;

out vec4 color;

void main() {
    gl_Position = u_projection * vec4(a_position, 0.0, 1.0);
    color = a_color;
}
