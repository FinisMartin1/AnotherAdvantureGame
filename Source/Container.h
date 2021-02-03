#ifndef CONTAINER_H
#define CONTAINER_H

#include"Component.h"
#include "tinyxml2.h"
#include"Battle.h"
#include"Overworld.h"
#include"ObjectFactory.h"
#include"PictureFrame.h"
#include"InvNode.h"
#include<vector>

using namespace std;
class Container :public Component
{
public:
	Container(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory, Battle* battle, Overworld* overworld);
	~Container();

	void start();
	GameObject* update();
	void finish();
	bool createCont = false;
	bool contOpen = false;
	int getTimer() { return timer; };
	void setTimer(int timer) { this->timer = timer; };
	void useCurrentItem(int item);
	void genContainer();
	int currentSpace = 0;
	int row = 1;
	int col = 1;
	bool useItem = false;


private:

	InvNode inventorySlots[6][6];
	ObjectFactory* factory;
	Battle* battle;
	Overworld* overworld;
	int timer = 100;
	string cont = "";


};


#endif // !CONTAINER_H
