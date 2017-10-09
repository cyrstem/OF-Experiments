#pragma once

#include "ofMain.h"
#include "Circulo.h"
#define NCIRC 17

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    

    Circulo myCirculo;
    Circulo myCirculo2;
    Circulo myCirculo3;
    Circulo myCirculo4;
    Circulo myCirculo5;
//     Circulo myCirculo6;
//     Circulo myCirculo7;

    void keyPressed(int key);
//    Circulo myCirculo [NCIRC];
    
    ofEasyCam cam;
    ofLight luz;
    ofSpherePrimitive sphere;
    
};
