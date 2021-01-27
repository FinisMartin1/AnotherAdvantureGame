#ifndef OVERWORLD_H
#define OVERWORLD_H
#include <vector>
#include"GameObject.h"
using namespace std;
class Overworld
{
public:
	Overworld();
	~Overworld();
	vector<GameObject*> getEntitys() {
		return entitys;
	};
	void addEntity(GameObject* entity)
	{
		entitys.push_back(entity);
	}
	void clearEntitys()
	{
		entitys.clear();
	}
	GameObject* getPlayer();
	GameObject* getEntityById(string id);
	bool inventoryOpen = false;
	bool equipmentOpen = false;
	int time = 0;
	int timer = 0;
	int maxTime = 1800;
	int alpha = 0;
private:
	vector<GameObject*> entitys;


};
#endif // !OVERWORLD_H
