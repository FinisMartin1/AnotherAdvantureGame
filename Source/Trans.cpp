#include"Trans.h"

#include"GameObject.h"
#include"SpriteComponent.h"
Trans::Trans(GameObject* owner, tinyxml2::XMLElement* componentElement) :Component(owner)
{
	float alpha = 0;
	componentElement->QueryFloatAttribute("alpha", &alpha);
	this->alpha = alpha;
}

Trans::~Trans()
{

}

void Trans::start()
{

}

GameObject* Trans::update()
{
	getOwner()->getComponent<Sprite>()->changeAlpha(alpha);
	return nullptr;
}

void Trans::finish()
{

}