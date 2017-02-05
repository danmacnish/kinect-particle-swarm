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
//constructor, initialises particle at random position from 0,0 to x,y
///////////////////////////////////////////////////////////////////////////////

particle::particle(int x, int y) : x_lim(x), y_lim(y) {
    pos.x = ofRandom(0, x_lim);
    pos.y = ofRandom(0, y_lim);
    vel_lim = 15;
    size = 5;
    vel.x = static_cast<int>(ofRandom(-5, 5));
    vel.y = static_cast<int>(ofRandom(-5, 5));
    p = pos; //initialise best known position as current position
    v_scalar1 = 15; //scales distance from particle to local best position
    v_scalar2 = 5; //scales distance from particle to global best position
    p_scalar = 1;
}

///////////////////////////////////////////////////////////////////////////////
//update particle position, based on depth data & global best position
///////////////////////////////////////////////////////////////////////////////

void particle::update(const ofImage &image, ofPoint &global) {
    //update velocity
    vel.x += ofRandom(0,1)*v_scalar1*(p.x - pos.x) + ofRandom(0,1)*v_scalar2*(global.x - pos.x);
    vel.y += ofRandom(0,1)*v_scalar1*(p.y - pos.y)+ ofRandom(0,1)*v_scalar2*(global.x - pos.x);;
    //limit velocity
    vel.limit(vel_lim);
    //update position
    pos += vel;
    //limit the particle to stay within bounds
    if( pos.x > x_lim ){
        pos.x = x_lim;
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > y_lim ){
        pos.y = y_lim;
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
    //update best known position if new position is better
    ofColor newVal = image.getColor(pos.x, pos.y);
    ofColor localBest = image.getColor(p.x, p.y);
    ofColor globalBest = image.getColor(global.x, global.y);
    if(newVal.getBrightness() > localBest.getBrightness()) {
        p = pos; //new local best is current position
        if(localBest.getBrightness() > globalBest.getBrightness()) {
            global = p; //update global best if local best is better
        }
    };
}

///////////////////////////////////////////////////////////////////////////////
//draw the particle
///////////////////////////////////////////////////////////////////////////////

void particle::draw(void) {
    ofSetColor(208, 255, 63);
    ofDrawCircle(pos, size);
}

////////////////////////////////////////////////////////////////////////////////
//reset particle positions
///////////////////////////////////////////////////////////////////////////////

void particle::reset(void) {
    //re spawn particles in new positions with new velocities
    pos.x = ofRandom(0, x_lim);
    pos.y = ofRandom(0, y_lim);
    vel.x = static_cast<int>(ofRandom(-5, 5));
    vel.y = static_cast<int>(ofRandom(-5, 5));
    p = pos; //initialise best known position as current position
}

particle::~particle() {
   
}