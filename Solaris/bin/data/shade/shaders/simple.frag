#version 120
#extension GL_ARB_texture_rectangle :enable
#extension GL_EXT_gpu_shader4 :enable
uniform sampler2DRect texture0;


void main() {
    vec2 pos = gl_TexCoord[0].xy;
    vec4 color = texture2DRect (texture0,pos);
    
    //cambio de color
    color.r =1.0 -color.r;
    color.g =1.0 -color.g;
    color.b = 1.0 -color.b;
    //output shit
    gl_FragColor =color;
}	