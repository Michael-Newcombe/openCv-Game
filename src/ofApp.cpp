#include "ofApp.h"
using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(10);
    ofEnableDepthTest();
    cam.setup(320, 240);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
	avatarMov();


	ofVec2f avgFlow = fb.getAverageFlow();
	smoothAvgFlow = onePole(smoothAvgFlow, avgFlow);

    // send camera to optical flow algorithm
    if(cam.isFrameNew())
        fb.calcOpticalFlow(cam);


}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(0, 255, 0);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(0, 0, smoothAvgFlow.x * 100, smoothAvgFlow.y * 100);
	ofPopMatrix();

    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofPushMatrix();
      
        ofTranslate(ofGetWidth()-cam.getWidth(), 0);
		fb.draw(0,0);
		cam.draw(0, 0);

    ofPopMatrix();
	
    game.run();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //if(key == OF_KEY_LEFT)  game.move(-2);
    //if(key == OF_KEY_RIGHT) game.move(2);
}

ofVec2f ofApp::onePole(ofVec2f current, ofVec2f prev) 
{
	ofVec2f output = prev + 0.9 * (current - prev);
	return output;
}
void ofApp::avatarMov() {
	
	if (smoothAvgFlow.x < -2.0 && smoothAvgFlow.x > 2.0) {

		game.move(0,0);
	}
    
	else if (smoothAvgFlow.x < 0.0 && smoothAvgFlow.x > -2.0) {

		game.move(2,0);
	}

	else if (smoothAvgFlow.x > 0.0 && smoothAvgFlow.x < 2.0) {

		game.move(-2,0);
	}

	if (smoothAvgFlow.y < -1.0 && smoothAvgFlow.y > 1.0) {

		game.move(0,0);
	}

	else if (smoothAvgFlow.y < 0.0 && smoothAvgFlow.y > -1.0) {

		game.move(0,0.5);
	}

	else if (smoothAvgFlow.y > 0.0 && smoothAvgFlow.y < 1.0) {

		game.move(0,-0.5);
	}

	

}
