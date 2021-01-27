#ifndef TEXT_H
#define TEXT_H
#include"Component.h"
#include "tinyxml2.h"
#include"TextureLibrary.h"
#include"SDL_ttf.h"
#include <string>
using namespace std;
class Text :public Component
{
public:
	Text(GameObject* owner, tinyxml2::XMLElement* componentElement, TextureLibrary* library);
	~Text();
	void start();
	GameObject* update();
	void finish();
	void setText(string text) { this->text = text; };
private:
	string text = "hello";
	string fontPath = "./Assets/Fonts/";
	TextureLibrary* library;
};
#endif