#ifndef _OF_ITUNES_APP
#define _OF_ITUNES_APP

#include "ofBaseApp.h"
#include "stdio.h"
 
#ifndef ITUNES 
#include "ofSoundStream.h"
#include "fft.h"
#endif

class ofxiTunesApp : public ofBaseApp {
	
	private :
				
		float waveformL[512];
		float waveformR[512];
		
		float spectrumL[256];
		float spectrumR[256];

#ifndef ITUNES
		
		fft		fftL;
		fft		fftR;
		float magnitudeL[512];
		float magnitudeR[512];
		
		float phaseL[512];
		float phaseR[512];

		float powerL[512];
		float powerR[512];
#endif

	public :
	
		ofxiTunesApp() {
		
			// audio setup
			#ifndef ITUNES
				ofSoundStreamSetup(0,2,this,44100,512,4);
			#endif
			
			printf("ofItunesApp\n");
			for(int i=0; i<512; i++) waveformL[i] = waveformR[i] = 0.;
			for(int i=0; i<256; i++) spectrumL[i] = spectrumL[i] = 1.;
		}
		~ofxiTunesApp() {
			printf("~ofItunesApp\n");
		}
		
		// 
		float getWaveformL(int index) {
			if(index<0) index = 0; 
			if(index>=512) index = 511;
			return waveformL[index];
		}
		float getWaveformR(int index) {
			if(index<0) index = 0; 
			if(index>=512) index = 511;
			return waveformR[index];
		}	
		
		
		float getSpectrumL(int index) {
			if(index<0) index = 0;
			if(index>=256) index = 255;
			return spectrumL[index];
		}
		float getSpectrumR(int index) {
			if(index<0) index = 0;
			if(index>=256) index = 255;
			return spectrumR[index];
		}
		
		
#ifndef ITUNES
		void audioReceived(float *input, int bufferSize, int nChannels) {
			
			//
			for (int i = 0; i < bufferSize; i++){
				waveformL[i] = input[i*2];
				waveformR[i] = input[i*2+1];
			}
			
			/* do the FFT	*/
			float avgL = 0.f;	
			float avgR = 0.f;	
			fftL.powerSpectrum(0,256,waveformL,512,&magnitudeL[0],&phaseL[0],&powerL[0],&avgL);
			fftR.powerSpectrum(0,256,waveformR,512,&magnitudeR[0],&phaseR[0],&powerR[0],&avgR);
			for(int	i=0; i<256; i++) {
				spectrumL[i] = 1.0-magnitudeL[i];
				if(spectrumL[i]<0) spectrumL[i] = 0;
				if(spectrumL[i]>1) spectrumL[i] = 1;
				spectrumR[i] = 1.0-magnitudeR[i];
				if(spectrumR[i]<0) spectrumR[i] = 0;
				if(spectrumR[i]>1) spectrumL[i] = 1;
			}
		}
#else
		void setWaveformL(unsigned char *input,int bufferSize) {
			for(int	i=0; i<bufferSize; i++) waveformL[i] = (input[i]/128.0)-1.;
		}
		void setWaveformR(unsigned char *input,int bufferSize) {
			for(int	i=0; i<bufferSize; i++) waveformR[i] = (input[i]/128.0)-1.;
		}
		
		void setSpectrumL(unsigned char *input,int bufferSize) {
			for(int	i=0; i<bufferSize; i++) spectrumL[i] = 1.0-(input[i]/256.0);
		}
		void setSpectrumR(unsigned char *input,int bufferSize) {
			for(int	i=0; i<bufferSize; i++) spectrumR[i] = 1.0-(input[i]/256.0);	
		}
#endif
		
};

typedef ofxiTunesApp* t_newApp();
typedef void t_delApp(ofxiTunesApp*);


#endif