#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<memory>
#include<iostream>
#include<vector>
#include "SDL.h"
#include "ObjectDefinitions.h"

class Component;
class Sprite;
class InputHandler;
class GameLibrary;

using namespace std;

class GameObject
{
public:
	enum facing{UP,DOWN,RIGHT,LEFT,UPRIGHT,DOWNRIGHT,UPLEFT,DOWNLEFT,NA};
	GameObject();
	~GameObject();
	bool initialize();

	void addComponent( Component* component);
	//come back to this

	template<class T>
	T* getComponent()
	{
		for (auto& component : components)
		{
			T* target = nullptr;
			if ( target = dynamic_cast<T*>(component.get()))
			{
				return(target);
			}
		}
		return(nullptr);
	}

	GameObject* update();
	void draw();
	void deleteSelf();
	string createPrimaryID();
	// vitality
	bool live{ true };
	bool isDead = false;
	string id;
	string id2;
	string primaryId = id + id2 + createPrimaryID();
	bool isBattle = false;
	facing currentDir = facing::NA;
	facing prevDir = facing::NA;
	bool isPlayer = false;
protected:

	vector<unique_ptr<Component>> components;
	bool initialized{ false };
	bool moving = false;

};

#endif
