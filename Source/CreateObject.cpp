#include "CreateObject.h"
#include "Clickable.h"
#include "GameObject.h"
#include"RidgidBodyComponent.h"
#include"Waypiont.h"
#include<iostream>
CreateObject::CreateObject(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory, LevelEditor* editor) :Component(owner)
{
	this->factory = factory;
	this->editor = editor;

}

CreateObject::~CreateObject()
{

}

void CreateObject::start()
{

}

GameObject* CreateObject::update()
{

	if (getOwner()->getComponent<Clickable>()->clickCheck() && timer<=0)
	{
		timer = 10;
		factory->createObject(editor->getBurshType(), getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
		if (editor->getBurshType() == "49")
		{
			string map;
			float x;
			float y;
			cout << "Which Map?" << endl;
			cin >> map;
			cout << "Players X:Y location" << endl;
			cin >> x;
			cin >> y;
			factory->getQue().back()->getComponent<Waypoint>()->setMap(map + ".txt");
			factory->getQue().back()->getComponent<Waypoint>()->setPlayerPosition(x,y);
		}
	}
	timer--;
	return nullptr;
}

void CreateObject::finish()
{

}