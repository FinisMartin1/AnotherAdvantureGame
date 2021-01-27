
#ifndef INPUT_H
#define INPUT_H
#include "Component.h"
#include "InputHandler.h"
#include "tinyxml2.h"
#include "Battle.h"

#include <string>
#include <memory>


class UserInput : public Component {
public:
	UserInput(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle, InputHandler* input);
	~UserInput();

	

	void start();
	void finish();
	GameObject* update();

	

private:
	bool isPlayer;
	InputHandler* input;
	Battle* battle;
	

};

#endif // !USERINPUTCOMPONENT_H