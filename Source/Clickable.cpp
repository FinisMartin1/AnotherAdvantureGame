#include "Clickable.h"
#include "sdl.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "RidgidBodyComponent.h"



Clickable::Clickable(GameObject* owner, tinyxml2::XMLElement* componentElement,InputHandler *input) :Component(owner)
{
	this->input = input;
}

Clickable::~Clickable()
{

}

void Clickable::start()
{

}

GameObject *Clickable::update()
{
	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);
	RidgidBody* body = getOwner()->getComponent<RidgidBody>();
	Sprite* sbody = getOwner()->getComponent<Sprite>();



	if (mouseX > body->position->x&& mouseX<(body->position->x + sbody->size->x) && mouseY>body->position->y&&mouseY < (body->position->y + sbody->size->y) && input->keyStates[InputHandler::Inputs::CLICK]==true)
	{
		clicked = true;
		return nullptr;
	}
	clicked = false;
	return nullptr;
}

void Clickable::finish()
{

}