#ifndef DIALOG_H
#define DIALOG_H
#include"Component.h"
#include "tinyxml2.h"
#include"DialogNode.h"
#include"ObjectFactory.h"
#include<string>
using namespace std;
class Dialog :public Component
{
public:
	Dialog(GameObject* owner, tinyxml2::XMLElement* componentElement,ObjectFactory* factory);
	~Dialog();
	void start();
	GameObject* update();
	void finish();
	vector<DialogNode*> getDialogOptions() { return dialogOptions; };
	bool getIsTalking() { return isTalking; };
	
	int slected = 0;
private:
	ObjectFactory* factory;
	DialogNode* tree = new DialogNode();
	string xmlPath = "./Assets/Config/dialog.xml";
	vector<DialogNode*> dialogOptions;
	bool isTalking = false;
	
};
#endif
