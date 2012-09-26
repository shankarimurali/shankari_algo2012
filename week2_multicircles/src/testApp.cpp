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
	
	for (int i = 0; i < 450; i++){
	
		float radius = i;
		float something=ofMap(mouseX*mouseY, 0, 1440*900, 1, 100, true);
		float angle = ofGetElapsedTimef() * (10+ i/ 20.0)/something;
		float x = xorig + radius * cos(angle) + ofRandom(-5,5);
		float y = yorig + radius * -sin(angle) + ofRandom(-5,5);
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		float color=ofMap(radius, 0, 200, 0, 255, true);
		ofSetColor(color,ofRandom(0,255),ofRandom(0,255));
		ofRect(x, y, 2, 2);
	
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

