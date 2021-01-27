#ifndef NODE_H
#define NODE_H
#include "Definitions.h"
#include <vector>
using namespace std;
class Node
{
public:
	Node(Vector2D startPos, Vector2D endPos, Vector2D currentPos);
	Node* getRoot();
	float g;
	float h;
	float f;
	Node* parent;
	Vector2D position;
   
private:

};

#endif