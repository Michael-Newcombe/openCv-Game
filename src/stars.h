#pragma once

#pragma once

#include "ofMain.h"

class stars {

public:
	stars();

	void draw();
	void update(ofBoxPrimitive player);
	void respawn();
	bool collision(ofBoxPrimitive player);

	ofBoxPrimitive star;
	ofVec3f pos;
	ofColor color;
	int speed;
};

