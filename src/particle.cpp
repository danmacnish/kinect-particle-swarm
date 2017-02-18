//
//  particle.cpp
//  kinect particle swarm
//
//  Created by Daniel Macnish on 2/02/2017.
//
//

#include <vector>
#include "particle.h"

///////////////////////////////////////////////////////////////////////////////
//constructor, initialises particle at random Position from 0,0 to x,y
///////////////////////////////////////////////////////////////////////////////

particle::particle(int x, int y) : xLim(x), yLim(y) {
    uniqueVal = ofRandom(-10000,10000);
    anchorPos.x = ofRandom(0, xLim);
    anchorPos.y = ofRandom(0, yLim);
    //initialise particle at anchor position
    currentPos = anchorPos;
    //initialise noise vector
    noise.x = ofNoise(uniqueVal, currentPos.y * 0.05, ofGetElapsedTimef() * 0.6);
    noise.y = ofNoise(uniqueVal, currentPos.x * 0.05, ofGetElapsedTimef() * 0.6);
    //set velocity to 0
    vel.set(0,0);
    velLim = 10;
    size = 5;
    gRadius = 16;
    v_scalar1 = 2; //scales gradient vector
    v_scalar2 = 3; //scales distance from current position to anchor position
    v_scalar3 = 1; //scales random noise
}

///////////////////////////////////////////////////////////////////////////////
//update particle currentPosition, based on depth data & global best currentPosition
///////////////////////////////////////////////////////////////////////////////

void particle::update(const ofImage &image) {
    //calculate random perlin noise to inject into particle velocity
    noise.x = ofNoise(uniqueVal, currentPos.y * 0.05, ofGetElapsedTimef() * 0.6);
    noise.y = ofNoise(uniqueVal, currentPos.x * 0.05, ofGetElapsedTimef() * 0.6);
    
    //calculate gradient vector around particle then normalise
    calculateGradientVector(image);
    gradient.normalize();
    
    //calculate distance from current position->anchor position then normalise
    anchorDistance = anchorPos - currentPos;
    anchorDistance.normalize();
    
    //calculate velocity of particle based on gradient @ current position, distance from anchor position, and random perlin noise
    vel = v_scalar1*gradient + v_scalar2*anchorDistance + v_scalar3*noise;
    
    //limit velocity
    vel.limit(velLim);
    //update currentPosition
    currentPos += vel;
    //limit the particle to stay within bounds
    if( currentPos.x > xLim ){
        currentPos.x = xLim;
        vel.x *= -1.0;
    }else if( currentPos.x < 0 ){
        currentPos.x = 0;
        vel.x *= -1.0;
    }
    if( currentPos.y > yLim ){
        currentPos.y = yLim;
        vel.y *= -1.0;
    }
    else if( currentPos.y < 0 ){
        currentPos.y = 0;
        vel.y *= -1.0;
    }
}

///////////////////////////////////////////////////////////////////////////////
//draw the particle
///////////////////////////////////////////////////////////////////////////////

void particle::draw(void) {
    ofSetColor(208, 255, 63);
    ofDrawCircle(currentPos, size);
}

////////////////////////////////////////////////////////////////////////////////
//reset particle currentPositions
///////////////////////////////////////////////////////////////////////////////

void particle::reset(void) {
    //re spawn particles in new currentPositions with new velocities
    currentPos.x = ofRandom(0, xLim);
    currentPos.y = ofRandom(0, yLim);
    anchorPos = currentPos;
    vel.x = 0;
    vel.y = 0;
}

////////////////////////////////////////////////////////////////////////////////
//get reference to current particle position
///////////////////////////////////////////////////////////////////////////////

void particle::calculateGradientVector(const ofImage &image) {
    //get the current z value
    ofColor col = image.getColor(currentPos.x, currentPos.y);
    currentZ = col.getBrightness();
    //get the z value of four points around particle
    ofColor Pleft = image.getColor(ofClamp(currentPos.x - gRadius, 0, image.getWidth()-1), currentPos.y);
    ofColor Pright = image.getColor(ofClamp(currentPos.x + gRadius, 0, image.getWidth()-1), currentPos.y);
    ofColor Pup = image.getColor(currentPos.x, ofClamp(currentPos.y - gRadius, 0, image.getHeight()-1));
    ofColor Pdown = image.getColor(currentPos.x, ofClamp(currentPos.y + gRadius, 0, image.getHeight()-1));
    //calculate x and y components of gradient vector based on four values around particle
    //g scalar adjusts size of vector
    gradient.x = (-(currentZ - Pleft.getBrightness())/gRadius) + ((currentZ - Pright.getBrightness())/gRadius);
    gradient.y = (-(currentZ - Pup.getBrightness())/gRadius) + ((currentZ - Pdown.getBrightness())/gRadius);
}

////////////////////////////////////////////////////////////////////////////////
//get reference to current particle position
///////////////////////////////////////////////////////////////////////////////

const ofVec2f &particle::getCurrentPosition(void) {
    return currentPos;
}

////////////////////////////////////////////////////////////////////////////////
//set radius of gradient calculation
///////////////////////////////////////////////////////////////////////////////

void particle::setGradientRadius(int val) {
    gRadius = val;
}

////////////////////////////////////////////////////////////////////////////////
//set scalar 1
///////////////////////////////////////////////////////////////////////////////

void particle::setScalar1(float val) {
    v_scalar1 = val;
}

////////////////////////////////////////////////////////////////////////////////
//set scalar 2
///////////////////////////////////////////////////////////////////////////////

void particle::setScalar2(float val) {
    v_scalar2 = val;
}

////////////////////////////////////////////////////////////////////////////////
//set scalar 3
///////////////////////////////////////////////////////////////////////////////

void particle::setScalar3(float val) {
    v_scalar3 = val;
}

////////////////////////////////////////////////////////////////////////////////
//set velocity limit
///////////////////////////////////////////////////////////////////////////////

void particle::setVelocityLimit(float val) {
    velLim = val;
}

////////////////////////////////////////////////////////////////////////////////
//set particle size
///////////////////////////////////////////////////////////////////////////////

void particle::setParticleSize(int val) {
    size = val;
}

particle::~particle() {
   
}





