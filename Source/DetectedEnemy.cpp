#include"DetectedEnemy.h"
#include"Battle.h"
#include"RidgidBodyComponent.h"
#include"GameObject.h"

DetectedEnemy::DetectedEnemy(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, ObjectFactory* factory) :Component(owner)
{
	this->battle = battle;
	this->factory = factory;
	
}

DetectedEnemy::~DetectedEnemy()
{

}

void DetectedEnemy::start() {}

GameObject* DetectedEnemy::update() {
	RidgidBody* body = getOwner()->getComponent<RidgidBody>();
	float sx = body->position->x;
	float sy = body->position->y;
	RidgidBody* eBody;
	float ex;
	float ey;
	for (int i = 0;  i< battle->getEnemys().size(); i++)
	{
		ex = battle->getEnemys()[i]->getComponent<RidgidBody>()->position->x;
		ey= battle->getEnemys()[i]->getComponent<RidgidBody>()->position->y;
		if (ex == sx && ey == sy)
		{
			factory->createObject("04",ex,ey);
		}
		else if (ex == (sx+64) && ey == sy)
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == (sx-64) && ey == sy)
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == sx && ey == (sy+64))
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == sx && ey == (sy-64))
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == (sx+64) && ey == (sy+64))
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == (sx+64) && ey == (sy-64))
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == (sx-64) && ey == (sy+64))
		{
			factory->createObject("04", ex, ey);
		}
		else if (ex == (sx-64) && ey == (sy-64))
		{
			factory->createObject("04", ex, ey);
		}

	}

	return nullptr;
}

void DetectedEnemy::finish() {}