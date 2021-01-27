#include "Ability.h"
#include "RidgidBodyComponent.h"
#include "Clickable.h"
#include "MoveSpace.h"
#include <chrono>
#include <random>
#include "EnemyAi.h"
#include "Stats.h"
Ability::Ability(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle,InputHandler* input,ObjectFactory* factory) :Component(owner)
{
	this->battle = battle;
	this->input = input;
	this->factory = factory;

	float abil;
	float buff;

	componentElement->QueryFloatAttribute("abil", &abil);
	componentElement->QueryFloatAttribute("buff", &buff);
	skills.push_back(abil);
}

Ability::~Ability()
{

}

void Ability::start()
{

}

GameObject* Ability::update()
{
	RidgidBody* eBody;

		switch (currentAbility)
		{
		case 1:
			break;

		case 2:
			//ranged attack one space
			for (int i = 0; i < battle->getEnemys().size(); i++)
			{
				eBody = battle->getEnemys()[i]->getComponent<RidgidBody>();
				factory->createObject("04", eBody->position->x, eBody->position->y);
			}
			break;
		case 3:
			vector<GameObject*> targets;
			if (battle->getPlayer() == getOwner())
			{
				for (int j = 0; j < getOwner()->getComponent<MoveSpace>()->getSpaces().size(); j++)
				{
					float sx = getOwner()->getComponent<MoveSpace>()->getSpaces()[j]->getComponent<RidgidBody>()->position->x;
					float sy = getOwner()->getComponent<MoveSpace>()->getSpaces()[j]->getComponent<RidgidBody>()->position->y;
					for (int i = 0; i < battle->getAlly().size(); i++)
					{
						float	ex = battle->getAlly()[i]->getComponent<RidgidBody>()->position->x;
						float	ey = battle->getAlly()[i]->getComponent<RidgidBody>()->position->y;
						if (ex == sx && ey == sy)
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx + 64) && ey == sy)
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx - 64) && ey == sy)
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == sx && ey == (sy + 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == sx && ey == (sy - 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx + 64) && ey == (sy + 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx + 64) && ey == (sy - 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx - 64) && ey == (sy + 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
						else if (ex == (sx - 64) && ey == (sy - 64))
						{
							targets.push_back(battle->getAlly()[i]);
						}
					}
				}
				if (!targets.empty() && battle->getTarget() == nullptr&& getOwner()->getComponent<Stats>()->getMoveSpace() > 0)
				{
					unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
					std::default_random_engine generator(seed);
					float size = targets.size() - 1;
					std::uniform_real_distribution<float> distribution(0.0, size);
					int num;
					num = distribution(generator);

					battle->setTarget(targets[num]);
					targets.clear();

				}
				else if (battle->getTarget() == nullptr && battle->getSpace()==nullptr && getOwner()->getComponent<Stats>()->getMoveSpace() > 0)
				{
					getOwner()->getComponent<EnemyAi>()->moveToPlayer();
				}
			}
			targets.clear();
			break;
		}
		return nullptr;
	}


void Ability::finish()
{

}