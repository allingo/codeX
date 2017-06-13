#version 410 core
layout(location = 0) in vec4 vPosition;
out vec4 Color;
void
main()
{
    Color = vec4(0.5, 0.5, 0.5, 1.0);
    gl_Position = vPosition;
}
