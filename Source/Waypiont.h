#ifndef WAYPOINT_H
#define WAYPOINT_H
#include"Component.h"
#include "tinyxml2.h"
#include"ObjectFactory.h"
#include"Overworld.h"
#include"View.h"
#include<string>
class Waypoint :public Component
{
public:
	Waypoint(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory,Overworld* overworld,View* view);
	~Waypoint();
	
	void start();
	GameObject* update();
	void finish();
	void setMap(string map) { this->map = map; }
	void setPlayerPosition(float x, float y) { pX = x; pY = y; }
	string getMap() { return map; }
	float getX() { return pX; }
	float getY() { return pY; }
private:
	string map;
	bool nextMap = false;
	float pX;
	float pY;
	ObjectFactory* factory;
	Overworld* overworld;
	View* view;
};
#endif // !WAYPOINT_H
