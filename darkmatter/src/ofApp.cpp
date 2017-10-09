#include "ofApp.h"


#define WINDOW_PADDING          30.0
#define RECT_WIDTH_TO_PADDING   0.6
const int origA[] = {1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0};
const int origB[] = {0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1};
const int origC[] = {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0};

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
//    ofSetFullscreen(true);
    VISUALS_WIDTH = ofGetWindowWidth();
    VISUALS_HEIGHT = ofGetWindowHeight();
//    WINDOW_PADDING = 4;
//    RECT_WIDTH_TO_PADDING =10.0;
    ofSetBackgroundColor(0);
    ofSetWindowShape(1024, 800);
    timeBtwnLines.set("timeBtwnLines", 0.2, 0, 1);
  
    
    pNewLine.set("pNewLine", 0.1, 0, 1);

    
    // Calculate rectangle size and padding from width
    float availableSpaceX = (VISUALS_WIDTH - WINDOW_PADDING * 2);
    float widthUnits = M_COLS * RECT_WIDTH_TO_PADDING + (M_COLS - 1);
    float unitWidth = availableSpaceX / widthUnits;
    rectSize = unitWidth * RECT_WIDTH_TO_PADDING;
    paddingSizeX = unitWidth;
    
    // Calculate Y padding
    float availableSpaceY = (VISUALS_HEIGHT - WINDOW_PADDING * 2);
    float totalPaddingY = availableSpaceY - unitWidth * M_ROWS;
    paddingSizeY = availableSpaceY / ((M_ROWS - 1) * 2);
    
    // Load in original
    for (int i = 0; i < M_ROWS; i++) {
        const int (*shape)[M_COLS];
        
        if (i < 5) {
            shape = &origA;
        } else if (i < 49) {
            shape = &origB;
        } else {
            shape = &origC;
        }
        
        for (int j = 0; j < M_COLS; j++) {
            dots[i][j]=(*shape)[i]; //aqui era por j    
        }
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    if (lastLineTime == 0) {
        lastLineTime = ofGetElapsedTimef();
    }
    
    float time = ofGetElapsedTimef();
    
    if (lastLineTime + timeBtwnLines < time) {
        lastLineTime = time;
        // Copy all the lines down one
        for (int i = M_ROWS - 1; i >= 1; i--) {
            memcpy(dots[i], dots[i-1], sizeof(int) * M_COLS);
        }
        
        // Sometimes randomly replace the first line
        if (ofRandomuf() < pNewLine) {
            for (int i = 0; i < M_COLS; i++) {
                dots[0][i] = round(ofRandomuf());
            }
        }
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < M_ROWS; i++) {
        for (int j = 0; j < M_COLS; j++) {
            if (!dots[i][j]) continue;
            
            ofNoFill();
            ofSetCircleResolution(132);
            ofSetLineWidth(0);
            
//            ofSetColor(255);
            ofDrawCircle(j*(rectSize+paddingSizeX)+WINDOW_PADDING,i*(rectSize+paddingSizeY)+WINDOW_PADDING, rectSize);
//            ofDrawRectangle(j*(rectSize+paddingSizeX)+WINDOW_PADDING,
//                            i*(rectSize+paddingSizeY)+WINDOW_PADDING,
//                            rectSize, rectSize);
        }
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

}


