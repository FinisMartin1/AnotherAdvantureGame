#ifndef STATS_H
#define STATS_H
#include "Component.h"
#include "tinyxml2.h"
#include"Battle.h"
#include"Overworld.h"
class Stats :public Component
{
public:
	Stats(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle* battle,Overworld* overworld);
	~Stats();

	void start();
	GameObject* update();
	void finish();
	void caculateStats();
	void checKVisibility();
	int getMoveSpace()
	{
		return movementSpaces;
	};
	int getMaxMoveSpace() { return m_MovementSpaces; };
	void setMaxMoveSpace(int movespace) { m_MovementSpaces = movespace; };
	int getHealth()
	{
		return health;
	};
	int getAtt()
	{
		return att;
	};
	void setHealth(int health)
	{
		this->health = health;
	};
	float getCriticalRate()
	{
		return criticalRate;
	};

	float getCritDamage() { return critDamage; };
	int getEvvasion() { return evvasion; };
	int getAccracy() { return accracy; };
	int getSpeed() { return speed; };
	int level;
	//main stats
	float vatality;
	float attunment;
	float endurance;
	float strength;
	float dex;
	float intellegance;
	float faith;
	float perception;
	float agility;
	float luck;

	//modifiable stats
	int health;
	int m_health;
	int m_end;
	int end;
	int att;
	int mana;
	int m_mana;
	int sneak;
	//un-modifiable stats
	int Max_MovementSpaces;
	int m_MovementSpaces;
	int movementSpaces;
	float criticalRate;
	float critDamage;
	int accracy;
	int evvasion;
	int speed;
	int visibility = 100;
	vector<GameObject*> visibleObjects;
	//defenceStats

private:
	Battle* battle;
	Overworld* overworld;

};
#endif // !STATS_H
