#include"Pathfinding.h"
#include "PhysicsDevice.h"
#include"RidgidBodyComponent.h"
#include"GameObject.h"
#include <chrono>
#include <random>
PathFinder::PathFinder(GameObject* owner, tinyxml2::XMLElement* componentElement, PhysicsDevice* physics) :Component(owner)
{
	createRandomTime();
	timer = wanderTimerMax;
}

PathFinder::~PathFinder()
{

}

void PathFinder::start()
{

}

GameObject* PathFinder::update()
{
	RidgidBody* body = getOwner()->getComponent<RidgidBody>();
	startPos.x = body->position->x;
	startPos.y = body->position->y;
	createNode(nullptr, startPos);
	activateNode(nodes[0]);
	bool foundEnd = false;
	if (checkEnd(activeNodes[activeNodes.size() - 1]->position))
	{
		endPos.x = NULL;
		endPos.y = NULL;
		

	}


	if (endPos.x!=NULL&&endPos.y!=NULL)
	{

	while (!foundEnd)
	{
		bubblesort();

		activateNode(nodes[0]);
		foundEnd = checkEnd(activeNodes[activeNodes.size() - 1]->position);
		if (activeNodes.size() == 100)
		{
			foundEnd = true;
			endPos.x = NULL;
			endPos.y = NULL;
		}
			

	}
	if (activeNodes[activeNodes.size() - 1]->parent != nullptr)
	{
		moveToNode(activeNodes[activeNodes.size() - 1]->getRoot());
	}
}
	if (endPos.x == NULL && endPos.y == NULL && wander == true&& timer>=wanderTimerMax)
	{
		createEndPos();
		createRandomTime();
		timer = 0;
	}
	else
	{
		timer++;
	}
		nodes.clear();
		activeNodes.clear();
	
	return nullptr;
}

void PathFinder::finish()
{

}
bool PathFinder::checkSpace(Vector2D position)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (position.x <= nodes[i]->position.x && (position.x+32)>nodes[i]->position.x && position.y <= nodes[i]->position.y && (position.y+32) >nodes[i]->position.y)
		{
			return true;
		}
	}

	for (int i = 0; i < activeNodes.size(); i++)
	{
		if (position.x <= activeNodes[i]->position.x && (position.x + 32)>activeNodes[i]->position.x && position.y <= activeNodes[i]->position.y && (position.y + 32) >activeNodes[i]->position.y)
		{
			return true;
		}
	}
	return false;
}
void PathFinder::createNode(Node* parent, Vector2D position)
{
	Node* node = new Node(startPos, endPos, position);
	node->parent = parent;
	nodes.push_back(node);
}
void PathFinder::activateNode(Node* node)
{
	activeNodes.push_back(node);
	nodes.erase(nodes.begin());
	if (!checkSpace(Vector2D{ node->position.x,node->position.y }))
	{
		createNode(node, Vector2D{ node->position.x,node->position.y });
	}
	if (!checkSpace(Vector2D{ node->position.x + 32,node->position.y }))
	{
		createNode(node, Vector2D{ node->position.x + 32,node->position.y });
	}
	if (!checkSpace(Vector2D{ node->position.x - 32,node->position.y }))
	{
		createNode(node, Vector2D{ node->position.x - 32,node->position.y });
	}
	if (!checkSpace(Vector2D{ node->position.x,node->position.y+32 }))
	{
		createNode(node, Vector2D{ node->position.x,node->position.y+32 });
	}
	if (!checkSpace(Vector2D{ node->position.x,node->position.y - 32 }))
	{
		createNode(node, Vector2D{ node->position.x,node->position.y - 32 });
	}
	if (!checkSpace(Vector2D{ node->position.x+32,node->position.y + 32 }))
	{
		createNode(node, Vector2D{ node->position.x+32,node->position.y + 32 });
	}
	if (!checkSpace(Vector2D{ node->position.x-32,node->position.y - 32 }))
	{
		createNode(node, Vector2D{ node->position.x-32,node->position.y + 32 });
	}
	if (!checkSpace(Vector2D{ node->position.x-32,node->position.y + 32 }))
	{
		createNode(node, Vector2D{ node->position.x-32,node->position.y + 32 });
	}
	if (!checkSpace(Vector2D{ node->position.x+32,node->position.y -32 }))
	{
		createNode(node, Vector2D{ node->position.x+32,node->position.y - 32 });
	}
}

void PathFinder::bubblesort()
{
	int i, j;
	for (i = 0; i < nodes.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < nodes.size() - i - 1; j++)
			if (nodes[j]->f > nodes[j + 1]->f)
				swap(j, j + 1);
}
void PathFinder::swap(int i, int j)
{

	Node* temp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = temp;
}
bool PathFinder::checkEnd(Vector2D position)
{
	if (endPos.x<=position.x && (endPos.x + 32)>position.x && endPos.y<=position.y && (endPos.y + 32)>position.y)
	{
		return true;
	}
	return false;
}

void PathFinder::moveToNode(Node* node)
{
	if (getOwner()->getComponent<RidgidBody>()->position->x > node->position.x)
	{
		getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ -0.5,0 });
	}
	if (getOwner()->getComponent<RidgidBody>()->position->x < node->position.x)
	{
		getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 0.5,0 });
	}
	if (getOwner()->getComponent<RidgidBody>()->position->y > node->position.y)
	{
		getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 0,-0.5});
	}
	if (getOwner()->getComponent<RidgidBody>()->position->y < node->position.y)
	{
		getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 0,0.5 });
	}
}

void PathFinder::createEndPos()
{
	float xMax = getOwner()->getComponent<RidgidBody>()->position->x + 120;
	float xMin = getOwner()->getComponent<RidgidBody>()->position->x - 120;
	float yMax = getOwner()->getComponent<RidgidBody>()->position->y + 120;
	float yMin = getOwner()->getComponent<RidgidBody>()->position->y - 120;
	float x;
	float y;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(xMin, xMax);
	endPos.x = distribution(generator);

	endPos.y= distribution(generator);
}

void PathFinder::createRandomTime()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(0, 500);
	wanderTimerMax= distribution(generator);
}