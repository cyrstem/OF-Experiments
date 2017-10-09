#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myMaker.setup();
    
    //basic setup canvas
    ofSetWindowTitle("Forms & Shapes");
    ofSetWindowShape(800, 800);
//    ofSetBackgroundColor(87, 247, 216);
    ofSetBackgroundColor(51);
    pos.x=0.0;
    pos.y=ofGetHeight()/2;
    
    //how to create a pointer
    int i = 5;
    //like this  and save it lie &i
    int * p = &i;
    
    // to get accese back to the  pointer *p
    
    cout<< *p<<endl;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myMaker.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myMaker.draw();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
