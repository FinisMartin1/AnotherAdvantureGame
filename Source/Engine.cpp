#include "Engine.h"
#include <string>
#include <vector>
#include <iostream>
#include "Definitions.h"
#include "GameObject.h"

#include "RidgidBodyComponent.h"
#include "SpriteComponent.h"
#include "Stats.h"
#include "Clickable.h"
#include "Container.h"

// rework this

Engine::Engine(string path)
{
	

	library->imgPath = imgPath;
	factory->xmlPath = xmlPath;
	loadLevel(path);
	

	
	editor.get()->setFactory(factory.get());
	editor.get()->playLevel("beachTown_2.txt");

	SDL_StopTextInput();

}


Engine::~Engine() {

}


void Engine::loadLevel(string path)
{
	current_map = path;
	string objectType;
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(path.c_str()) != tinyxml2::XML_SUCCESS) {
		printf("Bad File Path");
		exit(1);
	}

	//Get root
	tinyxml2::XMLElement* root = doc.FirstChildElement("Level");
	
	char tempType;
	float type;
	GameObject* object;
	for (tinyxml2::XMLElement* obj = root->FirstChildElement("Object"); obj != NULL; obj = obj->NextSiblingElement())
	{
		const char*objType;

		type = obj->QueryFloatAttribute("type", &type);





		object = factory->applyXML(obj);
		object->id = type;

		inventory.push_back(object);


	}
	
	
}
void Engine::createBattleSpace()
{

	for (int i = 32; i < gDevice->getHeight()-32; i = i + 64)
	{
		for (int j = 32; j < gDevice->getWidth() - 32; j = j + 64)
		{
			factory.get()->createObject("00", j, i);
			
		}
	}


}
void Engine::updateObjects()
{
	if (factory->mapChange == true)
	{
		objects.clear();
		factory->mapChange = false;
	}
	for (int i = 0; i < factory.get()->getQue().size(); i++)
	{
		objects.push_back(factory.get()->getQue()[i]);
	}


	factory.get()->clearQue();
	battle->clearLists();
}
void Engine::update()
{

	int w = gDevice->getWidth();
	int h = gDevice->getHeight();
	factory.get()->setResolution(gDevice->getWidth(), gDevice->getHeight());
	vector<GameObject*>newObjects;
	bool repeat = false;
    int count = 0;
	if (timer < 60)
	{
		timer++;
	}
	else
	{
		timer = 0;
		time++;

	}
	
	if (input->keyStates[InputHandler::Inputs::COMMAND] == true)
	{
		string command;
		
		cin >> command;
		commandList(command);

	}
	if (input->keyStates[InputHandler::Inputs::J] == true && bTimer <= 0)
	{
		int brush = stoi(editor->getBrush());
		brush--;
		cout << "Current Brush is " << brush << endl;
		editor->changeBrushType(to_string(brush));
		bTimer = 10;

	}
	if (input->keyStates[InputHandler::Inputs::L] == true && bTimer<=0)
	{
		int brush = stoi(editor->getBrush());
		brush++;
		cout << "Current Brush is " << brush << endl;
		editor->changeBrushType(to_string(brush));
		bTimer = 10;
	}
	bTimer--;
	if (input->keyStates[InputHandler::Inputs::BACK] == true && freeCam == true)
	{
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->getComponent<RidgidBody>()->removeBody();
			objects[i]->getComponent<RidgidBody>()->position->y=objects[i]->getComponent<RidgidBody>()->position->y + 2;
			if (objects[i]->id == "37")
			{
				objects[i]->getComponent<RidgidBody>()->setWallBody();
			}
			else
			{
				objects[i]->getComponent<RidgidBody>()->setPhysicsBody();
			}
		}

	}
	if (input->keyStates[InputHandler::Inputs::FORWARD] == true && freeCam == true)
	{
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->getComponent<RidgidBody>()->removeBody();
			objects[i]->getComponent<RidgidBody>()->position->y = objects[i]->getComponent<RidgidBody>()->position->y - 2;
			if (objects[i]->id == "37")
			{
				objects[i]->getComponent<RidgidBody>()->setWallBody();
			}
			else
			{
				objects[i]->getComponent<RidgidBody>()->setPhysicsBody();
			}
		}

	}
	if (input->keyStates[InputHandler::Inputs::LEFT] == true && freeCam == true)
	{
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->getComponent<RidgidBody>()->removeBody();
			objects[i]->getComponent<RidgidBody>()->position->x = objects[i]->getComponent<RidgidBody>()->position->x - 2;
			if (objects[i]->id == "37")
			{
				objects[i]->getComponent<RidgidBody>()->setWallBody();
			}
			else
			{
				objects[i]->getComponent<RidgidBody>()->setPhysicsBody();
			}
		}

	}
	if (input->keyStates[InputHandler::Inputs::RIGHT] == true && freeCam == true)
	{
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->getComponent<RidgidBody>()->removeBody();
			objects[i]->getComponent<RidgidBody>()->position->x = objects[i]->getComponent<RidgidBody>()->position->x + 2;
			if (objects[i]->id == "37")
			{
				objects[i]->getComponent<RidgidBody>()->setWallBody();
			}
			else
			{
				objects[i]->getComponent<RidgidBody>()->setPhysicsBody();
			}
		}

	}
	
	updateObjects();

	for (int i = 0; i < objects.size(); i++)

	{

		if (!overworld->getEntitys().empty())
		{
			objects[i] = overworld->getEntityById(objects[i]->primaryId);
		}
		if (!battle->getPlayers().empty())
		{
			objects[i] = battle->getPlayerById(objects[i]->primaryId);
		}
		if (objects[i] == nullptr)
		{
			objects[i]->isDead = true;
		}
	}

	if (battle->isBattle==true)
	{
		battle->update();
	}
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->id2 == "00")
		{
			battle->addPlayer(objects[i]);
			battle->addAlly(objects[i]);
			overworld->addEntity(objects[i]);

		}
		if (objects[i]->id == "02")
		{

			if (objects[i]->getComponent<Clickable>()->clickCheck() == true)
			{
				if (!battle->isPlayerInSpace(objects[i]))
				{
					battle->setSlectedSpace(objects[i]);
				}
			}



		}
		if (objects[i]->id2 == "01")
		{
			battle->addPlayer(objects[i]);
			battle->addEnemy(objects[i]);
			overworld->addEntity(objects[i]);

		}
	}
	for (int i = 0; i < objects.size(); i++)
	{

		if (isBattle == false)
		{
			objects[i]->isBattle = false;
		}
		else
		{
			objects[i]->isBattle = true;
		}
		if (objects[i]->id == "01")
		{
			view->camera->x = objects[i]->getComponent<RidgidBody>()->position->x-400;
			view->camera->y = objects[i]->getComponent<RidgidBody>()->position->y-400;
		}
		if (!objects[i]->isDead) {
			GameObject* newObject;

				newObject=objects[i]->update();

			if (newObject != nullptr) {
				newObjects.push_back(newObject);
				newObject->initialize();
			}


		}

	}
	


	objects.clear();
	for (int i = 0; i < newObjects.size(); i++)
	{
		
		objects.push_back(newObjects[i]);
	}
	overworld->clearEntitys();
	physics.get()->update(1.0f / gDevice->FPS);
	battle->createInventory = false;
	if (view->camera->x < 0)
	{
		view->camera->x = 0;
	}
	if (view->camera->y < 0)
	{
		view->camera->y = 0;
	}
	if (view->camera->x > (view->camera->w ))
	{
		view->camera->x = view->camera->w ;
	}
	if (view->camera->y > (view->camera->h ))
	{
		view->camera->y = view->camera->h;
	}
}

