#shader vertex
#version 450 core

layout(location = 0) in vec3 a_Position;

void main(){
	gl_Position = vec4(a_Position, 1.0);
}

#shader fragment
#version 450 core

layout(location = 0) out vec4 o_Color;

uniform vec4 u_Color;

void main(){
	o_Color = u_Color;
}