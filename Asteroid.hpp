
#pragma once

#include "ofMain.h"

class Asteroid {
    
    public:
        Asteroid();
        
        void draw();
        void update(ofBoxPrimitive player);
        void respawn();
        bool collision(ofBoxPrimitive player);
        
        ofBoxPrimitive a;
        ofVec3f pos;
        ofColor color;
        int speed, wiggleAmount;
        float wiggleSpeed;
};
