#include "Library.h"
#include "GameObject.h"
#include "RidgidBodyComponent.h"

Library::Library()
{

}

Library::~Library()
{

}
void Library::addToLibary( GameObject* object)
{
	inventory.push_back(object);
}
GameObject* Library::createObject(int type, float x, float y)
{

	GameObject* newObject = inventory[type];
	RidgidBody* body = newObject->getComponent<RidgidBody>();

	body->position->x = x;
	body->position->y = y;

	return newObject;
}