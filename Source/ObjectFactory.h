#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include<string>
#include<map>
#include"ObjectDefinitions.h"

#include "tinyxml2.h"

using namespace std;


class Engine;
class GameObject;
class InputHandler;
class TextureLibrary;
class Battle;
class LevelEditor;
class PhysicsDevice;
class Overworld;
class View;

struct SDL_Renderer;

class ObjectFactory {
public:
	ObjectFactory(  InputHandler* input, TextureLibrary* library,Battle*battle,LevelEditor* editor,PhysicsDevice* physics,Overworld* overworld,View* view);
	~ObjectFactory();

	GameObject* applyXML(tinyxml2::XMLElement* obj);
	
	void createObject(std::string pType, float x, float y);
	std::vector<GameObject*> getQue()
	{
		return objectsQue;
	}
	void addToQue(GameObject* object)
	{
		objectsQue.push_back(object);
	}
	void clearQue()
	{
		objectsQue.clear();
	}
	void createMap();

	void setResolution(int w, int h);
	
	//void objectFromTemplate(ObjectTemplate* temp, shared_ptr<GameObject>);
	//void objectFromXML( XMLElement* ObjectXML, ObjectTemplate* baseObject, shared_ptr<GameObject>);

	std::string xmlPath = "";
	int w;
	int h;
	bool mapChange = false;
private:
	InputHandler* input;
	TextureLibrary* library;
	Battle* battle;
	PhysicsDevice* physics;
	std::vector<GameObject*>objectsQue;
	SDL_Renderer* renderer;
	Engine* engine;
	LevelEditor* editor;
	Overworld* overworld;
	View* view;


	//void getListObjects( XMLElement* comp, ObjectTemplate* baseObject, shared_ptr<vector<shared_ptr<GameObject>>> list);

	//ObjectTemplate templateFromXML( XMLElement * ObjectXML, ObjectTemplate* baseObject );
};


#endif
