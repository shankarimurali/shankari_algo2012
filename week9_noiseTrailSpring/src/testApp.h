#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "noiseField.h"
#include "spring.h"

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
	
	// let's make a vector of them
	vector <particle> particles;
	vector <spring> springs;
	vector < ofPoint > trail;
	
	noiseField NF;
	
	bool bPressed;
	
	ofImage image;
	ofPixels imagePixels;
	float imageWidth;
	float imageHeight;
	int scale;
	
	
	
	
	
	
};

#endif
