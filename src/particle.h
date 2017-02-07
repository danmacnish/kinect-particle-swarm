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
    float v_scalar1;
    float v_scalar2;
    float p_scalar;
    float unique_val; //allows us to make each particle slightly different
    int x_lim;
    int y_lim;
    int size;
    float vel_lim;
    
public:
    particle(int x, int y);
    void update(const ofImage &image, ofPoint &global);
    void draw(void);
    void reset(void);
    ~particle();
};


#endif /* particle_h */