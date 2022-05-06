#version 330

layout(location = 0) out vec4 out_color;

void main()
{
    float rosu = 202.0f / 255.0f;
    float galben = 226.0f / 255.0f;
    float albastru = 99.0f / 255.0f;
    out_color = vec4(rosu, galben, albastru, 1);
}