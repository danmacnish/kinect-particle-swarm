//
//  particle.cpp
//  kinect particle swarm
//
//  Created by Daniel Macnish on 2/02/2017.
//
//

#include <stdio.h>
#include "ofApp.h"
#include "particle.h"

particle::particle(int x, int y) : x_lim(x), y_lim(y) {
    pos_x = ofRandom(0, x_lim);
    pos_y = ofRandom(0, y_lim);
    vel_x = static_cast<int>(ofRandom(0, x_lim/10));
    vel_y = static_cast<int>(ofRandom(0, y_lim/10));
    p_x = pos_x;
    p_y = pos_y;
    v_scalar = 1;
    p_scalar = 1;
}

void particle::update(ofImage *image) {
    float r = ofRandom(0,1);
    //update velocity
    vel_x += r*v_scalar*(p_x - pos_x);
    vel_y += r*v_scalar*(p_y - pos_y);
    //update position
    pos_x += vel_x;
    pos_y += vel_y;
    //if new position is better than old position, update p
    
}