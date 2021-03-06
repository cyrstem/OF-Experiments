#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include"ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
    ofVideoGrabber cam;
    ofxCv::ObjectFinder finder;
    ofxCv::RunningBackground background;
    
    ofImage thresholded;
    
    //gui staff
    ofxPanel gui;
    ofParameter<bool> resetBackground;
    ofParameter<float> learningTime, thresholdValue;
    ofParameter<float> erodeAmt;
    ofParameter<float> dilateAmt;
    ofParameter<float> blurAmt;
    ofParameter<float> smooth;
    
    ofFbo fboFrame;
    ofVec2f pointer;
    ofVec2f oldPos;
    bool bOld;
    int frameLost;
    
    
};
