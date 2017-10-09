//
//  maker.cpp
//  Forms
//
//  Created by Jacobo Heredia on 3/10/17.
//
//

#include "maker.h"
Maker::Maker(){
    
}

void Maker::setup(){
    ofSetCircleResolution(326);
    miPosition = {0,0,0,0,0,0};
    miIncremento = {1,2,3,4,5};
//
//    pos.x=0;
//    pos.y=ofGetHeight()/2;
}

void Maker::update(){
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

void Maker::draw(){
    
        ofSetColor(ofColor::white);
    for (float position: miPosition)//como funciona esta parte
    {
        ofDrawEllipse(position, 200, 10, 10);
        ofDrawBox(position+10, 10, 20);
//        ofDrawBox(position, 60, 20);
        

        //ofDrawCircle(<#float x#>, <#float y#>, <#float radius#>)
    }


}