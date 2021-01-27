#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Component.h"
#include "ObjectFactory.h"
#include "tinyxml2.h"
#include "EquipNode.h"
#include "ObjectFactory.h"
#include <string>

class Equipment:public Component
{
public:
	Equipment(GameObject* owner, tinyxml2::XMLElement* componentElement,Overworld* overworld,Battle* battle, ObjectFactory* factory);
	~Equipment();

	void start();
	GameObject* update();
	void finish();
	void updateStats();

	void setChangeEquip(bool changeEquip)
	{
		this->changeEquip = changeEquip;
	}

	Weapon* getWeapon()
	{
		return weapon;
	}
	Armor* getArmor()
	{
		return armor;
	}
	int getTimer() { return timer; };
	bool equipmentOpen = false;
	bool createEquipment = false;
	int row=0;
	int col=0;
	void setTimer(int timer)
	{
		this->timer = timer;
	}
	bool equipItem = true;
	void equipSpace(int row, int col);
private:
	bool changeEquip=false;

	int wep = 1;
	int helmet;
	int guntlets;
	int chest;
	int leggings;
	int boots;
	std::string weapon2="steelSheild";


	Weapon* weapon;
	Armor* armor;
	Armor* ahelmet;
	Armor* aguntlets;
	Armor* achest;
	Armor* aleggings;
	Armor* aboots;

	int timer = 100;
	EquipNode equipmentSlots[15][15];

	ObjectFactory* factory;
	Battle* battle;
	Overworld* overworld;
}; 

#endif