#version 330

// Input
// TODO(student): Get values from vertex shader
in vec3 frag_pos;
in vec3 frag_normal;
in vec3 frag_texCoo;
in vec3 frag_color;

// Output
layout(location = 0) out vec4 out_color;

void main()
{
    // TODO(student): Write pixel out color
    out_color = vec4(frag_normal, 1);
}
