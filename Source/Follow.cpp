#include"Follow.h"
#include"RidgidBodyComponent.h"
Follow::Follow(GameObject* owner, tinyxml2::XMLElement* componentElement, Overworld* overworld) :Component(owner)
{
	this->overworld = overworld;
}

Follow::~Follow()
{

}

void Follow::start()
{

}

GameObject* Follow::update()
{
	for (int i = 0; i < overworld->getEntitys().size() - 1; i++)
	{
		if (id == overworld->getEntitys()[i]->primaryId)
		{
			getOwner()->getComponent<RidgidBody>()->position->x = overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->x;
			getOwner()->getComponent<RidgidBody>()->position->y = overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->y;
		}
	}
	return nullptr;
}

void Follow::finish()
{

}