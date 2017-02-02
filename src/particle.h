//
//  particle.h
//  kinect particle swarm
//
//  Created by Daniel Macnish on 2/02/2017.
//
//

#ifndef particle_h
#define particle_h

#include "ofApp.h"

class particle {
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
    int p_x;
    int p_y;
    float v_scalar;
    float p_scalar;
    int x_lim;
    int y_lim;
    
public:
    particle(int x, int y);
    void update(ofImage *image);
    ~particle();
    
};


#endif /* particle_h */