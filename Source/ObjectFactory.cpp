#include "Battle.h"
#include "ObjectFactory.h"
#include "GameObject.h"
#include "TextureLibrary.h"
#include "SpriteComponent.h"
#include "RidgidBodyComponent.h"
#include "Stats.h"
#include "Clickable.h"
#include "InputHandler.h"
#include "input.h"
#include "DetectedEnemy.h"
#include "SetTarget.h"
#include "Equipment.h"
#include "Ability.h"
#include "MoveSpace.h"
#include "EnemyAi.h"
#include "Effect.h"
#include "Gui.h"
#include "DeleteSelf.h"
#include "CreateObject.h"
#include "LevelEditor.h"
#include "PhysicsDevice.h"
#include "Pathfinding.h"
#include "Overworld.h"
#include "Faction.h"
#include "Inventory.h"
#include "Frame.h"
#include "eFrame.h"
#include "Dialog.h"
#include"Text.h"
#include"Follow.h"
#include"Wall.h"
#include"Waypiont.h"
#include"Night.h"
#include"Window.h"
#include"Container.h"
#include"Trans.h"
#include<iostream>
using namespace tinyxml2;

ObjectFactory::ObjectFactory(InputHandler* input, TextureLibrary* library, Battle* battle,LevelEditor* editor,PhysicsDevice* physics,Overworld* overworld,View* view) {
	
	this->input = input;
	this->library = library;
	this->battle = battle;
	this->editor = editor;
	this->physics = physics;
	this->overworld = overworld;
	this->view = view;
}

ObjectFactory::~ObjectFactory() {
}

GameObject* ObjectFactory::applyXML(tinyxml2::XMLElement* ObjectXML)
{
	// allocate new GameObject
	
	
	GameObject* object=new GameObject;

	for (
		tinyxml2::XMLElement* componentElement = ObjectXML->FirstChildElement();
		componentElement;
		componentElement = componentElement->NextSiblingElement()
		)
	{
		string componentName = componentElement->Attribute("name");
		if (componentName == "sprite")
		{
			object->addComponent(new Sprite(object, componentElement,library,view));
		}
		else if (componentName == "body")
		{
			object->addComponent(new RidgidBody(object, componentElement,physics,view));
			
		}
		else if (componentName == "clickable")
		{
			object->addComponent(new Clickable(object, componentElement,input));

		}
		else if (componentName == "stats")
		{
			object->addComponent(new Stats(object, componentElement,battle,overworld));

		}
		else if (componentName == "detectedenemy")
		{
			object->addComponent(new DetectedEnemy(object, componentElement,battle,this));

		}
		else if (componentName == "settarget")
		{
			object->addComponent(new SetTarget(object, componentElement, battle));

		}
		else if (componentName == "equipment")
		{
			object->addComponent(new Equipment(object, componentElement,overworld,battle,this));

		}
		else if (componentName == "ability")
		{
			object->addComponent(new Ability(object, componentElement,battle,input,this));

		}
		else if (componentName == "input")
		{
			object->addComponent(new UserInput(object, componentElement, battle, input));

		}
		else if (componentName == "movespace")
		{
			object->addComponent(new MoveSpace(object, componentElement, battle, this));

		}
		else if (componentName == "enemyai")
		{
			object->addComponent(new EnemyAi(object, componentElement, battle));

		}
		else if (componentName == "effect")
		{
			object->addComponent(new Effect(object, componentElement, battle));

		}
		else if (componentName == "gui")
		{
			object->addComponent(new Gui(object, componentElement,this, battle));

		}
		else if (componentName == "deleteself")
		{
			object->addComponent(new DeleteSelf(object, componentElement, battle,overworld));

		}
		else if (componentName == "createobject")
		{
			object->addComponent(new CreateObject(object, componentElement, this, editor));

		}
		else if (componentName == "pathfinder")
		{
			object->addComponent(new PathFinder(object, componentElement, physics));

		}
		else if (componentName == "faction")
		{
			object->addComponent(new Faction(object, componentElement, battle));

		}
		else if (componentName == "inventory")
		{
			object->addComponent(new Inventory(object, componentElement,this,battle,overworld));

		}
		else if (componentName == "frame")
		{
			object->addComponent(new Frame(object, componentElement,battle));

		}
		else if (componentName == "eframe")
		{
			object->addComponent(new eFrame(object, componentElement, battle));
		}
		else if (componentName == "dialog")
		{
			object->addComponent(new Dialog(object, componentElement,this));
		}
		else if (componentName == "text")
		{
		object->addComponent(new Text(object, componentElement, library));
		}
		else if (componentName == "follow")
		{
		object->addComponent(new Follow(object, componentElement, overworld));
		}
		else if (componentName == "wall")
		{
		object->addComponent(new Wall(object, componentElement, editor,physics));
		}
		else if (componentName == "waypoint")
		{
		object->addComponent(new Waypoint(object, componentElement,this,overworld,view));
		}
		else if (componentName == "night")
		{
		object->addComponent(new Night(object, componentElement,overworld));
		}
		else if (componentName == "window")
		{
		object->addComponent(new Window(object, componentElement, overworld));
		}
		else if (componentName == "container")
		{
		object->addComponent(new Container(object, componentElement, this, battle, overworld));
		}
		else if (componentName == "trans")
		{
		object->addComponent(new Trans(object, componentElement));
		}
	}
	return object;
}

void ObjectFactory::createObject(string pType, float x, float y)
{

	string current_map = "Assets/Config/level1.xml";
	string objectType;
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(current_map.c_str()) != tinyxml2::XML_SUCCESS) {
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
		const char* objType;

		objType = obj->Attribute("type");


		if (objType == pType)
		{
			object = applyXML(obj);
			object->id = objType;
			object->id2 = obj->Attribute("type2");
			RidgidBody* body = object->getComponent<RidgidBody>();
			body->position->x = x;
			body->position->y = y;
			if (object->id == "37")
			{
				object->getComponent<RidgidBody>()->setWallBody();
			}
			else 
			{
				object->getComponent<RidgidBody>()->setPhysicsBody();
			}

			objectsQue.push_back(object);
		}








	}


}
void ObjectFactory::createMap()
{
	int width;
	int height;
	cout << "Set Level Size: Witdh:Height" << endl;
	cin >> width;
	cin >> height;
	for (int i = 0; i < height; i = i + 32)
	{
		for (int j = 0; j < width; j = j + 32)
		{
			createObject("12", i, j);
		}
	}
}

void ObjectFactory::setResolution(int w, int h)
{
	this->w = w;
	this->h = h;
}