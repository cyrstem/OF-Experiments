#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
   
    
    ofEasyCam cam;
    ofxPanel gui;
    ofxSlider<float>resolution;
    ofxSlider<float>sphereSize;
    ofxSlider<float>smallsphereSize;
    bool hideMenu;
     ofTrueTypeFont dots;
    
    ofSpherePrimitive sphere;
    vector<ofPoint> vertices;
    float           nextLetterTime;
    int             lineCount;
    int             letterCount;
    vector<string> mrRobot;
    
    
};
