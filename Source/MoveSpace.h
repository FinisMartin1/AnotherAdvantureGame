#ifndef MOVESPACE_H
#define MOVESPECE_H
#include"Component.h"
#include"Battle.h"
#include"ObjectFactory.h"
#include "tinyxml2.h"
class MoveSpace :public Component
{
public:
	MoveSpace(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, ObjectFactory* factory);
	~MoveSpace();
	void start();
	GameObject* update();
	void finish();
	void createMovementSpace(int moveNum);
	void getMoveSpaces();
	void caculateMoves();
	vector<GameObject*> getSpaces() { return spaces; };
	void getCurrentSpace();
private:
	vector<GameObject*> spaces;
	GameObject* currentSpace;
	bool create = false;
	Battle* battle;
	ObjectFactory* factory;


};
#endif