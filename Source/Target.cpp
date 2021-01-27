#include "Target.h"
#include"Battle.h"
#include"RidgidBodyComponent.h"
#include"Clickable.h"
#include"GameObject.h"
Target::Target(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle):Component(owner)
{

}

Target::~Target()
{

}


void Target::start()
{

}

GameObject* Target::update()
{
	float x = getOwner()->getComponent<RidgidBody>()->position->x;
	float y = getOwner()->getComponent<RidgidBody>()->position->y;
	float ex;
	float ey;
	for (int i = 0; i < battle->getEnemys().size(); i++)
	{
		ex = battle->getEnemys()[i]->getComponent<RidgidBody>()->position->x;
		ey = battle->getEnemys()[i]->getComponent<RidgidBody>()->position->y;
		if (ex == x && ey == y && getOwner()->getComponent<Clickable>()->clickCheck())
		{
			battle->setTarget(battle->getEnemys()[i]);
		}
	}
	return nullptr;
}

void Target::finish()
{

}