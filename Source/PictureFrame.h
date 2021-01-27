#ifndef PICTUREFRAME_H
#define PICTUREFRAME_H
#include "Component.h"
#include "tinyxml2.h"
#include "Battle.h"

class PictureFrame :public Component
{
public:
	PictureFrame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle);
	~PictureFrame();

	void start();
	GameObject* update();
	void finish();

private:
	int pictureNum;
	Battle* battle;
};

#endif // !PICTUREFRAME_H
