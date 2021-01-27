#ifndef PATHFINDING_H
#define PATHFINDING_H
#include"Component.h"
#include "tinyxml2.h"
#include "Node.h"
#include <vector>
class PhysicsDevice;
using namespace std;

class PathFinder :public Component
{
public:
	PathFinder(GameObject* owner, tinyxml2::XMLElement* componentElement,PhysicsDevice* physics);
	~PathFinder();

	void start();
	GameObject* update();
	void finish();

	void activateNode(Node* node);
	void createNode(Node* parent, Vector2D position);
	bool checkSpace(Vector2D position);
	void swap(int i, int j);
	void bubblesort();
	void moveToNode(Node* node);
	bool checkEnd(Vector2D position);
	bool wander = true;
	void createEndPos();
	void createRandomTime();
	
private:
	Vector2D startPos;
	Vector2D endPos = Vector2D{ NULL,NULL };
	vector<Node*> nodes;
	vector<Node*>activeNodes;
	bool active = false;
	int wanderTimerMax = 500;
	int timer = 500;
	

};
#endif