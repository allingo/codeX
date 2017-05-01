#version 320 core
uniform Uniforms
{
    vec3 translation;
    float scale;
    vec4 rotation;
    bool enable;
}
in vec4 fColor;
out vec4 color;

void
main()
{
    color = fColor;
}
