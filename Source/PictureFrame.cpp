#include"PictureFrame.h"


PictureFrame::PictureFrame(GameObject* owner, tinyxml2::XMLElement* componentElement, Battle* battle) :Component(owner)
{
	this->battle = battle;
}

PictureFrame::~PictureFrame()
{

}

void PictureFrame::start()
{

}

GameObject* PictureFrame::update()
{

	return nullptr;
}

void PictureFrame::finish()
{

}