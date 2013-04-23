#include "ofxiTunesWindow.h"
#include "ofMain.h"

// for iTunes
extern "C" ofxiTunesWindow* newWin() {
    return new ofxiTunesWindow;
}

extern "C" void delWin(ofxiTunesWindow* p) {
    delete p;
}

ofBaseApp		*OFSAptrForiTunes = NULL;
ofxiTunesWindow *ofWindowPtr;

/******** Constructor ************/

ofxiTunesWindow::ofxiTunesWindow() {
	printf("ofxiTunesWindow::ofxiTunesWindow()\n");
	nFrameCount				= 0;
	bEnableSetupScreen		= true;
	
	windowPos.set(0, 0);
	windowSize.set(0, 0);
	screenSize.set(0, 0);
	
	
	bNewScreenSize		= false;
	bNewScreenPosition	= false;
	bNewWindowString	= true;
	
	nFrameCount				= 0;
	windowMode				= 0;
	bNewScreenMode			= false;
	timeNow, timeThen, fps	= 0.0f;
	nFramesForFPS			= 2;
	nFrameCount				= 0;
	buttonInUse				= 0;
	bEnableSetupScreen		= false;
	
	bFrameRateSet			= false;
	millisForFrame			= 0;
	prevMillis				= 0;
	diffMillis				= 0;
	
	frameRate				= 60.0f;
	
	nonFullScreenX = 0 ;
	nonFullScreenY = 0;
	
	windowString = "openFrameworks";
	
	bFSAA = false;
	
	
}

void ofxiTunesWindow::setUseFSAA(bool useFSAA) {
	bFSAA = useFSAA;
}

/******** Initialization methods ************/

void ofxiTunesWindow::setupOpenGL(int w, int h, int screenMode) {
	printf("ofxiTunesWindow::setupOpenGL()\n");
	
	windowMode		= screenMode;
	if( windowMode != OF_WINDOW )bNewScreenMode	= true;
	
	requestedWidth	= w;
	requestedHeight = h;
	
	windowW = 0;
	windowH = 0;
	
}


void ofxiTunesWindow::initializeWindow() {
	
}


void  ofxiTunesWindow::runAppViaInfiniteLoop(ofBaseApp * appPtr) {
	OFSAptrForiTunes = appPtr;
	OFSAptrForiTunes->setup();
}

void ofxiTunesWindow::update() {}

void ofxiTunesWindow::render(int x, int y,int width, int height){
		
		
		windowW = width;
		windowH = height;
		
		//height = height > 0 ? height : 1;
		if(height<0) height=1;
		glViewport(x,y,width,height);
		float * bgPtr = ofBgColorPtr();
		bool bClearAuto = ofbClearBg();
		if ( bClearAuto == true || nFrameCount < 3){
			glClearColor(bgPtr[0],bgPtr[1],bgPtr[2], bgPtr[3]);
			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		if( bEnableSetupScreen )ofSetupScreen();
        if(height<0) height=1;
        //height = height > 0 ? height : 1;
		glViewport(x,y,width,height);
		ofSetupScreen();
		OFSAptrForiTunes->update();
		OFSAptrForiTunes->draw();
		
		// -------------- fps calculation:
		timeNow = ofGetElapsedTimef();
		if( ( timeNow - timeThen ) > 0 ) {
			fps = 1.0 / (timeNow-timeThen);
			frameRate *= 0.9f;
			frameRate += 0.1f*fps;
		}
		timeThen = timeNow;
		// --------------
		
		nFrameCount++; // increase the overall frame count
		
	}
	
	
	void ofxiTunesWindow::keyPressed(int key){
		if(key == OF_KEY_ESC){
			//OF_EXIT_APP(0);
		}
	}
	
	void ofxiTunesWindow::mousePressed(float x, float y, int button){
		
	}
	
	void ofxiTunesWindow::mouseDragged(float x, float y, int button){
	}
	
	void ofxiTunesWindow::mouseReleased(int button){
	}
	
	
	void ofxiTunesWindow::mouseMoved(float x, float y){
	
	}
	
	
	/******** Set Window properties ************/
	
	void ofxiTunesWindow::setWindowPosition(int x, int y) {
		requestedX = x;
		requestedY = y;
		bNewScreenPosition = true;
	}
	
	void ofxiTunesWindow::setWindowShape(int w, int h) {
		requestedWidth  = w;
		requestedHeight = h;
		bNewScreenSize = true;
	}
	
	
	
	/******** Get Window/Screen properties ************/
	
	// return cached pos, read if nessecary
	ofPoint	ofxiTunesWindow::getWindowPosition() {
		return ofPoint(windowX, windowY);
	}
	
	
	ofPoint	ofxiTunesWindow::getWindowSize() {
		return ofPoint(windowW, windowH,0);
	}
	
	ofPoint	ofxiTunesWindow::getScreenSize() {
		return screenSize;
	}
	
	int	ofxiTunesWindow::getWindowMode() {
		return windowMode;
	}
	
	float ofxiTunesWindow::getFrameRate() {
		return frameRate;
	}
	
	/******** Other stuff ************/
	void ofxiTunesWindow::setFrameRate(float targetRate) {
		
	}
	
	int	ofxiTunesWindow::getFrameNum() {
		return nFrameCount;
	}
	
	void ofxiTunesWindow::setWindowTitle(string title) {
		windowString = title;
		bNewWindowString = true;
	}
	
	
	void ofxiTunesWindow::setFullscreen(bool fullscreen) {
		
		if(fullscreen) windowMode		= OF_FULLSCREEN;
		else windowMode					= OF_WINDOW;
		
		bNewScreenMode					= true;
	}
	
	void ofxiTunesWindow::toggleFullscreen() {
		if(windowMode == OF_FULLSCREEN) setFullscreen(false);
		else setFullscreen(true);
	}
	
	
	void ofxiTunesWindow::enableSetupScreen(){
		bEnableSetupScreen = true;
	};
	
	void ofxiTunesWindow::disableSetupScreen(){
		bEnableSetupScreen = false;
	};
	
	
