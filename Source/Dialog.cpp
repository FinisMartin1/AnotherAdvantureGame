#include"Dialog.h"
#include"DialogNode.h"
#include"GameObject.h"
#include"Text.h"
Dialog::Dialog(GameObject* owner, tinyxml2::XMLElement* componentElement,ObjectFactory* factory) :Component(owner)
{
	const char* npcName;
	componentElement->QueryStringAttribute("log",&npcName);
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(xmlPath.c_str()) != tinyxml2::XML_SUCCESS) {
		printf("Bad File Path");
		exit(1);
	}
	tinyxml2::XMLElement* root = doc.FirstChildElement("dialog");

	for (tinyxml2::XMLElement* obj = root->FirstChildElement("DialogTree"); obj != NULL; obj = obj->NextSiblingElement())
	{
		const char* name;
		string tempName;
		obj->QueryStringAttribute("name", &name);
		tempName = name;
		if (npcName==tempName)
		{
			tinyxml2::XMLElement* child = obj->FirstChildElement("Speech");
			
			DialogNode* tempTree =new DialogNode(child);
			tree = tempTree;
		}
	}

	this->factory = factory;
}

Dialog::~Dialog()
{

}

void Dialog::start()
{

}

GameObject* Dialog::update()
{
	if (isTalking == true)
	{
		factory->createObject("22", 0 + 100, 0 + 540);

		
		dialogOptions.clear();
		dialogOptions.reserve(dialogOptions.size() + tree->getDialogNodes().size());
		for (int i = 0; i < tree->getDialogNodes().size(); i++)
		{
			dialogOptions.push_back(tree->getDialogNodes()[i]);
		}
		for (int i = 0; i < dialogOptions.size(); i++)
		{
			factory->createObject("23", 0 + 292, 0 + 540*(64*i+1));
			factory->createObject("24", 0 + 292, 0 + 540*(64 * i + 1));
			factory->getQue()[factory->getQue().size() - 1]->getComponent<Text>()->setText(dialogOptions[i]->getString());
		}
	}
	return nullptr;
}

void Dialog::finish()
{

}