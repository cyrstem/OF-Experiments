#pragma once

#include "ofMain.h"

#include "Punto.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
    //Gui
    
    //my class
    vector<Punto> p;
    //camara
    ofEasyCam cam;
    
    ofSpherePrimitive sphere, sphere2;
    
    int pSphereRes ;
    vector<ofPoint> vertices;
    


    bool yaap;
    ofLight luz;
    
    
//GUI
    ofParameter<float>rotacion ;
    ofParameter<int> sizeArray;
    ofParameter<int>alocar;
    ofxDatGui* gui;
    




};
