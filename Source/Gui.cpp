#include"Gui.h"
#include"Stats.h"
#include"SpriteComponent.h"
#include"RidgidBodyComponent.h"
Gui::Gui(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory, Battle* battle) :Component(owner)
{
	
	this->battle = battle;
	this->factory=factory;
	
}

Gui::~Gui()
{

}
void Gui::start()
{

}
GameObject* Gui::update()
{
	if (battle->getPlayer() == getOwner() && getOwner()->id2 == "00")
	{
		createFrames();
	}

	createBars();
	return nullptr;
}

void Gui::finish()
{

}
void Gui::createBars()
{
	GameObject* tempbar=new GameObject();
	if (battle->getPlayer() == getOwner()&& getOwner()->id2=="00")
	{
		factory->createObject("05", 0, 0);
		for (int i = 0; i < factory->getQue().size(); i++)
		{
			if (factory->getQue()[i]->id == "05")
			{
				tempbar = factory->getQue()[i];
				int temp = getOwner()->getComponent<Stats>()->health / getOwner()->getComponent<Stats>()->m_health;
				temp = temp * 100;
				temp = temp * 2;
				tempbar->getComponent<Sprite>()->rect->w = temp;
				factory->getQue()[i] = tempbar;
				break;
			}
		}
		factory->createObject("08", 0, 16);
		for (int i = factory->getQue().size() - 1; i > 0; i--)
		{
			if (factory->getQue()[i]->id == "08")
			{
				tempbar = factory->getQue()[i];
				int temp = getOwner()->getComponent<Stats>()->mana / getOwner()->getComponent<Stats>()->m_mana;
				temp = temp * 100;
				temp = temp * 2;
				tempbar->getComponent<Sprite>()->rect->w = temp;
				factory->getQue()[i] = tempbar;
				break;
			}
		}
		factory->createObject("09", 0, 24);
		for (int i = factory->getQue().size() - 1; i > 0; i--)
		{
			if (factory->getQue()[i]->id == "09")
			{
				tempbar = factory->getQue()[i];
				int temp = getOwner()->getComponent<Stats>()->end / getOwner()->getComponent<Stats>()->m_end;
				temp = temp * 100;
				temp = temp * 2;
				tempbar->getComponent<Sprite>()->rect->w = temp;
				factory->getQue()[i] = tempbar;
				break;
			}
		}
	}
	else if(getOwner()->id2 == "01")
	{
		factory->createObject("06", getOwner()->getComponent<RidgidBody>()->position->x, getOwner()->getComponent<RidgidBody>()->position->y);
		for (int i = factory->getQue().size()-1; i > 0; i--)
		{
			if (factory->getQue()[i]->id == "06")
			{
				tempbar = factory->getQue()[i];
				int temp = getOwner()->getComponent<Stats>()->health / getOwner()->getComponent<Stats>()->m_health;
				temp = temp * 100;
				temp = temp / 2;

					tempbar->getComponent<Sprite>()->rect->w = temp;

				
				factory->getQue()[i] = tempbar;
				break;
			}
		}

	}
	
}

void Gui::subtractFromHealthBar(int health)
{
	GameObject* tempbar = new GameObject();
	int tempHealth = (getOwner()->getComponent<Stats>()->health) / getOwner()->getComponent<Stats>()->m_health;
	
	int healthRetactSize = health / getOwner()->getComponent<Stats>()->m_health;
	if (battle->getPlayer() == getOwner() && getOwner()->id2 == "00")
	{
		tempHealth = tempHealth * 100;
		healthRetactSize = healthRetactSize * 100;
		factory->createObject("07", tempHealth, 0);
		for (int i = factory->getQue().size() - 1; i > 0; i--)
		{
			if (factory->getQue()[i]->id == "07")
			{
				tempbar = factory->getQue()[i];

				tempbar->getComponent<Sprite>()->rect->w = healthRetactSize;
				factory->getQue()[i] = tempbar;
				break;
			}
		}

	}
	else if (getOwner()->id2 == "01")
	{

		tempHealth = tempHealth/2;
		healthRetactSize = healthRetactSize/2;
		factory->createObject("07", getOwner()->getComponent<RidgidBody>()->position->x+tempHealth, getOwner()->getComponent<RidgidBody>()->position->y);
		for (int i = factory->getQue().size() - 1; i > 0; i--)
		{
			if (factory->getQue()[i]->id == "07")
			{
				tempbar = factory->getQue()[i];

				tempbar->getComponent<Sprite>()->rect->w = healthRetactSize;
				factory->getQue()[i] = tempbar;
				break;
			}
		}

	}

}

void Gui::subtractFromManaBar(int mana)
{
	GameObject* tempbar = new GameObject();
	int tempMana = (getOwner()->getComponent<Stats>()->mana) / getOwner()->getComponent<Stats>()->m_mana;

	int healthRetactSize = mana / getOwner()->getComponent<Stats>()->m_mana;

	tempMana = tempMana * 100;
	healthRetactSize = healthRetactSize * 100;
	factory->createObject("10", tempMana, 16);
	for (int i = factory->getQue().size() - 1; i > 0; i--)
	{
		if (factory->getQue()[i]->id == "10")
		{
			tempbar = factory->getQue()[i];

			tempbar->getComponent<Sprite>()->rect->w = healthRetactSize;
			factory->getQue()[i] = tempbar;
			break;
		}
	}
}

void Gui::subtractFromStanimaBar(int stanima)
{
	GameObject* tempbar = new GameObject();
	int tempStanima = (getOwner()->getComponent<Stats>()->end) / getOwner()->getComponent<Stats>()->m_end;

	int healthRetactSize = stanima / getOwner()->getComponent<Stats>()->m_end;

	tempStanima = tempStanima * 100;
	healthRetactSize = healthRetactSize * 100;
	factory->createObject("10", tempStanima, 24);
	for (int i = factory->getQue().size() - 1; i > 0; i--)
	{
		if (factory->getQue()[i]->id == "10")
		{
			tempbar = factory->getQue()[i];

			tempbar->getComponent<Sprite>()->rect->w = healthRetactSize;
			factory->getQue()[i] = tempbar;
			break;
		}
	}
}

void Gui::createFrames()
{
	for (int i = 0; i < 12; i++)
	{
		factory->createObject("11", (32 * i), (320));
	}
}