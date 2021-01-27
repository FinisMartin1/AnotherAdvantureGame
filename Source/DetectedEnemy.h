#ifndef DETECTEDENEMY_H
#define DETECTEDENEMY_H
#include "Component.h"
#include "ObjectFactory.h"
#include "tinyxml2.h"
class DetectedEnemy:public Component
{
public:
	DetectedEnemy(GameObject* owner, tinyxml2::XMLElement* componentElement,Battle*battle,ObjectFactory*factory );
	~DetectedEnemy();


	void start();
	GameObject* update();
	void finish();

private:
	Battle* battle;
	ObjectFactory* factory;
};
#endif // !DETECTEDENEMY_H
