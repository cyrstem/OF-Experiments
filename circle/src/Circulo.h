//
//  Circulo.h
//  circle
//
//  Created by Jacobo Heredia on 5/16/17.
//
//

#ifndef __circle__Circulo__
#define __circle__Circulo__

#include "ofMain.h"
class Circulo{
public:
    void setup();
    void update();
    void draw(int _rad ,int _tamLinea, int _cRess, ofColor _clr,int _anim, float _sine);
    Circulo();
    int rad;
    int tamLinea;
    int cReso;
    float sines;
    ofColor clr;
    
};

#endif /* defined(__circle__Circulo__) */

