#ifndef TARGET_H
#define TARGET_H

#include "Component.h"
#include "ObjectFactory.h"
#include "tinyxml2.h"

class Target:public Component
{
public:
	Target(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~Target();

	void start();
	GameObject* update();
	void finish();
private:
	Battle* battle;
};

#endif