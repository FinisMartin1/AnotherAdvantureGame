#ifndef NIGHT_H
#define NIGHT_H
#include"Component.h"
#include "tinyxml2.h"
#include "Overworld.h"
class Night :public Component
{
public:
	Night(GameObject* owner, tinyxml2::XMLElement* componentElement,Overworld* overworld);
	~Night();

	void start();
	GameObject* update();
	void finish();
private:
	Overworld* overworld;
	int time = 900;
	int timer = 0;
	int maxTime = 1800;
	int maxAlpha = 200;
	int alpha = 0;
};
#endif // !NIGHT_H
