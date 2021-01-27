#include "eFrame.h"
#include "SpriteComponent.h"
#include"Clickable.h"
#include"RidgidBodyComponent.h"
eFrame::eFrame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{
	this->battle = battle;
}

eFrame::~eFrame()
{

}

void eFrame::start()
{

}

GameObject* eFrame::update()
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
	case 3:
		pathName = "steelChestPlateIcon.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	case 5:
		pathName = "steelChestPlateIcon.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	case 6:
		pathName = "steelLeggingsIcon.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	case 7:
		pathName = "steelGunletIcon.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	case 8:
		pathName = "steelBootIcon.png";
		path = pathName;
		getOwner()->getComponent<Sprite>()->setTexture(&path);
		break;
	}
	if (getOwner()->getComponent<Clickable>()->clickCheck())
	{
		getOwner()->getComponent<RidgidBody>()->position->x = getOwner()->getComponent<Clickable>()->mouseX - 16;
		getOwner()->getComponent<RidgidBody>()->position->y = getOwner()->getComponent<Clickable>()->mouseY - 16;
	}
	return nullptr;
}

void eFrame::finish()
{

}