#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	//ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 10; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	for (int i = 0; i < (particles.size()-1); i++){
		spring mySpring;
		mySpring.distance		= 10;
		mySpring.springiness	= 0.01f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
	
	bPressed = false;
	
	NF.setup();
	NF.scaleOfField = 0.5;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	NF.setTime(ofGetElapsedTimef()*0.5);
	//NF.scaleOfField = ofMap(mouseX, 0,ofGetWidth(),0,0.01);
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		for (int j = 0; j < i; j++){
			if (bPressed){
				particles[i].addRepulsionForce(particles[j], 30,5.0);
			} else {
				particles[i].addRepulsionForce(particles[j], 30,5.0);	
			}
		}
		
		if (!bPressed){
			particles[i].addAttractionForce(particles[i].pos.x, particles[i].pos.y, 100,ofMap(i, 0, particles.size(), 1.0,2.0, true));
			//particles[i].addAttractionForce(ofGetWidth(), particles[i].pos.y, 2000,0.5);
			
			ofVec2f frcFromNoise = NF.getNoiseForPosition(particles[i].pos.x, particles[i].pos.y,2.0f);
			particles[i].addForce(frcFromNoise.x, frcFromNoise.y);
			
		} else {
			particles[i].addAttractionForce(mouseX, mouseY, 2000,ofMap(i, 0, particles.size(), 1.0,2.0, true));
			
		}
		
		
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
		
		particles[i].particleTrail.push_back(particles[i].pos);
		if (particles[i].particleTrail.size() > 200){
			particles[i].particleTrail.erase(particles[i].particleTrail.begin());	
		}
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	//NF.draw();
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].draw();
		
	}
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	
	ofSetColor(0,0,0);
	ofRect(10,10,230,20);
	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse press or mouse drag", 20, 23);
	
	
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
//	particles.erase(particles.begin());
//	particle myParticle;
//	myParticle.setInitialCondition(x,y,0,0);
//	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	bPressed = true;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	bPressed = false;
}
