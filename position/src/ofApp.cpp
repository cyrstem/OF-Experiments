#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(55);
    miPosition = {0,0,0,0,0,0};
    miIncremento = {1,2,3,4,5};
    

}

//--------------------------------------------------------------
void ofApp::update(){
    // da lo mismo  que std::size_t i  = int i
    float save;
    for (int i = 0; i < miPosition.size(); i++)
    {
        miPosition[i] = miPosition[i] + miIncremento[i];
        
        if (miPosition[i] > ofGetWidth())
        {
            miPosition[i] = 0;
        }

    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    for (float position: miPosition)//como funciona esta parte
    {
        ofDrawEllipse(position, 20, 20, 20);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

