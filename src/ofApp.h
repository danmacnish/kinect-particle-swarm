#pragma once

#include "ofMain.h"
#include "ofxGif.h"
#include "ofxOpenCv.h"
#include "particle.h"
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

        ofVideoPlayer video;
        ofxGIF::fiGifLoader gif;
        //vector<ofxCvGrayscaleImage> images;
        vector<ofImage> images;
        int index = 0;
        vector<particle> particles;
        int num_particles = 5;
		
};
