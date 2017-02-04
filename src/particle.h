//
//  particle.h
//  kinect particle swarm
//
//  Created by Daniel Macnish on 2/02/2017.
//
//

#ifndef particle_h
#define particle_h

#include "ofMain.h"

class particle {
    ofPoint pos;
    ofPoint vel;
    ofPoint p;
    float v_scalar;
    float p_scalar;
    int x_lim;
    int y_lim;
    int size;
    float vel_lim;
    
public:
    particle(int x, int y);
    void update(const ofImage &image);
    void draw(void);
    ~particle();
};


#endif /* particle_h */