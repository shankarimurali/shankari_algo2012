#include "testApp.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x; 
}	
//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofBackground(255, 255, 255);
	camWidth 		= 1024;	// try to grab at this size. 
	camHeight 		= 768;	
	scale=5;
	
	vidGrabber.listDevices();
	vidGrabber.setDeviceID(0);
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);
	
	learnBackground=true;  
	repulsionForceStrength=0.035;
	
	
}




//--------------------------------------------------------------
void testApp::update(){
	
	if (learnBackground){
		
		vidGrabber.grabFrame();
		if(vidGrabber.isFrameNew()){
			videoTexture.loadData(vidGrabber.getPixels(), camWidth,camHeight, GL_RGB);
			videoPixels.setFromPixels(vidGrabber.getPixels(), vidGrabber.getWidth(), vidGrabber.getHeight(), 3);
			myParticles.clear();
			for (int x = 0; x < camWidth/scale; x++)
				for(int y = 0; y < camHeight/scale; y++){
					particle * p = new particle();
					p->pos.set(ofGetWidth()/2-camWidth/2+x*scale,ofGetHeight()/2-camHeight/2+y*scale);
					p->size=scale;
					ofColor pixelColor = videoPixels.getColor(x*scale, y*scale);
					p->color.set(pixelColor);	
					myParticles.push_back(p);
				}
			
			
			
		}
		learnBackground=false;
	}
	
	
	// sort all the particles:
	
	sort( myParticles.begin(), myParticles.end(), comparisonFunction );		
		

		for (int i = 0; i < myParticles.size(); i++){
			
			ofColor particleColor=myParticles[i]->getColor();
			int x=mouseX;
			int y=mouseY;
			float addHue=myParticles[i]->addColor(x,y,50,10);
			float addSaturation=myParticles[i]->addColor(x,y,50,10);
			float addBrightness=myParticles[i]->addColor(x,y,80,10);
			float addAlpha=myParticles[i]->addColor(x,y,120,20);
			
			float hue=particleColor.getHue();
			float saturation=particleColor.getSaturation();
			float brightness=particleColor.getBrightness();
			
			
			particleColor.setHsb(ofClamp(hue+addHue, 0, 255),ofClamp( saturation+addSaturation, 0, 255),ofClamp( brightness+addBrightness, 0, 255),ofClamp(255-addAlpha, 0, 255));
			myParticles[i]->color.set(particleColor);
			
			myParticles[i]->resetForce();
			myParticles[i]->addAttractionForce( x,y,70,0.035);
			myParticles[i]->addRepulsionForce(x,y,120,repulsionForceStrength);
			myParticles[i]->bounceOffWalls(ofGetWidth(),ofGetHeight());
			myParticles[i]->addDampingForce();
			myParticles[i]->update();
			
		}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 0, 0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofRect(ofGetWidth()/2, ofGetHeight()/2, camWidth-10, camHeight-10);
	
	for (int i = 0; i < myParticles.size(); i++){
		myParticles[i]->draw();
	}
	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		learnBackground=true;
	} 
	
	if(key=='+')
	{
		repulsionForceStrength=0.4;
	}
	if(key=='-')
	{
		repulsionForceStrength=0.035;
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
	prevMouseX = x; 
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
