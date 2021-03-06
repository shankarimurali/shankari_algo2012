#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	ofEnableAlphaBlending();
	
	for (int i = 0; i < mouseX+mouseY+50; i++){
	
		float radius = ofMap(i, 0, mouseX+mouseY+50, 0, 450, true);
		float something=ofMap(mouseY+mouseX, 0, 1440+900, 100, 10, true);
		float angle =  ofGetElapsedTimef() * (10+ i/ (10.0*something));
		float x = xorig + radius * cos(angle) + ofRandom(-3,3);
		float y = yorig + radius * -sin(angle) + ofRandom(-3,3);
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		float color=ofMap(radius, 0, 200, 0, 255, true);
		ofSetColor(color,ofRandom(0,255),ofRandom(0,255));
		ofRect(x, y, 1.5, 1.5);
	
	}	
		
	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

