#include"Window.h"
#include"SpriteComponent.h"
#include"Texture.h"

Window::Window(GameObject* owner, tinyxml2::XMLElement* componentElement, Overworld* overworld) :Component(owner)
{
	this->overworld = overworld;

}

Window::~Window()
{

}

void Window::start()
{

}

GameObject* Window::update()
{

	if (overworld->timer < 60)
	{
		overworld->timer++;
	}
	else
	{
		overworld->timer = 0;
		overworld->time++;
		if (overworld->time > 900)
		{
			if (overworld->alpha <= 180)
			{
				overworld->alpha++;

			}
		}
		else
		{
			if (overworld->alpha > 0)
			{
				overworld->alpha--;
			}
		}

	}
	if (overworld->time >= overworld->maxTime)
	{
		overworld->time = 0;
	}
	RGBA color;
	color.B = 225;
	color.G = 225;
	color.R = 225;
	color.B = color.B - overworld->alpha;
	color.G = color.G - overworld->alpha;
	color.R = color.R - overworld->alpha;
	getOwner()->getComponent<Sprite>()->getTexture()->setRGBA(color);
	return nullptr;
}


void Window::finish()
{

}