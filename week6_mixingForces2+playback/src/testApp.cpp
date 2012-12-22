#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(20);
	ofBackground(255, 255, 255);

	
	for (int i=0; i<67; i++) {
		images[i].loadImage("screenshots/I_Page_"+ofToString(i+1)+".jpg");

	}
	imageWidth=1024;
	imageHeight=640;
	count=0;
	
}

//--------------------------------------------------------------
void testApp::update(){
	

}

//--------------------------------------------------------------
void testApp::draw(){

	images[count].draw(ofGetWidth()/2-imageWidth/2,ofGetHeight()/2-imageHeight/2,imageWidth,imageHeight);
	count=count+vel;
	
	if (count>66) {
		count=66;
		vel=-1;
	}
	else if(count<0)
	{
		count=0;
		vel=1;
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
