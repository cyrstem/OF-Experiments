//
//  OrbitSptr.h
//  Solaris
//
//  Created by Jacobo Heredia on 12/10/17.
//
//

#ifndef __Solaris__OrbitSptr__
#define __Solaris__OrbitSptr__

#include "ofMain.h"
class OrbitSptr{
public:
    void init(float _lSize,float _alfaV);
    void customDraw(float _offset, float _radius,int _resolution,bool _relleno, ofColor _color);

private:
    float reaction;
    bool relleno;
    ofPolyline circle;
    ofColor colors;
    float lineWidth;
    float alfaV;
    float v;
  
    
    
};

#endif /* defined(__Solaris__OrbitSptr__) */
