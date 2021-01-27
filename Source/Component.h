#ifndef COMPONENT_H
#define COMPONENT_H
#include <memory>
#include <vector>

class GameObject;
class ObjectTemplate;

union SDL_Event;

class Component
{
public:
	Component(GameObject* owner);
	~Component();
	void ownerDestroyed();
	GameObject* getOwner();
	virtual void start() = 0;
	virtual GameObject* update() = 0;
	virtual void finish() = 0;




protected:
	
	GameObject* _owner;
};


#endif