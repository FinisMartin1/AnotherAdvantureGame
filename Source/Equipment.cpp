#include"Equipment.h"
#include"Stats.h"
#include"eFrame.h"
#include"RidgidBodyComponent.h"
#include"SpriteComponent.h"
#include"Follow.h"
Equipment::Equipment(GameObject* owner, tinyxml2::XMLElement* componentElement,Overworld* overworld, Battle* battle ,ObjectFactory* factory) :Component(owner)
{
	float w;
	float chest;
	float leg;
	float helmet;
	float arm;
	float boot;
	componentElement->QueryFloatAttribute("w", &w);
	componentElement->QueryFloatAttribute("chest", &chest);
	componentElement->QueryFloatAttribute("leg", &leg);
	componentElement->QueryFloatAttribute("helmet", &helmet);
	componentElement->QueryFloatAttribute("arm", &arm);
	componentElement->QueryFloatAttribute("boots", &boot);
	wep = w;
	this->chest = chest;
	leggings = leg;
	this->helmet = helmet;
	guntlets = arm;
	this->boots = boot;
	if (wep != NULL)
	{
		updateStats();
	}
	this->factory = factory;
	this->battle = battle;
	this->overworld = overworld;
		updateStats();

		equipmentSlots[0][0].setAll(3, 3, 200, 200, false);
}

Equipment::~Equipment()
{

}

void Equipment::start()
{

}

