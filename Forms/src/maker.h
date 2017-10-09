//
//  maker.h
//  Forms
//
//  Created by Jacobo Heredia on 3/10/17.
//
//

#ifndef __Forms__maker__
#define __Forms__maker__

#include "ofMain.h"
class Maker{
public:
    //metodos
    void setup();
    void update();
    void draw();
    //contructor
    
    Maker();
private:
    ofVec2f pos;
    vector<float> miPosition;
    vector<float> miIncremento;
};
#endif /* defined(__Forms__maker__) */
