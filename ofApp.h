#pragma once

#include "ofMain.h"
#include "GamePlay.hpp"
#include "ofxCv.h"

using namespace ofxCv;

class ofApp : public ofBaseApp{
    
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
		void avatarMov();
		ofVec2f smoothAvgFlow;
		ofVec2f onePole(ofVec2f current, ofVec2f prev);
        ofVideoGrabber cam;
        FlowFarneback fb;
		
        GamePlay game;
};