void Engine::draw()
{
	gDevice->begin();
	for (int i = 0; i < objects.size(); i++)
	{
		
			objects[i]->draw();
		
	}
	gDevice->present();
}
	bool Engine::run()
	{
		//Construct Frame Timer
		std::unique_ptr<Timer> frameRate = make_unique<Timer>();
		if (!frameRate->Initialize(gDevice->FPS))
		{
			printf("Frame Timer could not intialize! SDL_Error: %s\n", SDL_GetError());
			exit(1);
		}


		SDL_Event* Event=new SDL_Event;

		while (SDL_PollEvent(Event))
		{
			input->update(Event);

		}

		if (!paused) {
			//Start Frame Timer
			frameRate->start();

			// update objects
			update();

			// draw objects
			draw();

			//pauses until proper refresh time has passed.
			frameRate->fpsRegulate();
		}
		return true;
	}

	bool Engine::detectCollision(GameObject * object1, GameObject * object2)
	{
		return false;
	}

	void Engine::addToLibary(GameObject* object)
	{
		inventory.push_back(object);
	}
	void Engine::createMovementSpace(int moveNum)
	{
		int offset = 2 * moveNum + 1;
		GameObject* player = battle->getPlayer();
		int pX=player->getComponent<RidgidBody>()->position->x;
		int pY = player->getComponent<RidgidBody>()->position->y;
		int sX = pX + (64* (offset/2));
		int sY = pY;

		while (offset > 0)
		{
			for (int i = offset; i != 0; i--)
			{
				factory.get()->createObject("02", sX, sY);
				sX = sX - 64;
				
			}
			offset -= 2;
			sX = pX + (64 * (offset / 2));
			sY -= 64;
			
		}
		offset = (2 * moveNum + 1)-2;
		sX = pX + (pX * (offset / 2));
		sY = pY+64;
		while (offset >= 1)
		{
			for (int i = offset; i != 0; i--)
			{
				factory.get()->createObject("02", sX, sY);
				sX = sX - 64;

			}
			sY += 64;

			offset -= 2;
			sX = pX + (64 * (offset / 2));
		}
	}

void Engine::commandList(string command)
{
	if (command == "openLevelEditor")
	{
		objects.clear();
		factory->createMap();
		isBattle = false;
		editor->isLevelEditor = true;
 }
	if (command == "saveLevel")
	{
		editor.get()->saveLevel(objects);
		cout << "Save Complete!" << endl;
	}
	if (command == "loadLevel")
	{
		cout << "which level?" << endl;
		string level;
		cin >> level;
		objects.clear();
	
		editor.get()->loadLevel(level);
		cout << "Load Complete!" << endl;
		
	}
	if (command == "changeBrush")
	{
		string type;
		cin >> type;
		editor.get()->changeBrushType(type);
		cout << "Brush has been set to " << type << endl;

	}
	if (command == "debug")
	{
		editor->isLevelEditor = true;
		cout << "Debug Mode On" << endl;

	}
	if (command == "freeCam")
	{
		if (freeCam == false)
		{


			freeCam = true;
			cout << "Free Camera Enabled" << endl;
		}
		else
		{
			freeCam = false;
			cout << "Free Camera Disabled" << endl;
		}
	}
	if (command == "playLevel")
	{
		string level;
		cin >> level;
		objects.clear();
		editor.get()->playLevel(level);
	}
	if (command == "setBrushSize")
	{
		int x, y;
		cin >> x >> y;
		editor->setBrushX(x);
		editor->setBrushY(y);
		cout << "Brush size has been set to " << x << " x " << y << endl;
	}
}

