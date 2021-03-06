#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(255, 255, 255, 255);
	
	ofSetBackgroundAuto(false);
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	//VF.draw();
	
	ofSetColor(0,0,0,127);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

	VF.addClockwiseCircle(ofGetWidth()/2,ofGetHeight()/2, 700, 0.1f);	
	VF.addInwardCircle(ofGetWidth()/2,ofGetHeight()/2, 700, 0.1f);	

	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (button == 0) {
		switch (drawingStyle){
			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
				break;
			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
		}		
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
