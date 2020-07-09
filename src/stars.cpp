
#include "stars.h"

stars::stars() {
	// random size, position, speed and colour
	star.set(3.0);
	//pos = ofVec3f(ofRandom(-ofGetWidth()*.2, ofGetWidth()*.2), -20, ofRandom(-2000, -10000));
	pos = ofVec3f(ofRandom(-ofGetWidth() *.2, ofGetWidth() *.2), ofRandom(-ofGetHeight() *.2, ofGetHeight() *.2), ofRandom(-1000, -10000));
	color = ofColor(255);
	speed = ofRandom(1, 20);

}

void stars::draw() {
	ofSetColor(color);
	star.draw();
}

void stars::update(ofBoxPrimitive player) {
	ofVec3f playerPos = player.getPosition();
	float playerSize = player.getSize().x;

	if (pos.z > 0) respawn();

	pos.z += speed;

	star.setPosition(pos);

}

void stars::respawn() {
	// position asteroid way in the distance
	pos.z = ofRandom(-8000, -10000);
}

bool stars::collision(ofBoxPrimitive player) {
	ofVec3f playerPos = player.getPosition();
	float playerSize = player.getSize().x;

	if (pos.z > playerPos.z && pos.x < playerPos.x + playerSize && pos.x > playerPos.x - playerSize)
		return true;
	return false;
}
