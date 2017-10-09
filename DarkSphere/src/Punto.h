//
//  Punto.h
//  DarkSphere
//
//  Created by Jacobo Heredia on 8/9/17.
//
//

#ifndef __DarkSphere__Punto__
#define __DarkSphere__Punto__

#include "ofMain.h"
class Punto{
public:
    void update();
    void draw();
    Punto();
    ofPoint pos;
    ofColor color;
    ofVec3f vel;
   
    //revisar lo de la ultima posicion
    ofVec3f lastPosition;
    float size, increment;
    
    
    //time and shit
    int vida;
    int tiempoVida;
    bool isDead;
    
    //crear  un verdadero   LIFE PArticle TRUE  this shit aint  working 
    unsigned long last;
    int counter;
    
};

#endif /* defined(__DarkSphere__Punto__) */
