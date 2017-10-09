#pragma once

#include "ofMain.h"
//--------------------------------------------------------------
//----------Class Particula
//--------------------------------------------------------------
class Punto {
public:
    Punto();
    void update();
    void draw();
    void reset();
    ofPoint pos;
    ofVec2f vel;
    float size, increment;
 
    
    unsigned long last;
    int counter;
    ofColor color;
    // fbo store test try  see if  works better
    
//     ofFbo fbo;

    };

//--------------------------------------------------------------
//----------Main OF
//--------------------------------------------------------------

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

    //Punto p;
    vector<Punto> p;
    //camara
    ofEasyCam cam;
    
     ofSpherePrimitive sphere;
    
    int pSphereRes;
     vector<ofPoint> vertices;
    //delete particle
    
  
    
    ofLight luz;
    

    
   };
