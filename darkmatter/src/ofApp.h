#pragma once

#include "ofMain.h"
#define M_COLS  75
#define M_ROWS  75

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    float rectSize, paddingSizeX, paddingSizeY;
    int dots[M_COLS][M_ROWS];
    
    ofParameter<float>pNewLine;
    ofParameter<float> timeBtwnLines;
    float lastLineTime;
    float VISUALS_WIDTH, VISUALS_HEIGHT, WINDOW_PADDING;
    float RECT_WIDTH_TO_PADDING;
		
};
