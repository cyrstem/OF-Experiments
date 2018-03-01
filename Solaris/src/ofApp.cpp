#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Audio Galaxy-Solaris 0.3b");
    ofLog(OF_LOG_VERBOSE);
    ofTrueTypeFont::setGlobalDpi(72);
    ofSetBackgroundColor(15);
    ofSetWindowShape(1024, 900);
    font.load("Lato-Light.ttf", 15);
  
    //loading files
    dir.listDir("audio");
    dir.sort();
    if( dir.size() ){
        sounds.resize(dir.size());
        ofLog(OF_LOG_NOTICE,"songs loaded");
    }
    for ( i =0; i<dir.size(); i++) {
        sounds[i].load(dir.getPath(i));
        //cout<< sounds[<<endl;
    }
    //charater count para cajas
    char tempString[255];
    rect = font.getStringBoundingBox(tempString, 0,0);

    ofSetSmoothLighting(true);
    //poision camara
    cam.setPosition(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 900);

//objetos inicio
    //lineWidht y alpha
    orb.init(3.5,239);
    orb2.init(3.2,150);
    orb3.init(4.5,50);
    orb4.init(4.5,50);
    orb5.init(5.5,100);
//elements
   
    // luces set

    //luz setup
//    luz.setPosition(ofGetWindowWidth()/2, 300, 400);
    luz0 =false;
    //load textos
    fbo.allocate(400, ofGetHeight()/2,GL_RGBA);
    fbo.begin();
        ofClear(0, 0, 0, 0);
    fbo.end();
    
    ui();
    posLightXY = ofPoint(0,ofGetHeight()/2);
    //luzX = 0;
    //luzY = ofGetHeight()/2;
    luzZ = 0;
    orbitSpeed = 0.0;

    cam.setTarget(ofVec3f(0,0,0));
    //luz.setAmbientColor(ofColor::whiteSmoke);
    //particle
    part.setup();
}

//--------------------------------------------------------------
void ofApp::elementData(){
    //size ,position, someother shit that didn't work nose por q
    uno.setup(1+reaction, 0, 3,ofVec3f(0,30,100));
    dos.setup(0.2*reaction,150, 40,ofVec3f(78,410,0));
    tres.setup(0.2*reaction, -150, 10,ofVec3f(0,10,23));
//    cuatro.setup(2, 9, 100,ofVec3f(0,60,32));
//    cinco.setup(1, 300, 190,ofVec3f(0,10,322));
    
}
//--------------------------------------------------------------
void ofApp::update(){
    elementData();
    luz.setPosition(posLightXY.x,posLightXY.y, luzZ);
    ofSoundUpdate();
    float *spectrum = ofSoundGetSpectrum(256);
    double level = 0;
    for (int i = 0 ; i<128; i++) {
        level+=spectrum[i] * spectrum[i];
    }
    level =sqrt(level/128);
    
    //this is key
    reaction =ofMap(level, 0, 1, 0.3, 100);
     time = ofGetElapsedTimef() -reaction;
    //text marquer
    
        
    uno.update();
    dos.update();
    tres.update();
    cuatro.update();
    cinco.update();
    //particula update
    part.update(34);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
        data();
    fbo.end();
    
    //float posYCam = 0 ;
    float sizeOrbit = ofMap(reaction, 0, 1, 0.3, 50);
    
    
    //Rotate the coordinate system
    float time = ofGetElapsedTimef();	//Get time in seconds
    float angle = time * 30;
    
    
    

    
    cam.begin();
    //ofEnableAlphaBlending();
    if (luz0==true) {
        
        luz.enable();
        ofEnableDepthTest();
    }
    else {
        luz0==false;
        ofDisableLighting();
         //luz.disable();
        ofDisableDepthTest();
    
    }
   // variables to pass
    //offset
    //radio
    //resolucion
    //  relleno color

    orb.customDraw(reaction, 50,100,false,ofColor::white);
    orb2.customDraw(reaction, 60,600,false,ofColor::white);
    orb3.customDraw(reaction, 70,800,false,ofColor::white);
    orb4.customDraw(reaction, 100, 900, false, ofColor::white);
    ofSetLineWidth(4);
    uno.draw();
    dos.draw();
    tres.draw();
//    cuatro.draw();
//    cinco.draw();
    
    //particula draw
    part.draw();
    part1.draw();
    part3.draw();
    
    ofPushStyle();
    ofNoFill();
    ofSetColor(82, 104, 92, 205);
    ofDrawBox(0,0,0,300,300,30*2);
    ofDrawBox(0,0,-10+5, 300, 300, 10);
    ofDrawBox(0,0,10-5, 300, 300, 10);
    // Corners
    
    ofSetColor(82, 104, 92, 255);
    ofPopStyle();
    //    outlineShader.setUniform1f("alpha_adjust", 1);
    for (int x = -1; x <= 1; x += 2) {
        for (int y = -1; y <= 1; y += 2) {
            for (int z = -1; z <= 1; z += 2) {
                drawCorner(ofPoint(x*(300/2+10), y*(300/2+10), z*(10+10)));
            }
        }
    }

    


    
    luz.disable();
    ofDisableAlphaBlending();
    cam.end();

    // Ui de lista de canciones se dibuja aqui '
    
    ofSetColor(255);
    fbo.draw( 0, 0);

    
    
    }
