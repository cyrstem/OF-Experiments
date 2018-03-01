//
//  Particle.cpp
//  Solaris
//
//  Created by Jacobo Heredia on 2/19/18.
//
//

#include "Particle.h"
//--------------------------------------------------------------
Particle::Particle(){
    live =false;
}

//--------------------------------------------------------------
void Particle::setup(){
    time =0;
    live = true;
    
}
//--------------------------------------------------------------
void Particle::update( float dt){
    
}
//--------------------------------------------------------------
void Particle::draw(){
 
    ofSetLineWidth(2);
    ofFill();
    ofSetColor(ofColor::whiteSmoke);
    ofDrawSphere(30,20, 10);
    
}
//--------------------------------------------------------------