#version 120

uniform float percent;
varying float normPos;

float map(float value, float inputMin, float inputMax, float outputMin, float outputMax) {;
	return ((value - inputMin) / (inputMax - inputMin) * (outputMax - outputMin) + outputMin);
}

void main() {
//	if(percent < normPos){
//		discard;
//	}
	gl_FragColor = vec4( vec3( 3.- map(normPos, percent-.21, percent+.01, 0., 1.0)) , 6.0);
}	