#include "DrawBar.h"

DrawBar::DrawBar(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{

}

DrawBar::~DrawBar()
{

}


void DrawBar::start()
{

}

GameObject* DrawBar::update()
{
	if (battle->getPlayer() != nullptr)
	{
		if (battle->getPlayer()->primaryId == player->primaryId && battle->getPlayer()->id2=="00")
		{
			
		}
	}
	return nullptr;
}

void DrawBar::finish()
{

}