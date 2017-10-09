#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(800,800);
    ofBackground(30);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofEnableSmoothing();
    ofEnableLighting();
    luz.setPosition(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 160);
    cam.setPosition(ofGetWidth(), ofGetHeight(),30);
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    luz.enable();
//    for (int i =0 ; i<NCIRC; i++) {
//        myCirculo[i].draw(100, 3, 1600, ofColor::red, 16, 0.3);
//    }
    //ofDrawSphere(0, 0, 50, 50);
    //ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//    int pt = ofRandom(0,5);
    
    sphere.setPosition(0,0,0);
    sphere.setRadius(30);
    sphere.draw();
    
    myCirculo.draw(50, 20, 1600,  ofColor::fromHex(0x379392),16, 0.2);
    myCirculo2.draw(100, 3,1500, ofColor::white,4, 0.1);
    myCirculo3.draw(160, 2,2600, ofColor::red,5, 0.6);
    myCirculo4.draw(180, 1,2600, ofColor::white,6,0.2);
    myCirculo5.draw(200, 3,2600, ofColor::red,6, 0.3);
   
//    ofDrawSphere(0, 0, 30);
    
//    myCirculo6.draw(210, 2,2600, ofColor::fromHex(0xb6ff4d),16, 0.2);
//    myCirculo7.draw(260, 5,2600, ofColor::red,1, 0.35);
//    myCirculo.draw(<#int _rad#>, <#int _tamLinea#>, <#int _cRess#>, <#ofColor _clr#>, <#int _anim#>, <#float _sine#>)
    luz.disable();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's':
            ofSaveScreen("screenshot"+ofToString(ofRandom(0,1000),0)+".png");
            cout<<"saveprint"<<endl;
            break;
            
        case'f':
            ofSetFullscreen(true);
            break;
    }
}
