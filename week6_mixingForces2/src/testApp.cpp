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
	//ofSetBackgroundAuto(false);
	scale=4;
	image.loadImage("1.jpg");
	image.setImageType(OF_IMAGE_COLOR);
	imageWidth=image.width;
	imageHeight=image.height;
	

	
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());

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
				
				p->pos.set(ofGetWidth()/2-imageWidth/2+ x*scale, ofGetHeight()/2-imageHeight/2+ y*scale);
				p->size=scale;
				ofColor pixelColor = imagePixels.getColor(x*scale, y*scale);
				p->color.set(pixelColor);
				
				myParticles.push_back(p);
			}
		
		learnImage=false;
	}
	
	// sort all the particles:
	
	sort( myParticles.begin(), myParticles.end(), comparisonFunction );		
	
	
	
	
	for (int i = 0; i < myParticles.size(); i++){
		
		
		myParticles[i]->addAttractionForce(mouseX,mouseY,20,1.0f);
		myParticles[i]->addRepulsionForce(mouseX,mouseY,ofMap(mouseY, 0, ofGetHeight(), 1, 200, true),1.0f);
		
		myParticles[i]->addDampingForce();
		myParticles[i]->update();
		
	}
	
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
		VF.clear();
	} 
	
	if (key=='a') {
		learnImage=true;
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	//VF.addOutwardCircle(mouseX, mouseY, 200, 0.005f);
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
