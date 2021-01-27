#ifndef ABILTY_H
#define ABILITY_H
#include"Component.h"
#include"Battle.h"
#include"ObjectFactory.h"
#include "tinyxml2.h"
class Ability :public Component
{
public:
	Ability(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle,InputHandler* input, ObjectFactory* factory);
	~Ability();
	void start();
	GameObject* update();
	void finish();
	void setCurrentAbility(int skill) { currentAbility = skill; };
	int getCurrentAbility() { return currentAbility; };
	vector<int> getSkillList() { return skills; };
private:
	vector<int> skills;
	int currentAbility;
	Battle* battle;
	ObjectFactory* factory;
	InputHandler* input;
};
#endif // !ABILTY_H

