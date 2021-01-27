#include "Effect.h"
#include "GameObject.h"
#include "Stats.h"
#include <random>
#include<chrono>

Effect::Effect(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{
	this->battle = battle;
}

Effect::~Effect()
{

}

void Effect::start()
{

}

GameObject* Effect::update()
{
	if (myTurn == true)
	{
		if (!activeBuffs.empty())
		{
			for (int i = 0; i < activeBuffs.size(); i++)
			{
				if (turnCounter[i] != 0)
				{
					switch (activeBuffs[i])
					{
					case 1:
						getOwner()->getComponent<Stats>()->movementSpaces = 0;
						break;
					case 2:
						getOwner()->getComponent<Stats>()->m_MovementSpaces / 2;
					}
					turnCounter[i]--;
				}
				else
				{
					endBuff(activeBuffs[i]);
				}
			}

		}
	}
	myTurn = false;
	return nullptr;

}

void Effect::finish()
{

}
void Effect::addBuff(int effect,int turns, int chance)
{
	bool activate = true;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(0.0, 100.0);
	int num = distribution(generator);
	if (num < chance)
	{
		for (int i = 0; i < activeBuffs.size(); i++)
		{
			if (activeBuffs[i] == effect)
			{
				activate = false;
			}

		}
		if (activate == true)
		{
			activeBuffs.push_back(effect);
			turnCounter.push_back(turns);
		}
	}
}
void Effect::endBuff(int effect)
{
	switch (effect)
	{
	case 1:
		getOwner()->getComponent<Stats>()->movementSpaces = getOwner()->getComponent<Stats>()->m_MovementSpaces;
		break;
	case 2:
		getOwner()->getComponent<Stats>()->m_MovementSpaces = getOwner()->getComponent<Stats>()->Max_MovementSpaces;
	}
}