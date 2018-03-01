//
//  Elements.cpp
//  Solaris
//
//  Created by Jacobo Heredia on 2/4/18.
//
//

#include "Elements.h"
void Element::setup(float _size, float _orbitRadius, float _speed, ofVec3f _position){
    size = _size;
    speed = _speed;
    orbitRadius = _orbitRadius;
    longitud = 0;
    parent = NULL;
    //esta parte aun no tiene sentirdo
    position =_position;
    
}

void Element::update(){
    orbit(longitud, 0,orbitRadius, ofVec3f(ofRandom(0,40),40,50));
    longitud += speed*ofGetLastFrameTime();
    if (longitud>360) longitud-= 360;
    
    //esta parte no tiene mucho sentido 
     position.set(0,0,0);
}

void Element::customDraw(){
    
    ofDrawSphere(position, size);
}