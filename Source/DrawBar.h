#ifndef DRAWBAR_h
#define DRAWBAR_h
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"
class DrawBar:public Component
{
public:
	DrawBar(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~DrawBar();

	void start();
	GameObject* update();
	void finish();
private:
	Battle* battle;
	int deleteType;
	GameObject* player;

};
#endif // !DrawBar.h

