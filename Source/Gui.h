#ifndef GUI_H
#define GUI_H
#include "Component.h"
#include "tinyxml2.h"
#include "ObjectFactory.h"
#include"Battle.h"
#include "Texture.h"
#include "TextureLibrary.h"
class Gui :public Component
{
public:
	Gui(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory,Battle* battle);
	~Gui();

void updateBars();

void setHealth(int health)
{
	this->health = health;
}
void setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}
void createFrames();
void updateFrames();
void createBars();
void addToHealthBar(int health);
void subtractFromHealthBar(int health);
void subtractFromManaBar(int mana);
void subtractFromStanimaBar(int stanima);
void start();
GameObject* update();
void finish();
private:


	ObjectFactory* factory;
	Texture* texture;
	Battle* battle;
	int health;
	int maxHealth;
	int healthLoss;

	//bar colour
	int green;
	int black;
	int white;
};
#endif // !GUI_H

