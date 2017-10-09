//
//  Controls.h
//  n0J1a
//
//  Created by Jacobo Heredia on 1/22/17.
//
//

#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class Controls: public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    ofParameterGroup parameters;
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofParameter<float> resolution;
    ofParameter<float> esferitasSize;
    ofxToggle swich ;
    ofxToggle doShader;
    ofxToggle esferas;
    //ofParameter<ofVec3f> position;
    
    
    ofxPanel gui;
    ofxGuiGroup dcontent;
    ofParameter<float> zLuz;
    ofParameter<float> xLuz;
    ofParameter<float> yLuz;
 
};