//--------------------------------------------------------------
void ofApp::ui(){
    //gui control stafff
    ofColor guiColor =(255,255,255);
    gui = new ofxUISuperCanvas("Solaris Ctrl");
    gui->setColorFill(guiColor);
    gui->addSpacer();
    gui->addLabel("Light Control");
    gui->addSpacer();
    gui->add2DPad("Posicion X Y",ofPoint(0,ofGetWidth()), ofPoint(0, ofGetHeight()), &posLightXY);
    gui->addSlider("Luz Z", 0.0, 2000.0, &luzZ);
    

    gui->addSpacer();
    gui->addSlider("rotationSpeed", 0.2, 1, &orbitSpeed);
   
    gui->addSpacer();
    gui->addLabel("General Info ");
//    string textString = "salvar 's', full screen 'f' , detener mouse 'm', activar mouse 'n'";
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");


}
//--------------------------------------------------------------
void ofApp::exit(){
    gui->saveSettings("settings.xml");
    delete gui;
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){

}
//--------------------------------------------------------------
void ofApp::data(){

    ofSetBackgroundColor(ofColor::black);
    
    
    if (dir.size() > 0){
        ofSetColor(ofColor::black);
       
    }
    
    //ofSetColor(ofColor::white);
    for(int i = 0; i < (int)dir.size(); i++){
        if(i == current) {
            ofSetColor(ofColor::white,225);
            
        }	else {
            
            ofSetColor(ofColor::whiteSmoke,128);
        }
        
        string fileInfo = "*" + ofToString(i + 1) + " = " + dir.getName(i);
        font.drawString(fileInfo, 10,i * 20 + 20);
        
        //this lines of code will draw selection
        ofSetLineWidth(0.1);
        ofNoFill();
        rect = font.getStringBoundingBox(fileInfo, 10,i*20+20);
        ofSetColor(ofColor::whiteSmoke,255);
        ofDrawRectangle(rect.x, rect.y, rect.width, rect.height);
//
    }
   

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case OF_KEY_DOWN:
            
            if (dir.size() > 0 && sounds[current].isLoaded()){
                sounds[current].stop();
                current++;
                current %= dir.size();
                luz0 =false;
                 ofLog(OF_LOG_NOTICE,"luz off ");
                
            }
            break;
        case OF_KEY_UP:
            if (dir.size() > 1 && sounds[current].isLoaded()){
                sounds[current].stop();
                current= current-1;
                current %= dir.size();
                luz0 =false;
                ofLog(OF_LOG_NOTICE,"luz off ");
            
            }
            
            break;
            
        case OF_KEY_RETURN:
            
            sounds[current].play();
            luz0 =true;
            ofLog(OF_LOG_NOTICE,"luz on ");
            break;
            
        case 'f' :
            ofToggleFullscreen();
            break;
            
        case 's':
            //grabScreen
            img.grabScreen(0, 0, ofGetWindowWidth(),ofGetWindowHeight());
            img.save("saveImg/screenshot"+ofToString(ofRandom(0,1000),0)+".jpg",OF_IMAGE_QUALITY_HIGH);
            ofLog(OF_LOG_NOTICE, "Image is save");
            
            break;
        case 'h':
             gui->toggleVisible();
            break;
            
            
      
    }


}

void ofApp::drawCorner(ofPoint p){
    float pl = 10.0;
    ofDrawLine(p.x, p.y, p.z, p.x, p.y, p.z-sin(p.z)*pl);
    ofDrawLine(p.x, p.y, p.z, p.x, p.y-sin(p.y)*pl, p.z);
    ofDrawLine(p.x, p.y, p.z, p.x-sin(p.x)*pl, p.y, p.z);
}


