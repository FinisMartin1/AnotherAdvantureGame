#include"Container.h"
#include"GameObject.h"
#include"Frame.h"
#include"Clickable.h"
#include<fstream>

Container::Container(GameObject* owner, tinyxml2::XMLElement* componentElement, ObjectFactory* factory, Battle* battle, Overworld* overworld) :Component(owner)
{
	this->factory = factory;
	this->battle = battle;
	this->overworld = overworld;

}

Container::~Container()
{

}

void Container::start()
{

}

GameObject* Container::update()
{
	int countRow = 0;
	int countCol = 0;
	if (timer <= 0 && getOwner()->getComponent<Clickable>()->clickCheck())
	{
		if (contOpen == false)
		{
			contOpen = true;
			createCont = true;
		}
		else if (contOpen == true)
		{
			contOpen = false;
		}
	}
	if (createCont == true && timer <= 0 && contOpen == true)
	{


		for (int i = 160; i < factory->w - 160; i = i + 32)
		{
			i++;

			for (int j = 160; j < factory->h - 160; j = j + 32)
			{

				j++;
				factory->createObject("84", i, j);

				if (inventorySlots[countRow][countCol].getItemNum() != 0)
				{
					factory->createObject("83", i, j);

					factory->getQue()[factory->getQue().size() - 1]->getComponent<Frame>()->setFrarmNum(inventorySlots[countRow][countCol].getItemNum());
				}

				countRow++;

			}
			countRow = 0;
			overworld->contOpen = true;
			battle->contOpen = true;
			this->contOpen = true;
			countCol++;
		}
		createCont = false;
		timer = 30;

	}
	if (contOpen == true)
	{
		factory->createObject("85", 160 + 33 * row, 160 + 33 * col);
	}
	if (contOpen == false && timer <= 0 && createCont == true)
	{
		overworld->contOpen = false;
		battle->contOpen = false;
		this->contOpen = false;
		createCont = false;
		timer = 10;
	}


	timer--;
	return nullptr;
}

void Container::finish()
{

}

void Container::genContainer()
{
	ifstream file("./Assets/Containers/" + cont);
	int item, num;

	
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				file >> item >> num;
				if (!file.eof())
				{
					inventorySlots[i][j].setItemNum(item);
					inventorySlots[i][j].setAmount(num);
				}
				else
				{
					inventorySlots[i][j].setItemNum(0);
					inventorySlots[i][j].setAmount(0);
				}
			}
		}


}
void Container::changeContainer()
{
	ofstream file("./Assets/Containers/" + cont);
	int item, num;


	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			item = inventorySlots[i][j].getItemNum();
			num = inventorySlots[i][j].getAmount();
			file << item << num;

	

		}
	}
	file.close();
}