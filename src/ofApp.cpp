#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //load the kinect frames
    string path = "kinect data/raw frames/frame";
    
    for(int i=0; i < 544; i++){
        string filePath = path + to_string(i) + ".png";
        images.push_back(ofImage());
        images[i].allocate(640,480,OF_IMAGE_GRAYSCALE);
        ofLoadImage(images[i].getPixels(), filePath);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetElapsedTimeMillis() % 3)
    {
        index++;
        if (index > images.size()-1) index = 0;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    images[index].draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
