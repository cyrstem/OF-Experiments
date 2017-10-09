#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    camW = 320;
    camH = 240;
    
//    camW = 720;
//    camH = 480;
    
    red = 255;
    green = 255;
    blue = 255;
    
    grabber.setup(camW, camH);
    pixels.allocate(camW, camH, OF_PIXELS_RGB);
    gray.allocate(camW, camH, OF_IMAGE_GRAYSCALE);
    img.allocate(camW, camH,OF_IMAGE_COLOR);
    pixels.set(255);
    ui();
    valueBlended = 0.001;
    //cv staff
    resetBackground = false;
    learningTime = 10;
    thresholdValue = 10;
    
    //CV contour finder;
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(150);
    threshold = 0;
    trackHs = false;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // For each pixel column, except the last one ...
                if (x < grabber.getWidth() + 1)
                {
                    // Get the color to the right from the LAST pixels saved.
                    ofColor lastColorToTheRight = pixels.getColor(x , y+2);
                    
                    // Get a copy of the current color from the camera.
                    ofColor currentColor = grabber.getPixels().getColor(x, y);
                    
                    // Blend the two colors (0.01 will favor the last, closer to
                    // 1 will favor the current live camera color.
                    ofColor blended = lastColorToTheRight.getLerped(currentColor,ofRandom(0,valueBlended));
                    
                    pixels.setColor(x, y, blended +3);
                    
                   
                }
                else
                {
                    // Otherwise, just save the raw pixel in the last row
                    // (because otherwise we couldn't access x + 1 because it
                    // wouldn't exist).
                    pixels.setColor(x, y, grabber.getPixels().getColor(x, y));
                }
            }
        }
        background.setLearningTime(learningTime);
        background.setThresholdValue(thresholdValue);
        background.update(grabber, thresholded);
        thresholded.update();

        
        
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(grabber);

    }
    
    texture.loadData(pixels);
//    glitchedLines.push_back(pixels);
//    cout <<glitchedLines.size()<<endl;
    
   

   
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(red,green,blue);
        texture.draw(10, 300);
    ofPopStyle();
    grabber.draw(10, 10, 320, 240);
    
    if(thresholded.isAllocated()) {
        thresholded.draw(340, 10);
    }
    ofSetLineWidth(2);
    contourFinder.draw();
    
    int n = contourFinder.size();
    for(int i = 0; i < n; i++) {
        // smallest rectangle that fits the contour
        ofSetColor(targetColor);
        ofPolyline minAreaRect = toOf(contourFinder.getMinAreaRect(i));
        minAreaRect.draw();
        
         //ellipse that best fits the contour
//        ofSetColor(magentaPrint);
//        cv::RotatedRect ellipse = contourFinder.getFitEllipse(i);
//        ofPushMatrix();
//        ofVec2f ellipseCenter = toOf(ellipse.center);
//        ofVec2f ellipseSize = toOf(ellipse.size);
//        ofTranslate(ellipseCenter.x, ellipseCenter.y);
//        ofRotate(ellipse.angle);
//        ofDrawEllipse(0, 0, ellipseSize.x, ellipseSize.y);
//        ofPopMatrix();
        
        // minimum area circle that encloses the contour
//        ofSetColor(cyanPrint);
//        float circleRadius;
//        ofVec2f circleCenter = toOf(contourFinder.getMinEnclosingCircle(i, circleRadius));
//        ofDrawCircle(circleCenter, circleRadius);
        
        // convex hull of the contour
        ofSetColor(yellowPrint);
        ofPolyline convexHull = toOf(contourFinder.getConvexHull(i));
        convexHull.draw();
        
        // defects of the convex hull
        vector<cv::Vec4i> defects = contourFinder.getConvexityDefects(i);
        for(int j = 0; j < defects.size(); j++) {
            ofDrawLine(defects[j][0], defects[j][1], defects[j][2], defects[j][3]);
        }
        
        // some different styles of contour centers
        ofVec2f centroid = toOf(contourFinder.getCentroid(i));
        ofVec2f average = toOf(contourFinder.getAverage(i));
        ofVec2f center = toOf(contourFinder.getCenter(i));
        ofSetColor(cyanPrint);
        ofDrawCircle(centroid, 1);
        ofSetColor(magentaPrint);
        ofDrawCircle(average, 1);
        ofSetColor(yellowPrint);
        ofDrawCircle(center, 1);
        
        // you can also get the area and perimeter using ofPolyline:
        // ofPolyline::getArea() and ofPolyline::getPerimeter()
        double area = contourFinder.getContourArea(i);
        double length = contourFinder.getArcLength(i);
        
        // balance is useful for detecting when a shape has an "arm" sticking out
        // if balance.length() is small, the shape is more symmetric: like I, O, X...
        // if balance.length() is large, the shape is less symmetric: like L, P, F...
        ofVec2f balance = toOf(contourFinder.getBalance(i));
        ofPushMatrix();
        ofTranslate(centroid.x, centroid.y);
        ofScale(5, 5);
        ofDrawLine(0, 0, balance.x, balance.y);
        ofPopMatrix();
    }
    gray.clone(img);
    gray.draw(360, 400);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofSetFullscreen(true);
            break;
        case 's':
            img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            img.save("saveImg/screenshot"+ofToString(ofRandom(0,1000),0)+".jpg");
            break;

    }
}

//--------------------------------------------------------------
void ofApp::ui(){
    gui = new ofxUISuperCanvas("VFX controls");
    gui->addSpacer();
    gui->addLabel("BACKGROUND", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addSlider("Blended V", 0.001, 1, &valueBlended);
    gui->addToggle("FULLSCREEN", false);
    gui->addButton("SAVEIMAGE", false);
    gui->addSpacer();
    gui->addLabel("Color", OFX_UI_FONT_MEDIUM);
    gui->addSlider("Red", 0, 255, &red);
    gui->addSlider("Green", 0, 255, &green);
    gui->addSlider("Blue", 0, 255, &blue);
    gui->addSpacer();
    gui->addLabel("Open Cv", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addButton("ResetBackground", false);
    gui->addSlider("LearningTim", 0, 30, &learningTime);
    gui->addSlider("thresholdVal", 0, 255, &thresholdValue);
    gui->addSpacer();
    gui->addLabel("Contour Finder", OFX_UI_FONT_MEDIUM);
    gui->addToggle("trackHs", false);
    gui->addSlider("threshold", 0, 255, &threshold);

    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
    
   


}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{
 
    
    if(e.getName() == "FULLSCREEN")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());

    } else if(e.getName() =="SAVEIMAGE"){
        ofxUIButton *button = (ofxUIToggle *) e.widget;
        img.grabScreen(texture.getWidth(), texture.getHeight(), grabber.getWidth(), grabber.getHeight());
        img.save("saveImg/screenshot"+ofToString(ofRandom(0,1000),0)+".png");
        ofLog(OF_LOG_NOTICE, "Image is save");

    } else if (e.getName() =="ResetBackground"){
        ofxUIButton *button = (ofxUIToggle *) e.widget;
        background.reset();
        cout<< resetBackground <<endl;
    } else if (e.getName() == "trackHs"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        (toggle->getValue());
        
    }
   
}
//--------------------------------------------------------------
void ofApp::exit()
{
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

//void ofApp::glitchImage() {
//    
//   
//    
//}


