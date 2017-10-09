#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Spheres - Vj");
    ofSetWindowShape(800,800);
    ofSetBackgroundColor(25);
    //ofEnableAlphaBlending();
    //ofEnableSmoothing();
    
    cam.setPosition(ofGetViewportWidth()/2, ofGetWindowHeight()/2, 10);
    pSphereRes = 12;
    rotacion.set("Rotacion", 0.5, 0.0, 3.0);
    sizeArray.set("Vector size", 1050, 100, 3050);

    yaap =false;

    gui = new ofxDatGui(10,650);
    gui->setTheme(new ofxDatGuiThemeWireframe());
    gui->addLabel("gui from of_parameters");
    gui->addSlider(rotacion);
    gui->addSlider(sizeArray);


    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i<p.size(); i++) {
        p[i].update();
        
    }
   // p.resize(sizeArray);
    
    gui->update();
    gui->toggle();

}
//--------------------------------------------------------------

void ofApp::draw(){
    
    
    ofEnableDepthTest();
    ofEnableLighting();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //cout << p.size() << endl;
    
    cam.begin();
    luz.enable();
    float rot = rotacion * ofGetFrameNum(); // ofRotate takes degrees
    
    
    ofRotateY(rot);
    
    
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
            pTemp.pos = v + ofPoint( ofRandom(-50,50), ofRandom(-50,50) );
            p.push_back(pTemp);
                        }
        
        if (p.size() > sizeArray){
            p.erase(p.begin());
            
        }
//        if (isDead== true) {
//            
//        }
       

        
    }
    // para poder dibujar una linea entre los dos elementos del vecto
    // tengo q aprender  a  usar esto  acontinuacion  o  aprender a usar referecias y //deferencias   en c++
    

    vector<Punto>::iterator it = p.begin();
    
    float xpos = (*it).pos.x;
    float ypos = (*it).pos.y;
    
    //cout << xpos <<endl;
    float dist = 40;
    
    //Draw lines between near points
//    float dist = 40;	//Threshold parameter of distance
//    for (int j=0; j<n; j++) {
//        for (int k=j+1; k<n; k++) {
//            if ( ofDist( p[j].x, p[j].y, p[k].x, p[k].y )
//                < dist ) {
//                ofLine( p[j], p[k] );
//            }
//        }
//    }
    
    //sphere2.drawWireframe();
    ofDisableBlendMode();
    luz.disable();
    cam.end();
    ofDisableLighting();
    ofDisableDepthTest();
    
    gui->draw();


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
