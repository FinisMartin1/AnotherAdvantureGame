#include"Overworld.h"

Overworld::Overworld()
{

}

Overworld::~Overworld()
{

}

GameObject* Overworld::getEntityById(string id)
{
	for (int i = 0; i < entitys.size() - 1; i++)
	{
		if (id == entitys[i]->primaryId)
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
		if (entitys[i]->isPlayer == true)
		{
			return entitys[i];
		}

	}
	return nullptr;
}