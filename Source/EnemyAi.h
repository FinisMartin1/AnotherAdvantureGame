#ifndef ENEMYAI_H
#define ENEMYAI_H
#include"Component.h"
#include"Battle.h"
#include "tinyxml2.h"
class EnemyAi:public Component
{
public:
	EnemyAi(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~EnemyAi();
	void start();
	GameObject* update();
	void finish();
	void behaviorTree();
	void moveToPlayer();
	void changeAbilty();
	
	void getTarget();
private:
	Battle* battle;
	GameObject* target;
};

#endif