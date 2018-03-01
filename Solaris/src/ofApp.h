#pragma once

#include "ofMain.h"
#include "OrbitSptr.h"
#include "Elements.h"
#include "ofxUI.h"
#include "Particle.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void data();
    void drawCorner(ofPoint p);
    void elementData();
		void keyPressed(int key);
    //GUI StaFF
    void ui();
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    
    
   //style
    ofTrueTypeFont font;
    //camera
    ofEasyCam cam;
    //luz
    ofLight luz;
    bool luz0;
    //load files
    ofDirectory dir;
     ofImage img;
    int current, i ;
    vector<ofSoundPlayer> sounds;
    //what react from audio
    
    float reaction, time;
//-------Clasess Start--------------------
    //orbitSpctr
    OrbitSptr orb ,orb2, orb3, orb4,orb5;
//----------------------------------------
    //fbo
    ofFbo fbo;

    
    //GUI staff
    ofxUISuperCanvas *gui;
    ofPoint posLightXY;
    
    float luzZ;
    float orbitSpeed;
    ofRectangle rect ;
    
    //Element spheresss
    //------------------------------------------
    Element uno,dos,tres, cuatro, cinco;

    Particle part, part1,part3;
   };
