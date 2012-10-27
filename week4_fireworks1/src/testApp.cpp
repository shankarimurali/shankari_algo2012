#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(0, 0, 0);
	
	for (int i = 0; i < 10000; i++){
		particle myParticle;
		myParticle.setInitialCondition(0,0,sin(i), sin(i));
		// more interesting with diversity :)
		//myParticle.damping = ofRandom(0.001, 0.05);
		particles.push_back(myParticle);
	}
	
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
		particles[i].addForce(0.0, 0.001*sin(i));
		particles[i].addDampingForce();
		//particles[i].bounceOffWalls();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){

	if (ofGetFrameNum()%500==0) {
		
		for (int i = 0; i < particles.size(); i++){
			particles[i].setInitialCondition(ofRandom(0,ofGetWidth()/3)*sin(i/100),ofRandom(ofGetHeight()/3)*sin(i/100),ofRandom(-10,0),ofRandom(-10,0));
			
		}	
	}
		
	ofEnableAlphaBlending();
	
	for (int i = 0; i < particles.size(); i++){	
	
		particles[i].draw();
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
//
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].setInitialCondition(mouseX*sin(i/100),mouseY*sin(i/100),ofRandom(-10,0),ofRandom(-10,0));
//		
//	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