GameObject* Equipment::update()
{
	if (equipmentOpen == true)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (equipmentSlots[i][j].isEquiped == true)
				{


					factory->createObject("20", 160 + 33 * equipmentSlots[i][j].row, 160 + 33 * equipmentSlots[i][j].col);
				}
			}
		}
	}
	if (equipmentOpen == true && createEquipment == true && timer <= 0)
	{
		int countRow = 0;
		int countCol = 0;
		for (int i = 160; i < factory->w - 160; i = i + 32)
		{
			i++;

			for (int j = 160; j < factory->h - 160; j = j + 32)
			{

				j++;
				factory->createObject("18", i, j);

				if (equipmentSlots[countRow][countCol].getEquipNum() !=0)
				{
					factory->createObject("19", i, j);

					factory->getQue()[factory->getQue().size() - 1]->getComponent<eFrame>()->setFrarmNum(equipmentSlots[countRow][countCol].getEquipNum());
					equipmentSlots[countRow][countCol].row = countRow;
					equipmentSlots[countRow][countCol].col = countCol;
				}

				countRow++;

			}
			countRow = 0;

			battle->equipmentOpen = true;
			overworld->equipmentOpen = true;
			this->equipmentOpen = true;
			countCol++;
		}
		createEquipment = false;
		timer = 10;

	}
	if (equipmentOpen == true)
	{
		factory->createObject("17", 160 + 33 * row, 160 + 33 * col);
	}
	if (equipmentOpen == false && timer <= 0 && createEquipment == true)
	{
		overworld->equipmentOpen = false;
		battle->equipmentOpen = false;
		this->equipmentOpen = false;
		createEquipment = false;
		timer = 10;
	}
	if (equipItem == true&& timer<=0)
	{
		equipSpace(row, col);
		timer = 10;
		
	}

	timer--;
	if (equipItem == true)
	{
		switch (chest)
		{
		case 3:
			factory->createObject("25", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Sprite>()->rect = getOwner()->getComponent<Sprite>()->rect;
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Follow>()->setId(getOwner()->primaryId);
			factory->createObject("26", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Sprite>()->rect = getOwner()->getComponent<Sprite>()->rect;
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Follow>()->setId(getOwner()->primaryId);
			break;
		}
		switch (guntlets)
		{
		case 7:
			factory->createObject("27", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Sprite>()->rect = getOwner()->getComponent<Sprite>()->rect;
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Follow>()->setId(getOwner()->primaryId);
			break;
		default:
			break;
		}
		switch (leggings)
		{
		case 6:
			factory->createObject("28", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Sprite>()->rect = getOwner()->getComponent<Sprite>()->rect;
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Follow>()->setId(getOwner()->primaryId);
			break;
		}
		switch (boots)
		{
		case 8:
			factory->createObject("29", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Sprite>()->rect = getOwner()->getComponent<Sprite>()->rect;
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Follow>()->setId(getOwner()->primaryId);
			break;
		}

		equipItem = false;
	}
	return nullptr;
}

	void Equipment::finish()
	{

	}

void Equipment::updateStats()
{
	//weapons
	
	switch (wep)
	{
	
		
	case 1:
	{
		Weapon* steelSword = new Weapon();
		steelSword->slashAttack = 60;
		steelSword->bluntAttack = 5;
		steelSword->TrustAttack = 60;
		steelSword->fireAttack = 0;
		steelSword->forstAttack = 0;
		steelSword->abssAttack = 0;
		steelSword->lightningAttack = 0;
		steelSword->holyAttack = 0;
		steelSword->durability = 200;
		steelSword->strRrq = 25;
		steelSword->dexRrq = 25;
		steelSword->intRrq = 0;
		steelSword->faithRrq = 0;

		weapon = steelSword;
	}
		break;
	case 2:
	{
		Weapon* crab = new Weapon();
		crab->slashAttack = 10;
		crab->bluntAttack = 5;
		crab->TrustAttack = 10;
		crab->fireAttack = 0;
		crab->forstAttack = 0;
		crab->abssAttack = 0;
		crab->lightningAttack = 0;
		crab->holyAttack = 0;
		crab->durability = 200;
		weapon = crab;
		break;
	}
	}

	switch (chest)
	{
	case 0:
	{
		Armor* none = new Armor();
		none->slashDef = 0;
		none->trustDef = 0;
		none->bluntDef = 0;
		none->fireDef = 0;
		none->forstDef = 0;
		none->lightningDef = 0;
		none->abssDef = 0;
		none->holyDef = 0;
		none->magicDef = 0;
		none->durability = 0;
		achest = none;
		break;
	}
	case 3:
	{
		Armor* steelChest = new Armor();
		steelChest->slashDef = 25;
		steelChest->trustDef = 20;
		steelChest->bluntDef = 25;
		steelChest->fireDef = 4;
		steelChest->forstDef = 10;
		steelChest->lightningDef = 3;
		steelChest->abssDef = 0;
		steelChest->holyDef = 0;
		steelChest->magicDef = 8;
		steelChest->durability = 200;
		achest = steelChest;
	}
		break;
	case 4:
	{
		Armor* crab = new Armor();
		crab->slashDef = 30;
		crab->trustDef = 0;
		crab->bluntDef = 50;
		crab->fireDef = 0;
		crab->lightningDef = 0;
		crab->forstDef = 0;
		crab->abssDef = 0;
		crab->holyDef = 0;
		crab->magicDef = 0;
		achest = crab;
		break;
	}

	}
	switch (helmet)
	{
	case 0:
	{
		Armor* none = new Armor();
		none->slashDef = 0;
		none->trustDef = 0;
		none->bluntDef = 0;
		none->fireDef = 0;
		none->forstDef = 0;
		none->lightningDef = 0;
		none->abssDef = 0;
		none->holyDef = 0;
		none->magicDef = 0;
		none->durability = 0;
		ahelmet = none;
		break;
	}
	case 5:
	{
		Armor* steelHelmet = new Armor();
		steelHelmet->slashDef = 5;
		steelHelmet->trustDef = 5;
		steelHelmet->bluntDef = 5;
		steelHelmet->fireDef = 4;
		steelHelmet->forstDef = 5;
		steelHelmet->lightningDef = 0;
		steelHelmet->abssDef = 0;
		steelHelmet->holyDef = 0;
		steelHelmet->magicDef = 8;
		steelHelmet->durability = equipmentSlots[row][col].getDuribility();
		steelHelmet->maxDurabilty = 200;
		ahelmet = steelHelmet;
		break;
	}
	}
	switch (leggings)
	{
	case 0:
	{
		Armor* none = new Armor();
		none->slashDef = 0;
		none->trustDef = 0;
		none->bluntDef = 0;
		none->fireDef = 0;
		none->forstDef = 0;
		none->lightningDef = 0;
		none->abssDef = 0;
		none->holyDef = 0;
		none->magicDef = 0;
		none->durability = 0;
		aleggings = none;
		break;
	}
	case 6:
	{
		Armor* steelLeggings = new Armor();
		steelLeggings->slashDef = 25;
		steelLeggings->trustDef = 20;
		steelLeggings->bluntDef = 25;
		steelLeggings->fireDef = 4;
		steelLeggings->forstDef = 10;
		steelLeggings->lightningDef = 0;
		steelLeggings->abssDef = 0;
		steelLeggings->holyDef = 0;
		steelLeggings->magicDef = 8;
		steelLeggings->durability = equipmentSlots[row][col].getDuribility();
		steelLeggings->maxDurabilty = 200;
		aleggings = steelLeggings;
		break;
	}
	}

	switch (guntlets)
	{
	case 0:
	{
		Armor* none = new Armor();
		none->slashDef = 0;
		none->trustDef = 0;
		none->bluntDef = 0;
		none->fireDef = 0;
		none->forstDef = 0;
		none->lightningDef = 0;
		none->abssDef = 0;
		none->holyDef = 0;
		none->magicDef = 0;
		none->durability = 0;
		aguntlets = none;
		break;
	}
	case 7:
	{
		Armor* steelGuntlets = new Armor();
		steelGuntlets->slashDef = 5;
		steelGuntlets->trustDef = 5;
		steelGuntlets->bluntDef = 5;
		steelGuntlets->fireDef = 4;
		steelGuntlets->forstDef = 5;
		steelGuntlets->lightningDef = 0;
		steelGuntlets->abssDef = 0;
		steelGuntlets->holyDef = 0;
		steelGuntlets->magicDef = 8;
		steelGuntlets->durability  = equipmentSlots[row][col].getDuribility();
		steelGuntlets->maxDurabilty = 200;
		aguntlets = steelGuntlets;
		break;
	}
	}

	switch (boots)
	{
	case 0:
	{
		Armor* none = new Armor();
		none->slashDef = 0;
		none->trustDef = 0;
		none->bluntDef = 0;
		none->fireDef = 0;
		none->forstDef = 0;
		none->lightningDef = 0;
		none->abssDef = 0;
		none->holyDef = 0;
		none->magicDef = 0;
		none->durability = 0;
		aboots = none;
	}
	case 8:
	{
		Armor* steelBoots = new Armor();
		steelBoots->slashDef = 5;
		steelBoots->trustDef = 5;
		steelBoots->bluntDef = 5;
		steelBoots->fireDef = 4;
		steelBoots->forstDef = 5;
		steelBoots->lightningDef = 0;
		steelBoots->abssDef = 0;
		steelBoots->holyDef = 0;
		steelBoots->magicDef = 8;
		steelBoots->durability = equipmentSlots[row][col].getDuribility();
		steelBoots->maxDurabilty = 200;
		aboots = steelBoots;
		break;
	}
	}

	Armor* tempArmor = new Armor();
	tempArmor->slashDef = achest->slashDef + aleggings->slashDef + ahelmet->slashDef + aguntlets->slashDef + aboots->slashDef;
	tempArmor->trustDef = achest->trustDef + aleggings->trustDef + ahelmet->trustDef + aguntlets->trustDef + aboots->trustDef;
	tempArmor->bluntDef = achest->bluntDef + aleggings->bluntDef + ahelmet->bluntDef + aguntlets->bluntDef + aboots->bluntDef;
	tempArmor->fireDef = achest->fireDef + aleggings->fireDef + ahelmet->fireDef + aguntlets->fireDef + aboots->fireDef;
	tempArmor->forstDef = achest->forstDef + aleggings->forstDef + ahelmet->forstDef + aguntlets->forstDef + aboots->forstDef;
	tempArmor->lightningDef = achest->lightningDef + aleggings->lightningDef + ahelmet->lightningDef + aguntlets->lightningDef + aboots->lightningDef;
	tempArmor->abssDef = achest->abssDef + aleggings->abssDef + ahelmet->abssDef + aguntlets->abssDef + aboots->abssDef;
	tempArmor->holyDef = achest->holyDef + aleggings->holyDef + ahelmet->holyDef + aguntlets->holyDef + aboots->holyDef;
	tempArmor->magicDef = achest->magicDef + aleggings->magicDef + ahelmet->magicDef + aguntlets->magicDef + aboots->magicDef;
	armor = tempArmor;
}

void Equipment::equipSpace(int row, int col)
{
	int equipType = equipmentSlots[row][col].getEquipType();
	if (equipmentSlots[row][col].isEquiped == false)
	{
		switch (equipType)
		{
		case 0:
			wep = equipmentSlots[row][col].getEquipNum();
			break;
		case 1:
			helmet = equipmentSlots[row][col].getEquipNum();
			break;
		case 2:
			guntlets = equipmentSlots[row][col].getEquipNum();
			break;
		case 3:
			chest = equipmentSlots[row][col].getEquipNum();
			break;
		case 4:
			leggings = equipmentSlots[row][col].getEquipNum();
			break;
		case 5:
			boots = equipmentSlots[row][col].getEquipNum();
			break;
		}
		equipmentSlots[row][col].isEquiped = true;
	}
	else
	{
		switch (equipType)
		{
		case 0:
			wep = 0;
			break;
		case 1:
			helmet = 0;
			break;
		case 2:
			guntlets = 0;
			break;
		case 3:
			chest = 0;
			break;
		case 4:
			leggings = 0;
			break;
		case 5:
			boots = 0;
			break;
			
		}
		equipmentSlots[row][col].isEquiped = false;
	}
	updateStats();
}