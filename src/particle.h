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
    ofVec2f currentPos; //the current position
    ofVec2f anchorPos; //the position the particle tries to maintain
    ofVec2f vel; //particle velocity
    ofVec2f disturbance; //the disturbance vector (sum of gradients to nearest particles)
    float v_scalar1;
    float v_scalar2;
    float p_scalar;
    float uniqueVal; //allows us to make each particle slightly different
    int size;
    //position and velocity limits
    int xLim;
    int yLim;
    float velLim;
    
public:
    //constructor, pass in x and y position limits
    particle(int x, int y);
    //set methods
    void setDisturbanceVector(ofVec2f vect);
    void setScalar1(float val);
    void setScalar2(float val);
    void setVelocityLimit(float val);
    void setParticleSize(int val);
    
    //get methods
    const ofVec2f &getCurrentPosition(void);
    
    
    void update(const ofImage &image, ofVec2f &global);
    void draw(void);
    void reset(void);
    ~particle();
};


#endif /* particle_h */