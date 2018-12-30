#include "GamePlay.hpp"

/*
 a very crude 3D asteroids game - sorry if it runs slowly, there are no pointers
 */

GamePlay::GamePlay() {
    state = 0;
    
    player.set(5);
    player.setPosition(0, 0, -50);
        
    camera.setPosition(0, 0, 0);
    
    addAsteroids(50);
	addStars(200);
}

void GamePlay::run() {
    if(state == 0) playing();
    if(state == 1) gameOver();
}

void GamePlay::playing() {
    // increment score
    score = ofGetFrameNum();
    // add 10 more asteroids whenever score is multiple of 100
    if (score % 100 == 0) addAsteroids(10);
    // don't let asteroids size grow over 250
    if (asteroids.size() >= 250) asteroids.pop_back();
	if (mystars.size() >= 500) mystars.pop_back();

    
    // display score
    ofSetColor(160, 210, 214);
    ofDrawBitmapString("score: " + to_string(score), 20, 20);
    
    // camera perspective
    camera.begin();
        ofSetColor(255, ofRandom(200, 240));
        player.drawWireframe();
    
		for (int i = 0; i < mystars.size(); i++) {
			mystars[i].draw();
			mystars[i].update(player);
			
		}
		
		for(int i = 0; i < asteroids.size(); i++) {
            asteroids[i].draw();
            asteroids[i].update(player);
            // game over
            if(asteroids[i].collision(player)) state = 1;
        }
    camera.end();
    
    borders();
}

void GamePlay::gameOver() {
    finalScore = score;
    ofSetColor(160, 210, 214);
    ofDrawBitmapString("game over\nscore: " + to_string(finalScore), ofGetWidth()*.5, ofGetHeight()*.5);
}

void GamePlay::addAsteroids(int num) {
    for(int i = 0; i < num; i++) {
        Asteroid a;
        asteroids.push_back(a);
    }
}

void GamePlay::addStars(int num) {
	for (int i = 0; i < num; i++) {
		stars s;
		mystars.push_back(s);
	}
}

void GamePlay::move(float x, float y) {
    player.truck(x);
	player.boom(y);
}

void GamePlay::borders() {
    if(player.getX() >= 34) player.setPosition(34, 0, -50);
    if(player.getX() <= -34)player.setPosition(-34,0, -50);
	if (player.getY() >= 34) player.setPosition(34, 0, -50);
	if (player.getY() <= -34) player.setPosition(-34, 0, -50);
}

