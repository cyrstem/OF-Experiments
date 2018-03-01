#include "ofMain.h"
#include "ofApp.h"
//#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	 //this kicks off the running of my app
	 //can be OF_WINDOW or OF_FULLSCREEN
	 //pass in width and height too:
	ofRunApp(new ofApp());
    
//    ofGLFWWindowSettings settings;
//    settings.width = 800;
//    settings.height = 800;
//    settings.setPosition(ofVec2f(300,0));
//    settings.resizable = true;
//    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
//    
//    settings.width = 300;
//    settings.height = 300;
//    settings.setPosition(ofVec2f(0,0));
//    settings.resizable = false;
//    // uncomment next line to share main's OpenGL resources with gui
//    //settings.shareContextWith = mainWindow;
//    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
//    guiWindow->setVerticalSync(false);
//    
//    shared_ptr<ofApp> mainApp(new ofApp);
//    mainApp->setupGui();
//    ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawGui);
//    //ofAddListener(guiWindow->events().keyPressed(int key),mainApp.get(), &ofApp(::keyPressed(int key));
//    ofRunApp(mainWindow, mainApp);
//    ofRunMainLoop();

}
