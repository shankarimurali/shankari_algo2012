#include "testApp.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x; 
}  

//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(41,17,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 600; i++){
		
		particle * p = new particle();
        particles.push_back(p);
        particles[i]->pos.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
        particles[i]->vel.set(0,0);
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	// sort all the particle
	sort( particles.begin(), particles.end(), comparisonFunction );               // sort them!
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i]->resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i]->addAttractionForce(mouseX, mouseY, 1000, 0.07f);
		
		for (int j = 0; j < i; j++){
			particles[i]->addRepulsionForce(*particles[j], 200, 0.0001);
			particles[i]->addCounterClockwiseForce(*particles[j], 80, 0.09);
		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i]->addDampingForce();
		particles[i]->update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofBackground(0,0,0,255);
	
	for (int i = 0; i < particles.size(); i++){
		//ofSetColor(235,102,19,ofMap(i, 0, particles.size(), 20, 200, true));
		ofSetColor(242,93,7,ofMap(i, 0, particles.size(), 20, 255, true));
		particles[i]->draw();
	}
	
	for (int i=0; i<30; i++) {
		ofSetColor(242, 145, 27,ofMap(i, 0, 40, 8, 0, true));
		ofSetCircleResolution(500);
		ofCircle(ofGetMouseX(), ofGetMouseY(), i*4);
	}
	
	

	
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i]->setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
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
	particles.erase(particles.begin());
	particle * p= new particle();
	
	p->setInitialCondition(x,y,0,0);
	particles.push_back(p);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
