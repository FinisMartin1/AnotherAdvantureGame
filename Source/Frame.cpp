#include "Frame.h"
#include "SpriteComponent.h"
#include"Clickable.h"
#include"RidgidBodyComponent.h"
Frame::Frame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{
	this->battle = battle;
}

Frame::~Frame()
{

}

void Frame::start()
{

}

GameObject* Frame::update()
{
	string path;
	const char* pathName;


	switch (frameNum)
	{
	case 0:
		pathName = "emptySpace.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	case 1:
		pathName = "healthPotion.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	}
	if (getOwner()->getComponent<Clickable>()->clickCheck())
	{
		getOwner()->getComponent<RidgidBody>()->position->x = getOwner()->getComponent<Clickable>()->mouseX-16;
		getOwner()->getComponent<RidgidBody>()->position->y = getOwner()->getComponent<Clickable>()->mouseY-16;
	}
	return nullptr;
}

void Frame::finish()
{

}