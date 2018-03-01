//
//  OrbitSptr.cpp
//  Solaris
//
//  Created by Jacobo Heredia on 12/10/17.
//
//

#include "OrbitSptr.h"
void OrbitSptr::init(float _lSize, float _alfaV){
    
    alfaV = _alfaV;
    lineWidth =_lSize;
    relleno = false;
    ofSetSmoothLighting(true);
    ofEnableSmoothing();
    v = 0.0;
}

void OrbitSptr::customDraw(float _offset, float _radius,int _resolution,
                           bool _relleno, ofColor _color){
    //Orbit or circle settings
    ofSetLineWidth(lineWidth);
    colors = _color;
    relleno =_relleno;
    reaction =_offset;
    if (relleno == true) {
        ofFill();
        
    } else{
        ofNoFill();
    }
    //---------
    ofSetColor(colors,alfaV);
    //audio reaction
    float offset = reaction;
    //---------
    v=v+0.1;
    //building shape
    ofRotateY(0.2+v);
    ofBeginShape();
    int resolution = _resolution;
    float radius = _radius;
    float noiseHeight = 0+ reaction;
    //ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    for (int i = 0; i < resolution; i++) {
        
        float angle = ofMap(i, 0, resolution, 0, PI * 2);
        
        float x = cos(angle) * (radius + ofNoise(i, offset) * noiseHeight);
        float y = sin(angle) * (radius + ofNoise(i, offset) * noiseHeight);
        
        ofVertex(x , y);
        circle.addVertex(x + 200, y);
    }
    
    ofEndShape(true);
    


    
    
}