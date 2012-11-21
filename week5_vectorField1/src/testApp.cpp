#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		particle myParticle2;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,50),0,0);
		particles.push_back(myParticle);
		
	}
	
	VF.setupField(150,150,ofGetWidth(), ofGetHeight());
	
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
		particles[i].addForce(frc.x*2, frc.y*2);
		particles[i].addDampingForce();
		particles[i].update();
		
	}
	
	//VF.fadeField(0.99f);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	//VF.draw();
	
	
	
	for (int i = 0; i < particles.size(); i++){
		ofSetColor(ofRandom(100,150),73,50,100);
		particles[i].draw();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
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
	
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
	
	VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 60, 0.3f);
	
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x; 
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
