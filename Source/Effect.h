#ifndef EFFECT_H
#define EFFECT_H
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"

class Effect:public Component
{
public:
	Effect(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~Effect();
	void start();
	GameObject* update();
	void finish();
	void addBuff(int effect,int turns, int chance);
	void endBuff(int effect);
	
	bool myTurn = false;
private:
	vector<int> turnCounter;
	vector<int> activeBuffs;
	Battle* battle;
	
};
#endif // !

