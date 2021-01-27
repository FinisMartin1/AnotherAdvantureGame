#include "GameObject.h"
#include "Texture.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "RidgidBodyComponent.h"
#include "Stats.h"
#include "InputHandler.h"
#include"Text.h"
#include <chrono>
#include <random>


GameObject::GameObject()
{
	primaryId = id + id2 + createPrimaryID();

}

GameObject::~GameObject()
{
}

bool GameObject::initialize()
{
	//Call the start method

		initialized = true;


	return(initialized);
}

void GameObject::addComponent( Component* component)
{
	components.push_back(std::unique_ptr<Component>(component));
}

GameObject* GameObject::update()
{
	
		
	GameObject* newObject = nullptr;
	for (auto& component : components)
	{
		GameObject* tempObject = component->update();
		if (tempObject != nullptr && newObject==nullptr )
		{
			newObject = tempObject;
		}

	}
	if (id == "01")
	{
		isPlayer = true;
	}
	return this;
	}

void GameObject::draw()
{
	if (initialized) {
		Sprite* sprite = getComponent<Sprite>();
		if (sprite != nullptr)
		{
			sprite->draw();
		}
		if (id == "24")
		{
			getComponent<Text>()->update();
	}
	}
}
void GameObject::deleteSelf()
{
	delete this;
}
string GameObject::createPrimaryID()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(0.0, 9.0);
	int num;
	string tempId="";
	for (int i = 0; i < 4; i++)
	{
		num = distribution(generator);
		if (tempId == "")
		{
			tempId = to_string(num);
		}
		else
		{
			tempId = tempId+to_string(num);
		}
	}
	return tempId;
}

