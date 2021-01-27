#include"Node.h"


Node::Node(Vector2D startPos, Vector2D endPos, Vector2D currentPos)
{
	g=sqrt(pow((startPos.x - currentPos.x), 2) + pow((startPos.y - currentPos.y),2));
	h= sqrt(pow((endPos.x - currentPos.x), 2) + pow((endPos.y - currentPos.y), 2));
	f = g + h;
	position = currentPos;
}

Node* Node::getRoot()
{
	Node* temp;
	if (parent->parent == nullptr)
	{
		return this;
	}
	else
	{
		temp=parent->getRoot();
	}

	return temp;
}