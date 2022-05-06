#version 330

layout(location = 0) out vec4 out_color;

void main()
{
    float rosu = 207.0f / 255.0f;
    float galben = 93.0f / 255.0f;
    float albastru = 94.0f / 255.0f;
    out_color = vec4(rosu, galben, albastru, 1);
}