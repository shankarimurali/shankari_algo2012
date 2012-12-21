#include "testApp.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x; 
}	
//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	scale=5;
	image.loadImage("1.jpg");
	image.setImageType(OF_IMAGE_COLOR);
	imageWidth=image.width;
	imageHeight=image.height;
	
	learnImage=true;

	
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	if (learnImage) {
		
		unsigned char* pixels=image.getPixels();
		imagePixels.setFromPixels(image.getPixels(), image.width, image.height, 3);
		
		myParticles.clear();
		for (int x = 0; x < imageWidth/scale; x++)
			for(int y = 0; y < imageHeight/scale; y++){
				particle * p = new particle();
				myParticles.push_back(p);
				p->pos.set( x*scale,y*scale);
				p->size=scale;
				ofColor pixelColor = imagePixels.getColor(x*scale, y*scale);
				p->color.set(pixelColor);
				
				
			}
		
		learnImage=false;
	}

	
	for (int i = 0; i < myParticles.size(); i++){
		

		if (i%17==0) {
			
			myParticles[i]->pos.x=myParticles[i]->pos.x-sin(ofGetElapsedTimef()/1.5);
			
		}
		if (i%9==0) {
			
			myParticles[i]->pos.y=myParticles[i]->pos.y-sin(ofGetElapsedTimef()/1.5);
			
		}
		if (i%11==0) {
			
			myParticles[i]->pos.x=myParticles[i]->pos.x+sin(ofGetElapsedTimef()/1.5);
			
		}
		if (i%13==0) {
			
			myParticles[i]->pos.y=myParticles[i]->pos.y+sin(ofGetElapsedTimef()/1.5);
			
		}
		
		
		myParticles[i]->update();
		
		
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix();
	ofTranslate(ofGetWidth()/2-imageWidth/2, ofGetHeight()/2-imageHeight/2, 0);
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->draw();
	}
	ofPopMatrix();
	
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
