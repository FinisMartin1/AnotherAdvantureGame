#ifndef WALL_H
#define WALL_H
#include"Component.h"
#include "tinyxml2.h"
#include "LevelEditor.h"
#include "PhysicsDevice.h"
class Wall :public Component
{
public:
	Wall(GameObject* owner, tinyxml2::XMLElement* componentElement,LevelEditor* editor, PhysicsDevice* physics);
	~Wall();

	void start();
	GameObject* update();
	void finish();
private:
	LevelEditor* editor;
	PhysicsDevice* physics;
	
};
#endif // !WALL_H

