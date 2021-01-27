#ifndef INVENTORY_H
#define INVENTORY_H
#include"Component.h"
#include "tinyxml2.h"
#include"Battle.h"
#include"Overworld.h"
#include"ObjectFactory.h"
#include"PictureFrame.h"
#include"InvNode.h"
#include<vector>

using namespace std;
class Inventory :public Component
{
public:
	Inventory(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory ,Battle* battle, Overworld* overworld);
	~Inventory();

	void start();
	GameObject* update();
	void finish();
	bool createInventory = false;
	bool inventoryOpen = false;
	int getTimer() { return timer; };
	void setTimer(int timer) { this->timer = timer; };
	void useCurrentItem(int item);
	int currentSpace = 0;
	int row = 1;
	int col = 1;
	bool useItem = false;
	
	
private:

	InvNode inventorySlots[15][15];
	ObjectFactory* factory;
	Battle* battle;
	Overworld* overworld;
	int timer = 100;


};

#endif