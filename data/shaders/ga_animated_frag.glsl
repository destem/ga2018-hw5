#version 400

in vec3 o_normal;
in vec3 o_color;

out vec4 finalColor;

void main(void)
{
	finalColor = vec4(o_color, 1.0);
}
