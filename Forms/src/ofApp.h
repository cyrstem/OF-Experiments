#pragma once

#include "ofMain.h"
#include "maker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
//variables position
    ofVec2f pos;
    Maker myMaker;
};
