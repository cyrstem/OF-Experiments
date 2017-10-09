#pragma once

#include "ofMain.h"
#include "Controls.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    //my sections
    shared_ptr<Controls> gui;
    ofSpherePrimitive sphere;
    ofEasyCam cam;
    ofLight luz;
    bool printC;
    ofShader shader;
//    bool doShader;
    
    vector<ofPoint> vertices;
};
