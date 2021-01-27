#ifndef FACTION_H
#define FACTION_H
#include "Component.h"
#include "tinyxml2.h"
#include <vector>
#include "Battle.h"
using namespace std;
class Faction :public Component
{
public:
	Faction(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle* battle);
	~Faction();

	void start();
	GameObject* update();
	void finish();

	int faction;
	vector<int> alliesFactions;
	vector<int> enemyFaction;
private:
	Battle* battle;
};
#endif // !FACTION_H

