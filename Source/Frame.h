#ifndef FRAME_H
#define FRAME_H

#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"

class Frame :public Component
{
public:
	Frame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~Frame();

	void start();
	GameObject* update();
	void finish();

	void setFrarmNum(int num)
	{
		frameNum = num;
	}

private:

	Battle* battle;
	int frameNum;
};

#endif