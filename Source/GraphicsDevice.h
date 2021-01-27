#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H
#include "Texture.h"
#include "SDL_ttf.h"
#include<assert.h>



using namespace std;

class GraphicsDevice
{

public:
	GraphicsDevice();
	~GraphicsDevice();
	int getWidth();
	int getHeight();

	SDL_Renderer* getRenderer();

	void begin();

	void present();

	int FPS = 60;

private:

	//
	// PRIVATE METHODS
	//
	void initGraphicsDevice(int width =800, int height = 800);
	SDL_GLContext context;
	SDL_Window* window;

	void cleanUp();

	//
	//PRIVATE MEMBERS
	//
	bool quit;

	int width = 640;
	int height = 320;

	//Window(s) to display graphics
	

	//Hardware accelerated renderer
	SDL_Renderer* renderer;
};
#endif