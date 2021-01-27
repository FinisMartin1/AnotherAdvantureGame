#ifndef VIEW_H
#define VIEW_H
#include "SDL.h"
#include "SDL_image.h"
#include "Definitions.h"
class View
{
public:
	View();
	~View();

	SDL_Rect* camera = new SDL_Rect();
	Vector2D* velocity = new Vector2D();
private:


};
#endif // !VIEW_H
