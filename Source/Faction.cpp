#include "Faction.h"
#include"Stats.h"
#include"GameObject.h"
Faction::Faction(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle* battle):Component(owner)
{
	float fac;
	componentElement->QueryFloatAttribute("fac", &fac);
	faction = fac;

	switch (faction)
	{
	case 0:
		alliesFactions.push_back(0);
		enemyFaction.push_back(1);
		break;
	case 1:
		alliesFactions.push_back(1);
		enemyFaction.push_back(0);
		break;
	default:
		break;
	}
	this->battle = battle;
}

Faction::~Faction()
{

}

void Faction::start()
{

}

GameObject* Faction::update()
{
	for (int i = 0; i < getOwner()->getComponent<Stats>()->visibleObjects.size(); i++)
	{
		for (int i = 0; i < enemyFaction.size(); i++)
		{
			if (getOwner()->getComponent<Stats>()->visibleObjects[i]->getComponent<Faction>()->faction == enemyFaction[i])
			{
	//			battle->isBattle = true;
			}
		}
	}
	return nullptr;
}

void Faction::finish()
{

}