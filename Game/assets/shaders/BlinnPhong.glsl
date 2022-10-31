#shader vertex
#version 450 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Normal;
layout (location = 2) in vec2 a_TexCoord;

uniform mat4 u_Transform;
uniform mat4 u_ViewProj;
uniform mat4 u_Normal;

out vec3 v_Position;
out vec3 v_Normal;
out vec2 v_TexCoord;

void main() {
	v_Position = vec3(u_Transform * vec4(a_Position, 1.0));
	v_TexCoord = a_TexCoord;
	v_Normal = mat3(u_Normal) * a_Normal;
	
	gl_Position = u_ViewProj * u_Transform * vec4(a_Position, 1.0);
}

#shader fragment
#version 450 core

in vec3 v_Position;
in vec3 v_Normal;
in vec2 v_TexCoord;

layout(location = 0) out vec4 o_Color;

uniform vec3 u_ViewPos;

uniform struct Material{
    vec4 color;
    int shininess;
} u_Material;

struct DirLight {
    vec4 color;

	vec3 direction;
    float intensity;
};

vec3 calcDirLight(DirLight light, vec3 fragColor, vec3 normal, vec3 viewDir){
	vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), u_Material.shininess * 2.0);
    // combine results
    vec3 ambient  = 0.1 * light.color.rgb * fragColor;
    vec3 diffuse  = light.color.rgb * diff * fragColor;
    vec3 specular = light.color.rgb * spec * fragColor;

    return (ambient + (diffuse + specular) * light.intensity);
}

void main() {
    vec3 normal = normalize(v_Normal);
    vec3 viewDir = normalize(u_ViewPos - v_Position);

    DirLight light;
    light.color = vec4(1.0);
    light.direction = vec3(-1.0);
    light.intensity = 1.0;

    vec3 result = vec3(0.0);
    result += calcDirLight(light, u_Material.color.rgb, normal, viewDir);

    o_Color = vec4(result, 1.0);
}