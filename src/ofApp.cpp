#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //set OF log level
    ofSetLogLevel(OF_LOG_WARNING);
    
    //load the kinect frames in png format
    string path = "kinect data/raw frames/frame";
    
    for(int i=0; i < 530; i++){
        string filePath = path + to_string(i) + ".png";
        images.push_back(ofImage());
        images[i].allocate(640,480,OF_IMAGE_GRAYSCALE);
        ofLoadImage(images[i].getPixels(), filePath);
    }
    
    //init particles
    for(int i = 0; i < num_particles; ++i) {
        particle p(639,479);
        particles.push_back(p);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //index frames
    if (ofGetElapsedTimeMillis() % 3)
    {
        index++;
        if (index > images.size()-1) index = 0;
    }
    //update particles
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->update(images[index]);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255,255,255);
    images[index].draw(0, 0);
    
    //draw the particles
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->draw();
    }
    
    //write framerate and other info to screen
    stringstream ss;
    ss << "Framerate: " << ofToString(ofGetFrameRate(),0) << "\n";
    ss << "press r to reset particles" << endl;
    ofDrawBitmapString(ss.str().c_str(), 700, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r') {
        //reset particles
        for(auto it = particles.begin(); it != particles.end(); ++it) {
            it->reset();
        }
    }
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
