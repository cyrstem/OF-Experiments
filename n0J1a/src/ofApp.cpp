#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("n0j1a -AV app 0.1");
    ofSetWindowShape(800, 800);
    ofSetBackgroundColor(25);
    ofSetCircleResolution(200);
    cam.setAutoDistance(true);
    ofEnableDepthTest();
    printC = false;
    
    
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
    }else{
        shader.load("shaders/noise.vert", "shaders/noise.frag");
    }
#endif

    //doShader = true;
}

//--------------------------------------------------------------
void ofApp::update(){
luz.setPosition(gui->xLuz, ofGetHeight()/2, gui->zLuz);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofSetColor(gui->color);
    luz.enable();
    sphere.set(gui->radius, gui->resolution);
    sphere.setGlobalPosition(0, 0, 0);
    if (gui->swich == true) {
        
         sphere.drawWireframe();
    } else {
        shader.begin();
        //we want to pass in some varrying values to animate our type / color
        shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
        shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
        
        //we also pass in the mouse position
        //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
        shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
        sphere.draw();
        shader.end();
    }
    
    if (gui->esferas == false) {
        vertices = sphere.getMesh().getVertices();
        for (int i =0 ; i<vertices.size(); i++) {
            ofPoint v = vertices[i];
            ofDrawSphere(v.x, v.y,v.z,gui->esferitasSize);
        }
    }
    
    luz.disable();
    cam.end();
}
//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            ofSaveScreen("screenshot"+ofToString(ofRandom(0,1000),0)+".png");
            cout<<"saveprint"<<endl;
            printC=true;
            break;
            
    }

}


//--------------------------------------------------------------
