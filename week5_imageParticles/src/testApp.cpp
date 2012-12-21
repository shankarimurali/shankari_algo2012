#include "testApp.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x; 
}	
//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(255, 255, 255);
	scale=5;
	image.loadImage("image.jpg");
	image.setImageType(OF_IMAGE_COLOR);
	image.resize(ofGetWidth(), ofGetHeight());
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
			p->pos.set(x*scale,y*scale);
			p->size=scale;
			ofColor pixelColor = imagePixels.getColor(x*scale, y*scale);
			p->color.set(pixelColor);
			
			
		}
		
		learnImage=false;
	}
	
	// sort all the particles:
	
	sort( myParticles.begin(), myParticles.end(), comparisonFunction );		
	
	

	
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->resetForce();
		myParticles[i]->addAttractionForce( ofGetWidth()/2,ofGetHeight()/2,1440,0.2);
		myParticles[i]->addDampingForce();
		myParticles[i]->update();
		
		
	}
	
	
	//VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){

	
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->draw();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		learnImage=true;
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
