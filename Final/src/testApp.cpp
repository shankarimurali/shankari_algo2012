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
    serial.listDevices();    
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();    
	
	
    // Tells the computer which port to be listening to    
    serial.setup("/dev/tty.usbmodemfa131",9600);    
	repulsionForceStrength=0.035;
	
	
}

// trim trailing spaces
string ofxTrimStringRight(string str) {
    size_t endpos = str.find_last_not_of(" \t\r\n");
    return (string::npos != endpos) ? str.substr( 0, endpos+1) : str;
}

// trim trailing spaces
string ofxTrimStringLeft(string str) {
    size_t startpos = str.find_first_not_of(" \t\r\n");
    return (string::npos != startpos) ? str.substr(startpos) : str;
}

string ofxTrimString(string str) {
    return ofxTrimStringLeft(ofxTrimStringRight(str));;
}

//
string ofxGetSerialString(ofSerial &serial, char until) {
    static string str;
    stringstream ss;
    char ch;
	
    while ((ch=serial.readByte())>0 && ch!=until) {
        ss << ch;
    }
    str+=ss.str();
    if (ch==until) {
        string tmp=str;
        str="";
        return ofxTrimString(tmp);
    } else {
        return "";
    }
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
	
	string str;
	do {
		str = ofxGetSerialString(serial,'\n'); //read until end of line
		if (str=="") continue;
		
		string coordinates = str;  
		splitcoordinates = ofSplitString(coordinates, ",");  
		
		
		
		
	} while (str!="");
	
	if (splitcoordinates.size()>1) {
		int x=ofMap(ofToInt(splitcoordinates[0]), 1000, -1000, ofGetWidth()/2-camWidth/2, ofGetWidth()/2+camWidth/2, true);
		int y=ofMap(ofToInt(splitcoordinates[1]), 1000, -1000, ofGetHeight()/2-camHeight/2, ofGetHeight()/2+camHeight/2, true);
		
		for (int i = 0; i < myParticles.size(); i++){
			
			ofColor particleColor=myParticles[i]->getColor();
			
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
