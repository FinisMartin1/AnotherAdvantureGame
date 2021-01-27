#include"Night.h"

#include"GameObject.h"
#include"SpriteComponent.h"
Night::Night(GameObject* owner, tinyxml2::XMLElement* componentElement,Overworld* overworld) :Component(owner)
{
	this->overworld = overworld;
}

Night::~Night()
{

}
void Night::start()
{

}

GameObject* Night::update()
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
			if (alpha <= 180)
			{
				alpha++;

			}
		}
		else
		{
			if (alpha > 0)
			{
				overworld->alpha--;
			}
		}

	}
	if (overworld->time >= overworld->maxTime)
	{
		overworld->time = 0;
	}
	getOwner()->getComponent<Sprite>()->changeAlpha(overworld->alpha);
	return nullptr;
}

void Night::finish()
{

}