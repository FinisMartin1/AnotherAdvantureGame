#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <map>

class InputHandler {
public:
	InputHandler();
	enum class Inputs
	{
		NA, FORWARD, LEFT, RIGHT, PRIMARY, MISSILE, PAUSE, QUIT, RELOAD, MAP,CLICK, ENDTURN,COMMAND,BACK,INVENTORY,USE,EQUIPMENT,J,L
	};

	void update(SDL_Event* event);
	std::map<Inputs, bool> keyStates;
	int mouseX;
	int mouseY;

};

#endif // !INPUTHANDLER_H
