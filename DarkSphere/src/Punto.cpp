//
//  Punto.cpp
//  DarkSphere
//
//  Created by Jacobo Heredia on 8/9/17.
//
//

#include "Punto.h"
Punto::Punto(){
    pos = ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    size = 0.5f;
    increment = 0.2f;
    vel.set(ofRandom(-1,1),ofRandom(-1,1),ofRandom(-1,1));
//    last = ofGetElapsedTimeMillis();
//    color = ofColor::fromHsb(235, 0, 80);
    color = ofColor::white;
    vida = 0;
    tiempoVida = 100;
    isDead=false;
    
    

}

void Punto::update(){
    vida++;
    pos += vel ;
    size += increment;
 
    
    if (size >= 1.5 || size <= 0) {
        increment *= -1;
    }
    
    if(vida > tiempoVida){
        isDead = true;
    }

    
    
//    if(ofGetElapsedTimeMillis() - last > 70)
//    {
//        
//        color.setBrightness(counter % 155);
//        
//        counter ++;
//        last = ofGetElapsedTimeMillis();
//    }
//    


}


void Punto::draw(){
    ofSetColor(color);
//    ofPopStyle();
//    ofSetColor (ofColor::white);
//    ofDrawLine(pos.x, pos.z, 0, 40, 40, 40);
//    ofPushStyle();
    ofDrawSphere(pos, size);

}

