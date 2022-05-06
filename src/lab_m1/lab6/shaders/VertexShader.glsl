#version 330

// Input
// TODO(student): Get vertex attributes from each location
layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_normal;
layout (location = 2) in vec3 v_textCoo;
layout (location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

// Output
// TODO(student): Output values to fragment shader
out vec3 frag_pos;
out vec3 frag_normal;
out vec3 frag_texCoo;
out vec3 frag_color;

void main()
{
    // TODO(student): Send output to fragment shader
    frag_pos = v_position;
    frag_normal = v_normal;
    frag_texCoo = v_textCoo;
    frag_color = v_color;
    // TODO(student): Compute gl_Position
    gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}
