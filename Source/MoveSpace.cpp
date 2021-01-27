#include"MoveSpace.h"
#include"RidgidBodyComponent.h"
#include"Stats.h"

MoveSpace::MoveSpace(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, ObjectFactory* factory) :Component(owner)
{
	this->battle = battle;
	this->factory = factory;
}

MoveSpace::~MoveSpace()
{

}

void MoveSpace::start()
{

}

GameObject* MoveSpace::update()
{

	
	if (battle->getPlayer() == getOwner() && create==false)
	{
		createMovementSpace(getOwner()->getComponent<Stats>()->getMoveSpace());
		create = true;
		getMoveSpaces();
	}
	else if (battle->getPlayer() != getOwner())
	{
		spaces.clear();
		create = false;
	}


	if (battle->getPlayer() == getOwner())
	{
		getCurrentSpace();
	}
	return nullptr;
}


void MoveSpace::finish()
{

}

void MoveSpace::getMoveSpaces()
{
	for (int i = 0; i < factory->getQue().size(); i++)
	{
		if (factory->getQue()[i]->id == "02")
		{
			spaces.push_back(factory->getQue()[i]);
		}
	}
}

void MoveSpace::createMovementSpace(int moveNum)
{
	int offset = 2 * moveNum + 1;
	GameObject* player = battle->getPlayer();
	int pX = player->getComponent<RidgidBody>()->position->x;
	int pY = player->getComponent<RidgidBody>()->position->y;
	int sX = pX + (64 * (offset / 2));
	int sY = pY;

	while (offset > 0)
	{
		for (int i = offset; i != 0; i--)
		{
			factory->createObject("02", sX, sY);
			sX = sX - 64;

		}
		offset -= 2;
		sX = pX + (64 * (offset / 2));
		sY -= 64;

	}
	offset = (2 * moveNum + 1) - 2;
	sX = pX + (64 * (offset / 2));
	sY = pY + 64;
	while (offset >0)
	{
		for (int i = offset; i != 0; i--)
		{
			factory->createObject("02", sX, sY);
			sX = sX - 64;

		}
		sY += 64;

		offset -= 2;
		sX = pX + (64 * (offset / 2));
	}
}

void MoveSpace::getCurrentSpace()
{
	int sX;
	int sY;
	float cX;
	float cY;
	if (currentSpace == nullptr)
	{
		for (int i = 0; i < spaces.size(); i++)
		{
			sX = spaces[i]->getComponent<RidgidBody>()->position->x;
			sY = spaces[i]->getComponent<RidgidBody>()->position->y;
			cX = getOwner()->getComponent<RidgidBody>()->position->x;
			cY = getOwner()->getComponent<RidgidBody>()->position->y;

			if (sX == cX && sY == cY)
			{
				currentSpace = spaces[i];
			}

		}
	}
	else
	{
		cX=currentSpace->getComponent<RidgidBody>()->position->x;
		cY= currentSpace->getComponent<RidgidBody>()->position->y;
		sX = getOwner()->getComponent<RidgidBody>()->position->x;
		sY= getOwner()->getComponent<RidgidBody>()->position->y;
		if (cX != sX || cY != sY)
		{
			for (int i = 0; i < spaces.size(); i++)
			{
				sX = spaces[i]->getComponent<RidgidBody>()->position->x;
				sY = spaces[i]->getComponent<RidgidBody>()->position->y;
				cX = getOwner()->getComponent<RidgidBody>()->position->x;
				cY = getOwner()->getComponent<RidgidBody>()->position->y;

				if (sX == cX && sY == cY)
				{
					getOwner()->getComponent<Stats>()->movementSpaces=getOwner()->getComponent<Stats>()->movementSpaces- 1;
					currentSpace = spaces[i];
				}
			}
		}

	}
}