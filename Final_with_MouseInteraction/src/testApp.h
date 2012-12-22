#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"

class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
	vector <particle *> myParticles;
	vector <particle *> backgroundParticles;
	vector<string> splitcoordinates;
	vectorField VF;
	
	float prevMouseX;
	float prevMouseY;
	
	ofVideoGrabber 		vidGrabber;
	unsigned char * 	videoInverted;
	ofTexture			videoTexture;
	int 				camWidth;
	int 				camHeight;
	int scale;
	
	ofPixels videoPixels;
	bool learnBackground;
	ofSerial	serial;
	
	bool		bSendSerialMessage;			// a flag for sending serial
	char		bytesRead[3];				// data from serial, we will be trying to read 3
	char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
	int			nBytesRead;					// how much did we read?
	int			nTimesRead;					// how many times did we read?
	float		readTime;		
	
	float repulsionForceStrength;
	
};

#endif
	
