#include"SetTarget.h"
#include"RidgidBodyComponent.h"
#include"GameObject.h"
#include"Clickable.h"

SetTarget::SetTarget(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{
	this->battle = battle;
}

SetTarget::~SetTarget()
{

}

void SetTarget::start()
{

}

GameObject* SetTarget::update()
{
	float sx = getOwner()->getComponent<RidgidBody>()->position->x;
	float sy = getOwner()->getComponent<RidgidBody>()->position->y;
	if (getOwner()->getComponent<Clickable>()->clickCheck())
	{
		for (int i = 0; i < battle->getEnemys().size(); i++)
		{
			float ex = battle->getEnemys()[i]->getComponent<RidgidBody>()->position->x;
			float ey = battle->getEnemys()[i]->getComponent<RidgidBody>()->position->y;
			if (sx == ex && sy == ey)
			{
				battle->setTarget(battle->getEnemys()[i]);
			}
		}
	}
		return nullptr;
}

void SetTarget::finish()
{

}