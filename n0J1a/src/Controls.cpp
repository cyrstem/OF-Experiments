//
//  Controls.cpp
//  n0J1a
//
//  Created by Jacobo Heredia on 1/22/17.
//
//
#include "Controls.h"


void Controls::setup(){
    parameters.setName("Parameters");
    parameters.add(radius.set("radius",50,1,100));
    parameters.add(resolution.set("resolution",6,12,32));
    parameters.add(color.set("color",100,ofColor(0,0),255));
    parameters.add(esferitasSize.set("esfera Size",10,1,100));
    
    gui.setup(parameters);
    
    dcontent.setup("3D staff");
    dcontent.add(swich.setup("Switch",true));
    dcontent.add(esferas.setup("peque esferas",true));
    dcontent.add(zLuz.set("Position Luz Z",600,0,1000));
    dcontent.add(xLuz.set("Position Luz X",ofGetWidth()/2,0,1000));
    gui.add(&dcontent);

    
    
    ofBackground(0);
    ofSetVerticalSync(false);
}

void Controls::update(){
    
}

void Controls::draw(){
    gui.draw();
    ofDrawBitmapString(ofGetFrameRate(),100,600);
    ofDrawBitmapString(zLuz,100,580);
    
//    if(printC == true){
//        ofDrawBitmapString("saveImage",100,580);
//    }

    //ofDrawBitmapString(ofGetFrameRate(),20,20);

}