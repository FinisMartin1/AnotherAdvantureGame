#include"DialogNode.h"
DialogNode::DialogNode()
{

}
DialogNode::DialogNode(tinyxml2::XMLElement* obj)
{
	for (tinyxml2::XMLElement* child = obj->FirstChildElement("Speech"); child != NULL; child = child->NextSiblingElement())
	{
		if (child != nullptr)
		{
			children.push_back(new DialogNode(child));
		}
	}
	const char* tempString;
	obj->QueryStringAttribute("log", &tempString);
	dialog = tempString;
}

DialogNode::~DialogNode()
{

}
vector<DialogNode*> DialogNode::getDialogNodes()
{
	vector<DialogNode*> temp;
	if (wasSaid == false)
	{
		
		temp.push_back(this);
		return temp;
	}
	else if (wasSaid == true)
	{
		vector<DialogNode*> tempB;
		for (int i = 0; i < children.size() - 1; i++)
		{
			if (!children[i]->getDialogNodes().empty())
			{
				temp.reserve(children[i]->getDialogNodes().size() + temp.size());
				temp.insert(temp.end(), children[i]->getDialogNodes().begin(), children[i]->getDialogNodes().end());
			}
		}
	}
}

