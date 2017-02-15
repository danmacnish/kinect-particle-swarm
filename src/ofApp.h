#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "particle.h"
#include "ofxGui.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
        void velocityLimitChanged(float &val);
        void particleSizeChanged(float &val);
        void gradientRadiusChanged(float &val);

        vector<ofImage> images;
        int index = 0;
    
        //particles
        vector<particle> particles;
        int num_particles = 5; //number of particles
    
        //gui
        ofxFloatSlider scalar1;
        ofxFloatSlider scalar2;
        ofxFloatSlider gradientRadius;
        ofxFloatSlider velocityLimit;
        ofxFloatSlider particleSize;
        ofxPanel gui;
		
};
