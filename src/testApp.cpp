#include "testApp.h"
#include "stdio.h"
//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

	int stageWidth  = ofGetWidth();
	int stageHeight = ofGetHeight();
	
	float step = stageWidth/(256.0-1.0);
	float h = stageHeight-1;
	
    ofSetColor(0xFF,0xFF,0xFF);
	for(int i=0; i<(256-1); i++) {
		float v1 = getSpectrumL(i);
		float v2 = getSpectrumL(i+1);
		ofLine(step*i,(v1)*h,step*(i+1),(v2)*h);
	}
	ofSetColor(0,0xFF,0xFF);
	ofDrawBitmapString("libofxiTuens.dlylib",10,10+8);
}