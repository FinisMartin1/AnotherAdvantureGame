#include "TextureLibrary.h"
#include "GameObject.h"
#include "Component.h"
#include "RidgidBodyComponent.h"
#include "SpriteComponent.h"
#include "Texture.h"
#include "View.h"
#include <string>

Sprite::Sprite(GameObject* owner, tinyxml2::XMLElement* componentElement, TextureLibrary* library,View* view) : Component(owner)
{
// update this!!
	this->library = library;
	float sx;
	float sy;
	float cx;
	float cy;
	componentElement->QueryFloatAttribute("sx",&sx);
	componentElement->QueryFloatAttribute("sy", &sy);
	componentElement->QueryFloatAttribute("cx", &cx);
	componentElement->QueryFloatAttribute("cy", &cy);
	sposition->x = sx;
	sposition->y = sy;
	scenter->x = cx;
	scenter->y = cy;
	tempPos->x = 0;
	tempPos->y = 0;
	int sw;
	int sh;
	componentElement->QueryIntAttribute("sw", &sw);
	componentElement->QueryIntAttribute("sh",&sh);
	size->x = sw;
	size->y = sh;
	rect->x=sx;
	rect->y = sy;
	rect->w = sw;
	rect->h = sh;
	const char* pathName;
	componentElement->QueryStringAttribute("path", &pathName);
	path = pathName;
	angle = 0;
	setTexture(&path);
	componentElement->QueryStringAttribute("path", &pathName);
	ready = true;
	this->view = view;

}

Sprite::~Sprite() {}

void Sprite::initialize(TextureLibrary* library, ObjectTemplate* temp)
{
	// get rid of this!!!

}

void Sprite::start() {}

GameObject* Sprite::update() {
	

 
	return nullptr;
}

void Sprite::finish() {}

void Sprite::draw()
{
	
	RidgidBody* body = getOwner()->getComponent<RidgidBody>();
	
	tempPos->x = body->position->x;
	tempPos->y = body->position->y;
	if (getOwner()->id2 == "00")
	{
		if (getOwner()->currentDir == getOwner()->DOWN|| getOwner()->currentDir == getOwner()->DOWNRIGHT|| getOwner()->currentDir == getOwner()->DOWNLEFT)
		{
			if (timer < 0)
			{


				if (frameX > 8)
				{
					frameX = 1;
				}
				rect->y = 64 * 10;
				rect->x = frameX * 64;
				frameX++;
				timer = 8;
			}
			timer--;
		}
		if (getOwner()->currentDir == getOwner()->UP|| getOwner()->currentDir == getOwner()->UPRIGHT|| getOwner()->currentDir == getOwner()->UPLEFT)
		{
			if (timer < 0)
			{


				if (frameX > 8)
				{
					frameX = 1;
				}
				rect->y = 64 * 8;
				rect->x = frameX * 64;
				frameX++;
				timer = 8;
			}
			timer--;
		}
		if (getOwner()->currentDir == getOwner()->RIGHT)
		{
			if (timer < 0)
			{


				if (frameX > 8)
				{
					frameX = 1;
				}
				rect->y = 64 * 11;
				rect->x = frameX * 64;
				frameX++;
				timer = 8;
			}
			timer--;
		}
		if (getOwner()->currentDir == getOwner()->LEFT)
		{
			if (timer < 0)
			{


				if (frameX > 8)
				{
					frameX = 1;
				}
				rect->y = 64 * 9;
				rect->x = frameX * 64;
				frameX++;
				timer = 8;
			}
			timer--;
		}
		if(getOwner()->currentDir==getOwner()->NA)
		{ 
			rect->x = 0;
			timer = 0;
		}

	}
	tempPos->x = tempPos->x - view->camera->x;
	tempPos->y = tempPos->y - view->camera->y;
	if(ready)texture->draw(tempPos, body->angle, body->center, rect);
}

void Sprite::setTexture(string * path)
{       
	    this->path = *path;
		texture = library->getArtAsset(library->imgPath + *path);
		texture->setRGBA(color);
}

string Sprite::getPath()
{
	
	return path;
}
void Sprite::changeAlpha(int alpha)
{
	SDL_SetTextureAlphaMod(texture->getTexture(), alpha);
}