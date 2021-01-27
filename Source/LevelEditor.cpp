#include"LevelEditor.h"
#include <iostream>
#include<fstream>
#include"GameObject.h"
#include"RidgidBodyComponent.h"
#include"Waypiont.h"
#include"SpriteComponent.h"
using namespace std;
LevelEditor::LevelEditor(View* view)
{
	this->view = view;
}

LevelEditor::~LevelEditor()
{

}

void LevelEditor::createMap(int width,int height)
{
	string backgroundTex;

	for (int i = 0; i < width; i = i + 32)
	{
		for (int j = 0; j < height; j = j + 32)
		{
			factory->createObject("12", i, j);
		}
	}
}
void LevelEditor::saveLevel(vector<GameObject*> objects)
{
	vector<GameObject*> newObjects;
	bool repeat = false;
	for (int i = 0; i < objects.size(); i++)
	{
		if (newObjects.size() != 0)
		{


			for (int j = 0; j < newObjects.size() - 1; j++)
			{
				if (objects[i]->id == newObjects[j]->id)
				{
					if (newObjects[j]->getComponent<RidgidBody>()->position->x == objects[i]->getComponent<RidgidBody>()->position->x && newObjects[j]->getComponent<RidgidBody>()->position->y == objects[i]->getComponent<RidgidBody>()->position->y)
					{
						repeat = true;
					}
				}
			}
		}
		else
		{
			if (objects[i]->id != "12" && repeat == false)
			{
				newObjects.push_back(objects[i]);
			}
		}
			if (objects[i]->id != "12" && repeat == false)
			{
				newObjects.push_back(objects[i]);
			}
			repeat = false;


			
		
	}
	cout << "Please name level." << endl;
	string name;
	cin >> name;
	name = name + ".txt";
	ofstream outfile(name);
	
	for (int i = 0; i < newObjects.size(); i++)
	{
		outfile << newObjects[i]->id<<" " << newObjects[i]->getComponent<RidgidBody>()->position->x << " " << newObjects[i]->getComponent<RidgidBody>()->position->y <<" " << endl;
		if (newObjects[i]->id == "49")
		{
			outfile << newObjects[i]->getComponent<Waypoint>()->getMap() << " " << newObjects[i]->getComponent<Waypoint>()->getX() << " " << newObjects[i]->getComponent<Waypoint>()->getY();
		}
	}
	outfile.close();
}

void LevelEditor::loadLevel(string level)
{
	ifstream file("./Assets/Levels/"+level);
	string type;
	int x;
	int y;
	file >> x >> y;
	file >> type >> x;
	if (x == 1)
	{
		factory->createObject(type, 0, 0);
		factory->getQue()[0]->getComponent<Sprite>()->rect->w = x + 100;
		factory->getQue()[0]->getComponent<Sprite>()->rect->h = y + 100;
	}
	createMap(x, y);

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

}
void LevelEditor::playLevel(string level)
{
	ifstream file("./Assets/Levels/" + level);
	string type;
	int x;
	int y;
	file >> x >> y;

	view->camera->w = x;
	view->camera->h = y;
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
	
	factory->createObject("01", 20,20);
	factory->createObject("50", 0, 0);
	factory->getQue().back()->getComponent<Sprite>()->changeAlpha(200);
}