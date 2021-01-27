#ifndef FOLLOW_H
#define FOLLOW_H
#include"Component.h"
#include"Overworld.h"
#include "tinyxml2.h"
class Follow :public Component
{
public:
	Follow(GameObject* owner, tinyxml2::XMLElement* componentElement, Overworld* overworld);
	~Follow();
	void start();
	GameObject* update();
	void finish();
	void setId(string id) { this->id = id; };
private:
	string id;
	Overworld* overworld;
};

#endif