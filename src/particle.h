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
    ofVec3f currentPos; //the current position
    float currentZ; //current depth value
    ofVec3f anchorPos; //the position the particle tries to maintain
    ofVec3f anchorDistance; //distance from current position to anchor position
    ofVec3f vel; //particle velocity
    ofVec3f gradient; //the disturbance vector (gradient around particle)
    ofVec3f noise; //noise vector
    int gRadius; //used when calculating gradient around particle. larger value means gradient will be calculated over a larger distance
    float v_scalar1; //scales gradient vector
    float v_scalar2; //scales distance from current position to anchor position
    float v_scalar3; //scales perlin noise
    float v_scalar4; //amount that new velocity is influenced by current velocity
    float uniqueVal; //allows us to make each particle slightly different
    int size;
    //position and velocity limits
    int xLim;
    int yLim;
    float velLim;
    float distLimSquared; //maximum distance^2 from particle to anchor position
    
public:
    //constructor, pass in x and y position limits
    particle(int x, int y);
    //set methods
    void setGradientRadius(int val);
    void setScalar1(float val);
    void setScalar2(float val);
    void setScalar3(float val);
    void setScalar4(float val);
    void setVelocityLimit(float val);
    void setParticleSize(int val);
    
    //get methods
    const ofVec3f &getCurrentPosition(void);
    
    //update particle position based on depth data
    void update(const ofImage &image);
    //draw particle
    void draw(void);
    ///reset particle to new position and 0 velocity
    void reset(void);
    ~particle();

private:
    //calculate gradient vector for particle (i.e. disturbance vector). called inside update()
    void calculateGradientVector(const ofImage &image);
};


#endif /* particle_h */