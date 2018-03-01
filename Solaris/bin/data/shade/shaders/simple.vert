#version 120
#extension Gl_ARB_texture_rectangle :enable
#extension GL_EXT_gpu_shader4 :enable
void main() {
    gl_Position = gl_ModelViewProjectionMatrix *gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCood0;
    gl_FrontColor = gl_color;
    
}