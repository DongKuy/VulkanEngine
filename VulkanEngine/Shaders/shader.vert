#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
    vec3 lightColor;
    vec3 lightPos;
    vec3 viewPos;
    float brightness;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;
layout(location = 3) in vec3 inNormal;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;
layout(location = 2) out vec3 fragNormal;
layout(location = 3) out vec3 fragPos;
layout(location = 4) out vec3 lightPos;
layout(location = 5) out vec3 lightColor;
layout(location = 6) out vec3 viewPos;

void main() {
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 1.0);
    //fragColor = inColor * ubo.lightColor * 0.6;
    fragColor = inColor;
    lightColor = ubo.lightColor;
    fragTexCoord = inTexCoord;
    fragNormal = transpose(inverse(mat3(ubo.model))) * inNormal;
    //fragPos = inPosition;
    fragPos = vec3(ubo.model * vec4(inPosition,1.0));
    lightPos = ubo.lightPos;
    viewPos = ubo.viewPos;
}