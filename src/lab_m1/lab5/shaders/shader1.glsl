#version 330

layout(location = 0) out vec4 out_color;

void main()
{
    float rosu = 55.0f / 255.0f;
    float galben = 223.0f / 255.0f;
    float albastru = 15.0f / 255.0f;
    out_color = vec4(rosu, galben, albastru, 1);
}