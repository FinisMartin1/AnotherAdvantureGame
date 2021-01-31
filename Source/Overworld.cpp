#include"Overworld.h"

Overworld::Overworld()
{

}

Overworld::~Overworld()
{

}

GameObject* Overworld::getEntityById(string id)
{
	for (int i = 0; i < entitys.size(); i++)
	{
		if (id == entitys[i]->id)
		{
			return entitys[i];
		}
		
	}
	return nullptr;
}

GameObject* Overworld::getPlayer()
{
	for (int i = 0; i < entitys.size(); i++)
	{


	}
	return nullptr;
}