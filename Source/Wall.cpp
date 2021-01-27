#include "Wall.h"
#include"SpriteComponent.h"
#include"GameObject.h"
#include"RidgidBodyComponent.h"

Wall::Wall(GameObject* owner, tinyxml2::XMLElement* componentElement, LevelEditor* editor,PhysicsDevice* physics) :Component(owner)
{
	this->editor = editor;
	this->physics = physics;
	getOwner()->getComponent<RidgidBody>()->setWallBody();
}

Wall::~Wall()
{

}

void Wall::start()
{

}

GameObject* Wall::update()
{
	
	getOwner()->getComponent<RidgidBody>()->setActive();

	if (editor->isLevelEditor == true)
	{
		getOwner()->getComponent<Sprite>()->changeAlpha(100);
	
	}
	else
	{

		getOwner()->getComponent<Sprite>()->changeAlpha(0);

	}
	return nullptr;
}

void Wall::finish()
{

}