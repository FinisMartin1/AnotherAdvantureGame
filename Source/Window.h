#ifndef WINDOW_H
#define WINDOW_H

#include"Component.h"
#include "tinyxml2.h"
#include "Overworld.h"
class Window :public Component
{
public:
	Window(GameObject* owner, tinyxml2::XMLElement* componentElement,Overworld* overworld);
	~Window();
	void start();
	GameObject* update();
	void finish();
private:
	
	Overworld* overworld;
};
#endif