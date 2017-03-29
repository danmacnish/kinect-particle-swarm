#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "particle.h"
#include "ofxGui.h"
#include "ofxKinect.h"
#include <vector>

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    //gui callback methods
    void scalar1Changed(float &val);
    void scalar2Changed(float &val);
    void scalar3Changed(float &val);
    void scalar4Changed(float &val);
    void velocityLimitChanged(float &val);
    void particleSizeChanged(float &val);
    void gradientRadiusChanged(float &val);
    void nearClipChanged(float & val);
    void farClipChanged(float & val);

    ofxKinect kinect;
    ofImage depthImage;

    vector<ofImage> images;
    int index = 0;

    //particles
    const int numParticles = 1000; //number of particles
    vector<particle> particles;
    vector<ofVec2f> particlePositions;
    vector<ofVec3f> particleSizes;
    int xlimit = 630; //x and y limits of particle position on kinect depth image. 
    int ylimit = 479;
    
    //openGL
    ofVbo vbo; //Vertex buffered object, stores our point vertices on the graphics card. Basically means that we don't have to send the GPU an entire new array of points each time
    ofShader shader;
    ofEasyCam camera;
    float camDist;
    ofTexture texture;

    //gui
    ofxFloatSlider scalar1;
    ofxFloatSlider scalar2;
    ofxFloatSlider scalar3;
    ofxFloatSlider scalar4;
    ofxFloatSlider gradientRadius;
    ofxFloatSlider velocityLimit;
    ofxFloatSlider particleSize;
    ofxFloatSlider nearClip;
    ofxFloatSlider farClip;
    bool drawKinectFrame; //sets whether to draw kinect depth data
    bool hideGUI; //hide or display the GUI
    ofxPanel gui;
    
    //gif playback control
    bool paused;
    
    //angle of kinect
    int angle;
    
    //load video from file or use live video from kinect
    bool liveVideo;
		
};
