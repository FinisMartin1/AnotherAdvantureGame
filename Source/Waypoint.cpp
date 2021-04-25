#include"Waypiont.h"
#include"GameObject.h"
#include"RidgidBodyComponent.h"
#include"SpriteComponent.h"
#include<fstream>

Waypoint::Waypoint(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory,Overworld* overworld,View* view,LevelEditor* editor) :Component(owner)
{
	this->factory = factory;
	this->overworld = overworld;
	this->view = view;
	this->editor = editor;
}

Waypoint::~Waypoint()
{

}

void Waypoint::start()
{

}


GameObject* Waypoint::update()
{
	Vector2D* playerPos = new Vector2D();
	Vector2D* pos = new Vector2D();
	GameObject* player = new GameObject();
	if (!editor->getIsEditor())
	{
		player = overworld->getEntityById("01");
		pos->x = getOwner()->getComponent<RidgidBody>()->position->x;
		pos->y = getOwner()->getComponent<RidgidBody>()->position->y;
		playerPos->x = player->getComponent<RidgidBody>()->position->x;
		playerPos->y = player->getComponent<RidgidBody>()->position->y;

		if (playerPos->x > pos->x && playerPos->x<(pos->x + 32) && playerPos->y>pos->y && playerPos->y < (pos->y + 32))
		{
			ifstream file("./Assets/Levels/" + map);
			string type;
			int x;
			int y;

			file >> x >> y;
			view->camera->x = 0;
			view->camera->y = 0;
			view->camera->w = x;
			view->camera->h = y;
			file >> type >> x;
			if (x == 1)
			{
				factory->createObject(type, 0, 0);
				factory->getQue()[0]->getComponent<Sprite>()->rect->w = x + 100;
				factory->getQue()[0]->getComponent<Sprite>()->rect->h = y + 100;
			}
			while (!file.eof())
			{
				file >> type >> x >> y;
				factory->createObject(type, x, y);
				if (type == "49")
				{
					string map;
					float px;
					float py;
					file >> map >> px >> py;
					factory->getQue().back()->getComponent<Waypoint>()->setMap(map);
					factory->getQue().back()->getComponent<Waypoint>()->setPlayerPosition(px, py);
				}

			}

			factory->createObject("01", pX, pY);
		
			factory->mapChange = true;
			return nullptr;

		}
	}
	return nullptr;
}

void Waypoint::finish()
{

}