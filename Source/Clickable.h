#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "Component.h"
#include "tinyxml2.h"
#include "InputHandler.h"
class GameObject;
class GameLibrary;
class Texture;
struct SDL_Renderer;

class Clickable :public Component
{
public:
	Clickable(GameObject* owner, tinyxml2::XMLElement* componentElement, InputHandler *input);
	~Clickable();
	void start();
	GameObject*update();
	void finish();
	bool clickCheck() { return clicked; };
	int mouseX;
	int mouseY;
 
protected:
	InputHandler *input;
	bool clicked = false;

};
#endif // !1
