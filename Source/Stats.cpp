#include "Stats.h"
#include "GameObject.h"
#include "RidgidBodyComponent.h"
#include <chrono>
#include <random>
Stats::Stats(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle* battle,Overworld* overworld) : Component(owner)
{
	float lev;
	float vat;
	float end;
	float att;
	float str;
	float dex;
	float inte;
	float fai;
	float agi;
	float per;
	float luc;
	
	componentElement->QueryFloatAttribute("lev", &lev);
	componentElement->QueryFloatAttribute("vat", &vat);
	componentElement->QueryFloatAttribute("end", &end);
	componentElement->QueryFloatAttribute("att", &att);
	componentElement->QueryFloatAttribute("str", &str);
	componentElement->QueryFloatAttribute("int", &inte);
	componentElement->QueryFloatAttribute("fai", &fai);
	componentElement->QueryFloatAttribute("agi", &agi);
	componentElement->QueryFloatAttribute("per", &per);
	componentElement->QueryFloatAttribute("luc", &luc);
	componentElement->QueryFloatAttribute("dex", &dex);

	level = lev;
	vatality = vat;
	attunment = att;
	endurance = end;
	strength = str;
	intellegance = inte;
	faith = fai;
	agility = agi;
	perception = per;
	this->dex = dex;
	
	caculateStats();
	this->battle = battle;
	this->overworld = overworld;
	
}

Stats::~Stats()
{
	

}

void Stats::start()
{

}

GameObject* Stats::update()
{
	if (health <= 0)
	{
		getOwner()->isDead = true;
	}
	else
	{
		checKVisibility();
	}
	if (health > m_health)
	{
		health = m_health;
	}
	return nullptr;
}

void Stats::finish()
{

}

void Stats::caculateStats()
{
	movementSpaces = endurance / 10;
	m_MovementSpaces = movementSpaces;
	Max_MovementSpaces = movementSpaces;
	health = (vatality * 2);
	m_health = (vatality * 2);
	m_end= (endurance * 2);
	m_mana = (attunment * 2);
	mana = (attunment * 2);
	end = (endurance * 2);
	att = (strength + dex);
	criticalRate = (luck / 4);
	critDamage = (dex / 2);
	evvasion = (agility + (luck / 2));
	accracy = (perception+ dex / 2);
	speed = agility;
}

void Stats::checKVisibility()
{
	visibleObjects.clear();
	float xMax = getOwner()->getComponent<RidgidBody>()->position->x + 512;
	float xMin = getOwner()->getComponent<RidgidBody>()->position->x - 512;
	float yMax = getOwner()->getComponent<RidgidBody>()->position->y + 512;
	float yMin = getOwner()->getComponent<RidgidBody>()->position->y - 512;

	for (int i = 0; i < overworld->getEntitys().size(); i++)
	{
		if (xMax > overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->x && xMin < overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->x && yMax>overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->y && xMin < overworld->getEntitys()[i]->getComponent<RidgidBody>()->position->y)
		{

			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::default_random_engine generator(seed);

			std::uniform_real_distribution<float> distribution(0, 100);
			float num = distribution(generator);
			if (num < overworld->getEntitys()[i]->getComponent<Stats>()->visibility)
			{
				visibleObjects.push_back(overworld->getEntitys()[i]);
			}
		}
	}
}