#include"input.h"
#include"Stats.h"
#include"RidgidBodyComponent.h"
#include"Inventory.h"
#include"Equipment.h"
#include"Dialog.h"
#include<iostream>
#include"Container.h"
UserInput::UserInput(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, InputHandler* input):Component(owner)
{
	this->input = input;
	this->battle = battle;
	bool player;
	componentElement->QueryBoolAttribute("isPlayer", &player);
	isPlayer = player;
}


UserInput::~UserInput()
{

}

void UserInput::start()
{

}

GameObject* UserInput::update()
{
	if (isPlayer == true)
	{

		if (input->keyStates[InputHandler::Inputs::ENDTURN] == true)
		{
			input->keyStates[InputHandler::Inputs::ENDTURN] = false;
			battle->nextTurn();

		}
		if (input->keyStates[InputHandler::Inputs::FORWARD] == false && input->keyStates[InputHandler::Inputs::BACK] == false && input->keyStates[InputHandler::Inputs::RIGHT] == false && input->keyStates[InputHandler::Inputs::LEFT] == false)
		{
			getOwner()->prevDir = getOwner()->currentDir;
			getOwner()->currentDir = getOwner()->NA;
		}
		if (input->keyStates[InputHandler::Inputs::FORWARD] == true)
		{
			if (getOwner()->getComponent<Inventory>()->inventoryOpen == false && getOwner()->getComponent<Equipment>()->equipmentOpen == false)
			{
				getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 0,-2 });
				getOwner()->currentDir = getOwner()->UP;
			}
			else if (getOwner()->getComponent<Inventory>()->getTimer() <= 0 && getOwner()->getComponent<Inventory>()->inventoryOpen == true)
			{
				getOwner()->getComponent<Inventory>()->currentSpace - 15;
				getOwner()->getComponent<Inventory>()->col--;
				getOwner()->getComponent<Inventory>()->setTimer(10);
			}
			else if (getOwner()->getComponent<Equipment>()->getTimer() <= 0 && getOwner()->getComponent<Equipment>()->equipmentOpen == true)
			{

				getOwner()->getComponent<Equipment>()->col--;
				getOwner()->getComponent<Equipment>()->setTimer(10);
			}
			if (getOwner()->getComponent<Equipment>()->col < 0)
			{

				getOwner()->getComponent<Equipment>()->col++;
				getOwner()->getComponent<Equipment>()->setTimer(10);
			}
		}
		if (input->keyStates[InputHandler::Inputs::LEFT] == true)
		{

			if (getOwner()->getComponent<Inventory>()->inventoryOpen == false && getOwner()->getComponent<Equipment>()->equipmentOpen == false)
			{
				getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ -2,0 });
				getOwner()->currentDir = getOwner()->LEFT;
			}
			else if (getOwner()->getComponent<Inventory>()->getTimer() <= 0 && getOwner()->getComponent<Inventory>()->inventoryOpen == true)
			{
				getOwner()->getComponent<Inventory>()->currentSpace - 1;
				getOwner()->getComponent<Inventory>()->row--;
				getOwner()->getComponent<Inventory>()->setTimer(10);
			}
			else if (getOwner()->getComponent<Equipment>()->getTimer() <= 0 && getOwner()->getComponent<Equipment>()->equipmentOpen == true)
			{

				getOwner()->getComponent<Equipment>()->row--;
				getOwner()->getComponent< Equipment>()->setTimer(10);
			}
			if (getOwner()->getComponent<Inventory>()->row < 0)
			{
				getOwner()->getComponent<Inventory>()->currentSpace + 1;
				getOwner()->getComponent<Inventory>()->row++;
			}
			if (getOwner()->getComponent<Equipment>()->row < 0)
			{

				getOwner()->getComponent<Equipment>()->row++;
			}
		}
		if (input->keyStates[InputHandler::Inputs::RIGHT] == true)
		{
			if (getOwner()->getComponent<Inventory>()->inventoryOpen == false && getOwner()->getComponent<Equipment>()->equipmentOpen == false)
			{
				getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 2,0 });
				getOwner()->currentDir = getOwner()->RIGHT;
			}
			else if (getOwner()->getComponent<Inventory>()->getTimer() <= 0 && getOwner()->getComponent<Inventory>()->inventoryOpen == true)
			{
				getOwner()->getComponent<Inventory>()->currentSpace + 1;
				getOwner()->getComponent<Inventory>()->row++;
				getOwner()->getComponent<Inventory>()->setTimer(10);
			}
			else if (getOwner()->getComponent<Equipment>()->getTimer() <= 0 && getOwner()->getComponent<Equipment>()->equipmentOpen == true)
			{
				getOwner()->getComponent<Equipment>()->row++;
				getOwner()->getComponent<Equipment>()->setTimer(10);
			}
			if (getOwner()->getComponent<Inventory>()->row > 15)
			{
				getOwner()->getComponent<Inventory>()->currentSpace - 1;
				getOwner()->getComponent<Inventory>()->row--;
			}
			if (getOwner()->getComponent<Equipment>()->row > 15)
			{

				getOwner()->getComponent<Equipment>()->row--;
			}
		}
		if (input->keyStates[InputHandler::Inputs::BACK] == true)
		{
			if (getOwner()->getComponent<Inventory>()->inventoryOpen == false && getOwner()->getComponent<Equipment>()->equipmentOpen == false)
			{
				getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 0,2 });
				getOwner()->currentDir = getOwner()->DOWN;
			}
			else if (getOwner()->getComponent<Inventory>()->getTimer() <= 0 && getOwner()->getComponent<Inventory>()->inventoryOpen == true)
			{
				getOwner()->getComponent<Inventory>()->currentSpace + 15;
				getOwner()->getComponent<Inventory>()->col++;
				getOwner()->getComponent<Inventory>()->setTimer(10);
			}
			else if (getOwner()->getComponent<Equipment>()->getTimer() <= 0 && getOwner()->getComponent<Equipment>()->equipmentOpen == true)
			{

				getOwner()->getComponent<Equipment>()->col++;
				getOwner()->getComponent<Equipment>()->setTimer(10);
			}

			if (getOwner()->getComponent<Equipment>()->col > 15)
			{

				getOwner()->getComponent<Equipment>()->col--;
			}
		}
		if (input->keyStates[InputHandler::Inputs::RIGHT] == true && input->keyStates[InputHandler::Inputs::BACK] == true)
		{
			getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 2,2 });
			getOwner()->currentDir = getOwner()->DOWNRIGHT;
		}
		if (input->keyStates[InputHandler::Inputs::BACK] == true && input->keyStates[InputHandler::Inputs::LEFT] == true)
		{
			getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ -2,2 });
			getOwner()->currentDir = getOwner()->DOWNLEFT;
		}
		if (input->keyStates[InputHandler::Inputs::FORWARD] == true && input->keyStates[InputHandler::Inputs::LEFT] == true)
		{
			getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ -2,-2 });
			getOwner()->currentDir = getOwner()->UPLEFT;
		}
		if (input->keyStates[InputHandler::Inputs::FORWARD] == true && input->keyStates[InputHandler::Inputs::RIGHT] == true)
		{
			getOwner()->getComponent<RidgidBody>()->setLinearVelocity(Vector2D{ 2,-2 });
			getOwner()->currentDir = getOwner()->UPRIGHT;
		}

		if (input->keyStates[InputHandler::Inputs::INVENTORY] == true)
		{
			if (getOwner()->getComponent<Inventory>()->createInventory == false && getOwner()->getComponent<Inventory>()->inventoryOpen == false && getOwner()->getComponent<Inventory>()->getTimer() <= 0)
			{
				getOwner()->getComponent<Inventory>()->createInventory = true;
				getOwner()->getComponent<Inventory>()->inventoryOpen = true;
			}
			else if (getOwner()->getComponent<Inventory>()->createInventory == false && getOwner()->getComponent<Inventory>()->inventoryOpen == true && getOwner()->getComponent<Inventory>()->getTimer() <= 0)
			{
				getOwner()->getComponent<Inventory>()->inventoryOpen = false;
				getOwner()->getComponent<Inventory>()->createInventory = true;
			}
		}
		if (input->keyStates[InputHandler::Inputs::USE] == true && getOwner()->getComponent<Inventory>()->getTimer() <= 0 && getOwner()->getComponent<Inventory>()->inventoryOpen == true)
		{
			getOwner()->getComponent<Inventory>()->useItem = true;
			battle->createInventory = true;
			getOwner()->getComponent<Inventory>()->createInventory = true;
		}
		if (input->keyStates[InputHandler::Inputs::USE] == true && getOwner()->getComponent<Equipment>()->getTimer() <= 0 && getOwner()->getComponent<Equipment>()->equipmentOpen == true)
		{
			getOwner()->getComponent<Equipment>()->equipItem = true;
		}
		if (input->keyStates[InputHandler::Inputs::EQUIPMENT] == true && getOwner()->getComponent<Equipment>()->getTimer() <= 0)
		{
			getOwner()->getComponent<Equipment>()->equipmentOpen = true;
			getOwner()->getComponent<Equipment>()->createEquipment = true;
		}
		if (input->keyStates[InputHandler::Inputs::USE] == true)
		{

			if (getOwner()->currentDir == getOwner()->DOWN)
			{

			}
		}
	}
	if (isPlayer == false && getOwner()->id!="82")
	{
		if (getOwner()->getComponent<Dialog>()->getIsTalking())
		{
			if (input->keyStates[InputHandler::Inputs::FORWARD] == true)
			{
				getOwner()->getComponent<Dialog>()->slected - 1;
			}
			if (input->keyStates[InputHandler::Inputs::BACK] == true)
			{
				getOwner()->getComponent<Dialog>()->slected +1;
			}
			if (getOwner()->getComponent<Dialog>()->slected < 0)
			{
				getOwner()->getComponent<Dialog>()->slected + 1;
			}
			if (getOwner()->getComponent<Dialog>()->slected > getOwner()->getComponent<Dialog>()->getDialogOptions().size() - 1)
			{
				getOwner()->getComponent<Dialog>()->slected - 1;
			}
		}
	}
	if (getOwner()->id == "82")
	{
		if (input->keyStates[InputHandler::Inputs::EXIT] == true)
		{
			if (getOwner()->getComponent<Container>()->getTimer() <= 0)
			{
				getOwner()->getComponent<Container>()->contOpen = false;
				getOwner()->getComponent<Container>()->createCont = true;
				getOwner()->getComponent<Container>()->changeContainer();
			}
		}
	}

	
	return nullptr;
}

void UserInput::finish()
{

}