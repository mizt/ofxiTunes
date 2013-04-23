#ifndef _TEST_APP
#define _TEST_APP

#define ITUNES

#include "ofMain.h"
#include "ofxiTunesApp.h"

class testApp : public ofxiTunesApp {
	public:
		void setup();
		void update();
		void draw();
};


// for iTunes
extern "C" ofxiTunesApp* newApp() { return new testApp; }
extern "C" void delApp(ofxiTunesApp* p) { delete p; }

#endif
