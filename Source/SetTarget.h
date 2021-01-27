#ifndef SETTARGET_H
#define SETTARGET_H
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"
#include "InputHandler.h"

class SetTarget :public Component
{
public:
	SetTarget(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~SetTarget();
	void start();
	GameObject* update();
	void finish();
private:
	GameObject target;
	Battle* battle;
};

#endif