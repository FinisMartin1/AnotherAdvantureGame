#ifndef WAYPOINT_H
#define WAYPOINT_H
#include"Component.h"
#include "tinyxml2.h"
#include"ObjectFactory.h"
#include"Overworld.h"
#include"LevelEditor.h"
#include"View.h"
#include<string>
class Waypoint :public Component
{
public:
	Waypoint(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory,Overworld* overworld,View* view,LevelEditor* editor);
	~Waypoint();
	
	void start();
	GameObject* update();
	void finish();
	void setMap(string map) { this->map = map; }
	void setPlayerPosition(float x, float y) { pX = x; pY = y; }
	void setBondary(float w, float h) { this->w = w; this->h = h; }
	string getMap() { return map; }
	float getX() { return pX; }
	float getY() { return pY; }
	float getBW() { return w; }
	float getBH() { return h; }
private:
	string map;
	bool nextMap = false;
	float pX;
	float pY;
	float w;
	float h;
	ObjectFactory* factory;
	Overworld* overworld;
	View* view;
	LevelEditor* editor;
};
#endif // !WAYPOINT_H
