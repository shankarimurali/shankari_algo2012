#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(0,0,0);
		
	// set the position of the rectangle:
	

	
	for (int i=0; i<1000; i++) {
		rectangle myRectangle;
		myRectangle.pos.x = 0;
		myRectangle.pos.y = 0;
		myRectangle.max=i/40;
		myRectangle.catchUpSpeed=ofMap(i, 0, 999, 0.009, 0.05, true);
		rectangles.push_back(myRectangle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i=0; i<rectangles.size(); i++) {

		rectangles[i].xenoToPoint(mouseX, mouseY);
	}
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i=0; i<rectangles.size(); i++) {
		ofSetColor(ofMap(i, 0, rectangles.size(), 0, 255, true),ofMap(i, 0, rectangles.size(), 0, 255, true),ofMap(i, 0, rectangles.size(), 0, 255, true),ofMap(i, 0, rectangles.size(), 0, 255, true));
		rectangles[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){
}
