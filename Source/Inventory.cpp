#include"Inventory.h"
#include"GameObject.h"
#include"Frame.h"
#include"Effects.h"
#include"Stats.h"

Inventory::Inventory(GameObject* owner, tinyxml2::XMLElement* componentElement,ObjectFactory* factory,Battle* battle, Overworld* overworld) :Component(owner)
{
	this->factory = factory;
	this->battle = battle;
	this->overworld = overworld;
	inventorySlots[0][0].setAmount(1);
	inventorySlots[0][0].setItemNum(1);
}
Inventory::~Inventory()
{

}

void Inventory::start()
{

}

GameObject* Inventory::update()
{

	int countRow = 0;
	int countCol = 0;
	if (createInventory == true&& timer<=0&&inventoryOpen==true)
	{


		for (int i = 160; i < factory->w - 160; i = i + 32)
		{
			i++;
			
			for (int j = 160; j < factory->h - 160; j = j + 32)
			{

				j++;
				factory->createObject("16", i, j);
				
				if (inventorySlots[countRow][countCol].getItemNum() != 0)
				{
					factory->createObject("15", i, j);

					factory->getQue()[factory->getQue().size() - 1]->getComponent<Frame>()->setFrarmNum(inventorySlots[countRow][countCol].getItemNum());
				}
	
				countRow++;
				
			}
			countRow = 0;
			overworld->inventoryOpen = true;
			battle->inventoryOpen = true;
			this->inventoryOpen = true;
			countCol++;
		}
		createInventory = false;
		timer = 10;

	}
	if (inventoryOpen == true)
	{
		factory->createObject("17", 160 + 33 * row, 160 + 33 * col);
	}
	if (inventoryOpen == false && timer <= 0  && createInventory == true)
	{
		overworld->inventoryOpen = false;
		battle->inventoryOpen = false;
		this->inventoryOpen = false;
		createInventory = false;
		timer = 10;
	}
	if (useItem == true)
	{
		useCurrentItem(inventorySlots[row][col].getItemNum());
	}

	timer--;
	return nullptr;
}

void Inventory::finish()
{

}

void Inventory::useCurrentItem(int item)
{
	switch (item)
	{
	case 1:
		getOwner()->getComponent<Stats>()->health = getOwner()->getComponent<Stats>()->health + 60;
		break;
	}

	if (inventorySlots[row][col].getAmount() > 0)
	{
		inventorySlots[row][col].setAmount(inventorySlots[row][col].getAmount() - 1);
	}
	if (inventorySlots[row][col].getAmount() <= 0)
	{
		inventorySlots[row][col].setAmount(0);
		inventorySlots[row][col].setItemNum(0);
	}
	useItem = false;
	timer = 10;
}