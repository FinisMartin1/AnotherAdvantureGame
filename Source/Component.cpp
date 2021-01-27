#include "GameObject.h"
#include "Component.h"
#include "ObjectDefinitions.h"

Component::Component(GameObject* owner) : _owner( owner ) { }

Component::~Component() {}

void Component::ownerDestroyed()
{
	finish();
	_owner = nullptr;
}


GameObject* Component::getOwner()
{
	return(_owner);
}