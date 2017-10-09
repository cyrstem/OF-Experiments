#include "ofApp.h"

//--------------------------------------------------------------
//----------Class Particula
//--------------------------------------------------------------
Punto::Punto(){
    pos =ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    size = 0.5f;
    increment = 0.2f;    //vel.set(1,2);
    last = ofGetElapsedTimeMillis();
    color = ofColor::fromHsb(155, 147, 164);
    
    
    
//    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
//    fbo.begin();
//    ofClear(0,0,0,0);
//    fbo.end();


    
    

//el contruct  tiene q tener las variables
// iniciadas por q si no no carga nada
//el setup  no es necesario  o  a su vez el contruct no es necesario pero ambas deben tener   una inicializacion  de  las variables
    
}
//--------------------------------------------------------------

//--------------------------------------------------------------
void Punto::update(){

    pos += vel ;
        size += increment;
    
    
        if (size >= 1.5 || size <= 0) {
            increment *= -1;
            
        }
    
    
    if(ofGetElapsedTimeMillis() - last > 10)
    {
        
        color.setHue(counter % 236);

        counter ++;
        last = ofGetElapsedTimeMillis();
    }
//     cout<<last<<endl;
    
}

//--------------------------------------------------------------
void Punto::draw(){
   

//    fbo.begin();
        ofSetColor(color);
        ofDrawSphere(pos, size);
//    fbo.end();
//
//    fbo.draw(pos);
    
    //ofDrawCircle(pos, size);
    
    //let's draw to the screen the size of the circle and the increment
    
    //ofDrawBitmapString("increment:" + ofToString(increment), 10, 40);
    
}
//--------------------------------------------------------------
void Punto::reset(){
    
}

//--------------------------------------------------------------
//----------Main OF
//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(24);
    ofSetBackgroundColor(25);
    ofSetWindowShape(800, 800);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofEnableDepthTest();
    pSphereRes = 32;

    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i =0; i<p.size(); i++) {
        p[i].update();
        
    }


//    if (p.size()<= ofGetElapsedTimef()) {
//
//    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    
   cout << p.size() << endl;
    cam.begin();
    luz.enable();

    
    
    // el for que dibuja debe de estar dentro de la camara para q la camara la pueda ver y la pueda centrar en el objeto
    
    for (int i =0; i<p.size(); i++) {
   
            p[i].draw();
     
    }
    
    sphere.set(100 , pSphereRes);
    vertices = sphere.getMesh().getVertices();
    //cout << vertices<<endl;
    
    for (int i =0 ; i<vertices.size(); i++) {
        ofPoint v = vertices[i];
        //esto pasa las posiciones dentro de los vertices de la esfera
         //con un
        if (ofGetFrameNum() % 100 == 0){
            
            Punto pTemp;
            //esta era mi idea tonta
            //pTemp.pos = v;
            //esto lo hace  mas cool
            //pTemp.pos = v + ofPoint( ofNoise(1.2), ofNoise(1.3));
            pTemp.pos = v + ofPoint( ofRandom(-5,5), ofRandom(-5,5) );
            
                p.push_back(pTemp);
            
            
        }
        
        if (p.size() > 1050){
            p.erase(p.begin());
        }


    }
    
    //sphere.drawWireframe();
    luz.disable();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
        ofSetFullscreen(true);
            break;
        case 's':
            ofSaveScreen("screenshot"+ofToString(ofRandom(0,1000),0)+".png");
            break;

    }
}
