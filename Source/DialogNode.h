#ifndef DIALOGNODE_H
#define DIALOGNODE_H
#include<string>
#include<vector>
#include "tinyxml2.h"
using namespace std;
class DialogNode
{
public:
	DialogNode();
	DialogNode(tinyxml2::XMLElement* obj);
	~DialogNode();
	vector<DialogNode*> getDialogNodes();
	
	string	getString() {
		return dialog;
	};
	bool wasSaid = false;
private:
	
	string dialog;
	vector<DialogNode*> children;
};
#endif