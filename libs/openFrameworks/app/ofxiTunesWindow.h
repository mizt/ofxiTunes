#pragma once

#include "ofAppBaseWindow.h"

class ofxiTunesWindow : public ofAppBaseWindow {
public:
	
	ofxiTunesWindow();
	virtual ~ofxiTunesWindow(){};
	
	virtual void		setUseFSAA(bool bUseFSAA);
	
	virtual void		setupOpenGL(int w, int h, int screenMode);
	virtual void		initializeWindow();
	virtual void		runAppViaInfiniteLoop(ofBaseApp * appPtr);
	
	virtual void		hideCursor() {};
	virtual void		showCursor() {};
	
	virtual void		setWindowPosition(int x, int y);
	virtual void		setWindowShape(int w, int h);
	
	virtual int			getFrameNum();
	virtual float		getFrameRate();
	
	virtual ofPoint		getWindowPosition();
	virtual ofPoint		getWindowSize();
	virtual ofPoint		getScreenSize();
	
	virtual void		setFrameRate(float targetRate);
	virtual void		setWindowTitle(string title);
	
	virtual int			getWindowMode();
	
	virtual void		setFullscreen(bool fullscreen);
	virtual void		toggleFullscreen();
	
	virtual void		enableSetupScreen();
	virtual void		disableSetupScreen();
	
	virtual void		keyPressed(int key);
	virtual void		mousePressed(float x, float y, int button);
	virtual void		mouseMoved(float x, float y);
	virtual void		mouseDragged(float x, float y, int button);
	virtual void		mouseReleased(int button);
	
	virtual void update();
	virtual void render(int x, int y,int width, int height);
	
	string				windowString;
	bool				bFSAA;
	
	ofPoint				screenSize;
	ofPoint				windowSize;
	ofPoint				windowPos;
	
	int windowW, windowH;
	int windowX, windowY;
	
	bool			bNewScreenSize;
	bool			bNewScreenPosition;
	bool			bNewWindowString;
	
	int				requestedWidth;
	int				requestedHeight;
	
	int				requestedX;
	int				requestedY;
	
	int				windowMode;
	bool			bNewScreenMode;
	float			timeNow, timeThen, fps;
	int				nFramesForFPS;
	int				nFrameCount;
	int				buttonInUse;
	bool			bEnableSetupScreen;
	
	bool			bFrameRateSet;
	int 			millisForFrame;
	int 			prevMillis;
	int 			diffMillis;
	
	float 			frameRate;
	
	int 			nonFullScreenX;
	int 			nonFullScreenY;
	
	
};

typedef ofxiTunesWindow* t_newWin();
typedef void t_delWin(ofxiTunesWindow*);







