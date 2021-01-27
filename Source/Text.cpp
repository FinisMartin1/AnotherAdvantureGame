#include"Text.h"
#include"RidgidBodyComponent.h"
#include"GameObject.h"

Text::Text(GameObject* owner, tinyxml2::XMLElement* componentElement, TextureLibrary* library):Component(owner)
{
	this->library = library;
}

Text::~Text()
{

}

void Text::start()
{

}

GameObject* Text::update()
{

	TTF_Font* font=TTF_OpenFont((fontPath+"speech.ttf").c_str(), 30);
	if (!font) {
		printf("Unable to open font");
	}
	SDL_Color color = { 0,0,0,1 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* dialog = SDL_CreateTextureFromSurface(library->getRenderer(), textSurface);
	SDL_Rect textRect;
	textRect.x = getOwner()->getComponent<RidgidBody>()->position->x+20;
	textRect.y = getOwner()->getComponent<RidgidBody>()->position->y;
	SDL_QueryTexture(dialog, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(library->getRenderer(), dialog, NULL, &textRect);
	return nullptr;
}

void Text::finish()
{

}