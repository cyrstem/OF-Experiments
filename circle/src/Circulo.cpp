//
//  Circulo.cpp
//  circle
//
//  Created by Jacobo Heredia on 5/16/17.
//
//

#include "Circulo.h"
Circulo::Circulo(){
    
}

void Circulo::setup(){
    
}

void Circulo::update(){
    
}

void Circulo::draw(int _rad, int _tamLinea, int _cRess,ofColor _clr,int _anim, float _sine){
    tamLinea =_tamLinea;
    rad =_rad;
    cReso = _cRess;
    sines = _sine;
    
    //ofBackground(30);// draw grey background
    //ofSetColor(255);// set color drawing color to white
    //ofTranslate(ofGetWidth()/2,ofGetHeight()/2); // move initital drawing postion to the center of the screen
    int circle_resolution=cReso; // amount of points circle is made of, more points - better quality, but could decrease perfomance
    int radius=rad;
    
    ofPolyline circle;
    
    int sine_radius=radius*sines;
    int anim_shape=_anim;
    float sine_pct=0.5; // setting in percantage how big is the part
    
    float speed_increment=ofGetElapsedTimef()/2;
    
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=sine_radius*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle+speed_increment)*radius;
        float y=sin(angle+speed_increment)*radius;
        float z= ofLerp(x, y, sine_pct+1);
        
        // drawing sine wave only on a part of the circle
        if(i<sine_pct*circle_resolution){
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
            z=ofNoise(x+2,y+2);
        }
        
        circle.addVertex(ofPoint(x,y,z));
    }
    
    ofSetLineWidth(tamLinea);
    ofColor clr= _clr;
//    fromHex(0x379392);
    ofSetColor(clr);
    
    
    circle.close(); // to connect first and last point of our shape we need to use ‘close’ function
    circle= circle.getSmoothed(10);
    circle.draw();
}