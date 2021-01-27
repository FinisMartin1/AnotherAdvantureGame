#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Definitions.h"
class GraphicsDevice;
class Texture {

public:

	Texture() = delete;
	Texture(GraphicsDevice* gDevice, const std::string &path);
	~Texture();

	void draw(Vector2D* position, float angle = 0.0f, Vector2D* centerPoint = nullptr, SDL_Rect* clip = nullptr, int winW = 0, int winH = 0);
	void drawRec(float x, float y, float w, float h,int r,int g,int b);
	void setRGBA(RGBA);

	int width{ 0 };
	int height{ 0 };

	bool initialized{ false };

	void setWH(int w, int h);

	SDL_Texture* getTexture() { return sprite; };

private:
	//The actual hardware texture. created and destroyed by SDL
	SDL_Texture * sprite{ nullptr };

	GraphicsDevice* gDevice;
	SDL_Renderer* renderer;

};

#endif