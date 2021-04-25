#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H
#include "ObjectFactory.h"
#include "View.h"
class LevelEditor
{
public:
	LevelEditor(View* view);
	~LevelEditor();

	void createMap(int width, int height);

	void setWidth(int width)
	{
		this->width = width;
	}
	void setHeight(int height)
	{
		this->height = height;
	}
	std::string getBurshType()
	{
		return brushType;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
	int getBrushX()
	{
		return brushX;
	}
	int getBrushY()
	{
		return brushY;
	}
	void changeBrushType(string type)
	{
		brushType = type;
	}
	void setFactory(ObjectFactory* factory)
	{
		this->factory = factory;
	}
	void setBrushX(int brushX)
	{
		this->brushX = brushX;
	}
	void setBrushY(int brushY)
	{
		this->brushY = brushY;
	}
	void saveLevel(vector<GameObject*> objects);
	void loadLevel(string level);
	void playLevel(string level);
	bool isLevelEditor = false;
	string getBrush() { return brushType; };
	bool getIsEditor() { return isEditor; };

private:
	int width;
	int height;
	ObjectFactory* factory;
	View* view;
	std::string brushType = "13";
	int brushX;
	int brushY;
	bool isEditor=false;

};
#endif // !LEVELEDITOR_H
