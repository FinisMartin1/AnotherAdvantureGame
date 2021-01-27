#ifndef SPRITE_H
#define SPRITE_H
#include<vector>

#include "Component.h"
#include "SDL.h"
#include "SDL_image.h"
#include "tinyxml2.h"
class GameObject;
class TextureLibrary;
class Texture;
class ObjectTemplate;

struct Vector2D;


using namespace std;

class Sprite : public Component
{
public:
	Sprite(GameObject* owner, tinyxml2::XMLElement* componentElement, TextureLibrary* library);
	~Sprite();
	void initialize(TextureLibrary* library, ObjectTemplate* temp);

	void start();
	GameObject* update();
	void finish();

	void draw();

	void setTexture(string* path);
	string getPath();
	Texture* getTexture() { return texture; };

	
	struct SDL_Rect* rect = new SDL_Rect();
	Vector2D* size = new Vector2D();

	void changeAlpha(int alpha);
protected:
	int frameX = 1;
	int timer = 10;
	Vector2D* sposition=new Vector2D();
	
	Vector2D* scenter=new Vector2D();
	Texture* texture;
	Texture* texture2;
	int mouseX;
	int mouseY;
	float angle;
	bool ready{ false };

	TextureLibrary* library;
	string path;
	string path2;

	RGBA color;
};


#endif