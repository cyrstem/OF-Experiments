#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(39);
    ofSetWindowTitle("DotSphere@cyrstem");
    ofSetWindowShape(800, 800);
    dots.load("bpdotslight.otf",12);
    gui.setup();
    gui.setName("Sphere");
    gui.add(resolution.setup("Resolution",12, 8, 100));
    gui.add(sphereSize.setup("Size of the Sphere",100, 10, 200));
    gui.add(smallsphereSize.setup("Size of the Small Sphers",1, 0.1, 2));
    hideMenu =  false;
    
    ofBuffer buffer = ofBuffer("fsociety.txt");
    if(buffer.size()) {
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            
            string line = *it;
            
            // copy the line to draw later
            // make sure its not a empty line
            if(line.empty() == false) {
                mrRobot.push_back(line);
            }
            
            // print out the line
            cout << line << endl;
            
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    dots.drawString("'f' fullscreen", 10, ofGetHeight()-45);
    dots.drawString("'h' Show menups", 10, ofGetHeight()-25);
    dots.drawString("'enter' save ScreenCap", 10, ofGetHeight()-10);
    //string type = line ;
    
    cam.begin();
    //ofEnableDepthTest();
    sphere.set(sphereSize, resolution);
    vertices = sphere.getMesh().getVertices();
    
    for (int i =0 ; i<vertices.size(); i++) {
        ofPoint v = vertices[i];
        ofDrawSphere(v.x, v.y,v.z, smallsphereSize);
        //ofDrawBitmapString("hello", v.x, v.y, v.z);
//        for (int i = 0; i<mrRobot.size();i++) {
//            cout << mrRobot[i] << endl;
//        }
        
//        line.drawString();
        //ofDrawRectangle(v.x, v.y,v.z, 5, 5);
    }
    
    //sphere.drawWireframe();
    sphere.setGlobalPosition(0, 0, 0);
    cam.end();
    
    if (hideMenu)gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'h')hideMenu =!hideMenu;
     if (key == OF_KEY_RETURN) ofSaveScreen("screenshot"+ofToString(ofRandom(0,1000),0)+".png");
    if (key=='f') {
        ofSetFullscreen(true);
    }
    
    
}

//--------------------------------------------------------------

