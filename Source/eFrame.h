#ifndef EFRAME_H
#define EFRAME_H
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"
class eFrame:public Component
{
public:
	eFrame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~eFrame();

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
#endif // !EFRAME_H
