#include"Waypiont.h"
#include"GameObject.h"
#include"RidgidBodyComponent.h"
#include<fstream>

Waypoint::Waypoint(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory,Overworld* overworld) :Component(owner)
{
	this->factory = factory;
	this->overworld = overworld;
}

Waypoint::~Waypoint()
{

}

void Waypoint::start()
{

}


GameObject* Waypoint::update()
{

	return nullptr;
}

void Waypoint::finish()
{

}