#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H
#include<string>
#include<memory>
#include<map>

struct SDL_Renderer;
class GraphicsDevice;
class Texture;

class TextureLibrary {
public:
	TextureLibrary(GraphicsDevice*);
	Texture* getArtAsset(std::string name);
	SDL_Renderer* getRenderer() { return renderer; };
	std::string imgPath = "Assets/Images/";

private:
	std::map<std::string, Texture*> artLibrary;
	GraphicsDevice* gDevice;
	SDL_Renderer* renderer;
};
#endif