#ifndef CREATEOBJECT_H
#define CREATEOBJECT_H
#include "Component.h"
#include "ObjectFactory.h"
#include "tinyxml2.h"
#include "LevelEditor.h"
class CreateObject :public Component
{
public:
	CreateObject(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory ,LevelEditor* editor);
	~CreateObject();

	void start();
	GameObject* update();
	void finish();


private:
	LevelEditor* editor;
	ObjectFactory* factory;
	int timer = 10;
};
#endif