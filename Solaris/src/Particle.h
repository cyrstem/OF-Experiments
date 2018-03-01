//
//  Particle.h
//  Solaris
//
//  Created by Jacobo Heredia on 2/19/18.
//
//

#ifndef __Solaris__Particle__
#define __Solaris__Particle__

#include "ofMain.h"
class Particle{
public:
    Particle();
    void setup();
    void update(float dt);
    void draw();
    ofPoint pos;
    ofPoint vel;
    float time;
    float lifetime;
    bool live;
};

#endif /* defined(__Solaris__Particle__) */
