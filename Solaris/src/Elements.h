//
//  Elements.h
//  Solaris
//
//  Created by Jacobo Heredia on 2/4/18.
//
//

#ifndef __Solaris__Elements__
#define __Solaris__Elements__

#include "ofMain.h"
class Element : public ofNode{
    public:
    
    void setup(float _size, float _orbitRadius, float _speed,ofVec3f _position);
    void update();
    void customDraw();
    
private:
    float size;
    float speed;
    float orbitRadius;
    float latitud;
    float longitud;
    ofVec3f position;
    Element * parent;



};

#endif /* defined(__Solaris__Elements__) */
