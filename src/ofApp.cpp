#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //set OF log level
    ofSetLogLevel(OF_LOG_WARNING);
    
    //set our background to black
    ofBackgroundHex(0x000000);
    
    //disable ARB textures (non-arb textures are better supported), and load the texure
    ofDisableArbTex();
    ofLoadImage(texture, "dot.png");
    
    // set the camera distance
    camDist  = 1605;
    camera.setDistance(camDist);
    
    //seed random number generator
    ofSeedRandom();
    
    //set listener methods for gui sliders
    scalar1.addListener(this, &ofApp::scalar1Changed);
    scalar2.addListener(this, &ofApp::scalar2Changed);
    scalar3.addListener(this, &ofApp::scalar3Changed);
    scalar4.addListener(this, &ofApp::scalar4Changed);
    velocityLimit.addListener(this, &ofApp::velocityLimitChanged);
    particleSize.addListener(this, &ofApp::particleSizeChanged);
    gradientRadius.addListener(this, &ofApp::gradientRadiusChanged);
    
    //init gui
    gui.setup("particle settings", "particle settings", 650, 200);
    //add slider for scalar 1, init slider to 0.5, range 0 to 20
    gui.add(scalar1.setup("gradient force", 650, 0, 2000));
    gui.add(scalar2.setup("anchor force", 2000000, 0, 4000000));
    gui.add(scalar3.setup("random noise", 0.06, 0, 0.5));
    gui.add(scalar4.setup("current velocity", 0.86, 0, 1));
    gui.add(velocityLimit.setup("velocity limit", 2.25, 1, 5));
    gui.add(particleSize.setup("particle size", 3, 1, 5));
    gui.add(gradientRadius.setup("gradient radius", 23, 1, 30));
    
    //load the kinect frames in png format
    string path = "kinect data/raw frames/frame";
    
    //set video to paused
    paused = true;
    
    for(int i=0; i < 530; i++){
        string filePath = path + to_string(i) + ".png";
        images.push_back(ofImage());
        images[i].allocate(640,480,OF_IMAGE_GRAYSCALE);
        ofLoadImage(images[i].getPixels(), filePath);
    }
    ofLogNotice() << "loaded images";
    
    //init particles
    for(int i = 0; i < num_particles; ++i) {
        particle p(630,479);
        particles.push_back(p);
    }
    ofLogNotice() << "initialised particles";
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //index frames
    if (ofGetElapsedTimeMillis() % 3 && !paused)
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
    ss << "press p to pause/unpause playback" << endl;
    ofDrawBitmapString(ss.str().c_str(), 650, 50);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r') {
        //reset particles
        for(auto it = particles.begin(); it != particles.end(); ++it) {
            it->reset();
        }
    }
    else if(key == 'p') {
        //pause/unpause playback
        this->paused = !paused;
    }
}

//--------------------------------------------------------------
void ofApp::scalar1Changed(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setScalar1(val);
    }
}

//--------------------------------------------------------------
void ofApp::scalar2Changed(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setScalar2(val);
    }
}

//--------------------------------------------------------------
void ofApp::scalar3Changed(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setScalar3(val);
    }
}

//--------------------------------------------------------------
void ofApp::scalar4Changed(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setScalar4(val);
    }
}

//--------------------------------------------------------------
void ofApp::velocityLimitChanged(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setVelocityLimit(val);
    }
}

//--------------------------------------------------------------
void ofApp::particleSizeChanged(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setParticleSize(static_cast<int>(val));
    }
}

//--------------------------------------------------------------
void ofApp::gradientRadiusChanged(float &val) {
    //set scalar 1 for each particle. scalar 1 is the weight given to the particles local best position
    for(auto it = particles.begin(); it != particles.end(); ++it) {
        it->setGradientRadius(static_cast<int>(val));
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
