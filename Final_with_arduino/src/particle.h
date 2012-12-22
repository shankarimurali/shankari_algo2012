#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"


class particle
{
public:
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
	
	unsigned int bitFlagW;
	unsigned int bitFlagH;
	
	particle();
	virtual ~particle(){};
	
	void resetForce();
	void addForce(float x, float y);
	void addRepulsionForce(float x, float y, float radius, float scale);
	void addAttractionForce(float x, float y, float radius, float scale);
	void addRepulsionForce(particle &p, float radius, float scale);
	void addAttractionForce(particle &p, float radius, float scale);
	void addClockwiseForce(particle &p, float radius, float scale);
	void addCounterClockwiseForce(particle &p, float radius, float scale);
	void addPoint(float x, float y);
	void addDampingForce();
	float addColor(float x, float y, float radius, float scale);
	
	void setInitialCondition(float px, float py, float vx, float vy);
	void update();
	void draw();
	ofColor getColor();
	
	void bounceOffWalls(float width, float height);
	vector<ofPoint> positions;
	
	float damping;
	ofFloatColor color;
	float size;
	
protected:
private:
};

#endif // PARTICLE_H
