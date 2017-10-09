#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void ui();

        void guiEvent(ofxUIEventArgs &e);
        void exit();
		void keyPressed(int key);
    ofVideoGrabber grabber;
    int camW, camH;
    ofImage img;
    
    //ofImage img;
    
    ofPixels pixels;
    ofTexture texture;

		//gui
    	ofxUISuperCanvas *gui, *gui2;
    float valueBlended;
    float red,green, blue;
    
    
    //Cv staff  remove background
    ofxCv::RunningBackground background;
    ofxCv::ContourFinder contourFinder;
    
    float threshold;
    bool trackHs;
    ofImage thresholded;
    ofImage gray;
    
    ofColor targetColor;
    
    
    bool resetBackground;
    float learningTime, thresholdValue;
    //glitch staff!!!


};
