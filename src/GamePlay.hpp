
#pragma once

#include "ofMain.h"
#include "Asteroid.hpp"
#include "stars.h"

#include <vector>

class GamePlay {
    
    public:
        GamePlay();
    
        void run();
        void playing();
        void gameOver();
        void addAsteroids(int num);
		void addStars(int num);

        void borders();
        void move(float x, float y);
    
        ofBoxPrimitive player;
        ofCamera camera;
        vector<Asteroid> asteroids;
		vector<stars> mystars;

    
        int score, finalScore, state;
};
