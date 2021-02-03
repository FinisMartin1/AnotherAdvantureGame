#include"DeleteSelf.h"
#include"SpriteComponent.h"

DeleteSelf::DeleteSelf(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, Overworld* overworld) :Component(owner)
{
	float deleteType;
	componentElement->QueryFloatAttribute("deletetype", &deleteType);
	this->deleteType = deleteType;
	this->battle = battle;
	this->overworld = overworld;

}

DeleteSelf::~DeleteSelf()
{

}

void DeleteSelf::start()
{

}

GameObject* DeleteSelf::update()
{
	switch (deleteType)
	{
	case 0:
		if (battle->getPlayerDamaged())
		{
			getOwner()->deleteSelf();
			battle->setPlayerDamaged(false);
		}
		break;
	case 1:
		if (timer == 0)
		{
			getOwner()->getComponent<Sprite>()->rect->w--;
		}
		else
		{
			timer--;
		}
		if (getOwner()->getComponent<Sprite>()->rect->w == 0)
		{
			getOwner()->isDead = true;
		}
		break;
	case 2:
		if (overworld->inventoryOpen == false || battle->inventoryOpen == false)
		{
			getOwner()->isDead = true;
		}
		if (battle->createInventory == true)
		{
			getOwner()->isDead = true;
		}
		break;
	case 3:
		if (overworld->inventoryOpen == false || battle->inventoryOpen == false)
		{
			getOwner()->isDead = true;
		}
		if (timer == 0)
		{
			getOwner()->isDead = true;
		}
		else
		{
			timer--;
		}
		break;
	case 4:
		if (overworld->equipmentOpen == false || battle->equipmentOpen == false)
		{
			getOwner()->isDead = true;
		}
		break;
	case 5:
		if (overworld->equipmentOpen == false || battle->equipmentOpen == false)
		{
			getOwner()->isDead = true;
		}
		if (timer == 0)
		{
			getOwner()->isDead = true;
		}
		else
		{
			timer--;
		}
		break;
	case 6:

		if (overworld->contOpen == false || battle->contOpen == false)
		{
			getOwner()->isDead = true;
		}
		break;
	case 7:
		if (overworld->contOpen == false || battle->contOpen == false)
		{
			getOwner()->isDead = true;
		}
		if (timer == 0)
		{
			getOwner()->isDead = true;
		}
		else
		{
			timer--;
		}
		break;
	}

	return nullptr;
}

void DeleteSelf::finish()
{

}