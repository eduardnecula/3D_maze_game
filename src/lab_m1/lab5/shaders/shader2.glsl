#version 330

layout(location = 0) out vec4 out_color;

void main()
{
    float rosu = 155.0f /255.0f;
    float galben = 77.0f / 255.0f;
    float albastru = 212.0f / 255.0f;
    out_color = vec4(rosu, galben, albastru, 1);
}