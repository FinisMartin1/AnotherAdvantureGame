#ifndef DELETESELF_H
#define DELETESELF_H
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"
#include "Overworld.h"
class DeleteSelf:public Component
{
public:
	DeleteSelf(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle* battle, Overworld* overworld);
	~DeleteSelf();

	void start();
	GameObject* update();
	void finish();
private:
	Battle* battle;
	Overworld* overworld;
	int deleteType;
	int delay = 3;
	int timer = 1;
	
};
#endif // !DELETESELF_H

