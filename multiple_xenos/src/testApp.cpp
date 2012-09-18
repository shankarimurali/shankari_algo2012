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
	
	//myRectangle.pos.x = 100;
	//myRectangle.pos.y = 50;
	
	for (int i=0; i<160; i++) {
		myRectangle[i].pos.x=0;
		myRectangle[i].pos.y=0;
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	for (int i=0; i<160; i++) {
		
		if(i<20)
		{
		myRectangle[i].xenoToPoint(mouseX+mouseX*i, mouseY);
		}
		
		else if (i>=20 && i<40) {
		myRectangle[i].xenoToPoint(mouseX, mouseY+mouseY*(i-20));
		}
		
		else if (i>=40 && i<60) {
			myRectangle[i].xenoToPoint(ofGetWidth()-(mouseX+mouseX*(i-40)), mouseY);
		}
		
		else if (i>=60 && i<80) {
			myRectangle[i].xenoToPoint(ofGetWidth()-mouseX, mouseY+mouseY*(i-60));
		}
		
		else if (i>=80 && i<100) {
			myRectangle[i].xenoToPoint((mouseX+mouseX*(i-80)),ofGetHeight()- mouseY);
		}
		
		else if (i>=100 && i<120) {
			myRectangle[i].xenoToPoint(mouseX,ofGetHeight()-(mouseY+mouseY*(i-100)));
		}
		
		else if (i>=120 && i<140) {
				myRectangle[i].xenoToPoint(ofGetWidth()-(mouseX+mouseX*(i-120)),ofGetHeight()- mouseY);
		}
		
		else if (i>=140 && i<160) {
			myRectangle[i].xenoToPoint(ofGetWidth()-mouseX,ofGetHeight()-(mouseY+mouseY*(i-140)));
		}
	}
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	//myRectangle.draw();
	
	for (int i=0; i<160; i++) {
		myRectangle[i].draw();
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
