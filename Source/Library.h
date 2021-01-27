#ifndef LIBRARY_H
#define LIBRARY_H
#include<string>
#include<vector>
#include"ObjectFactory.h"
#include"Texture.h"

using namespace std;

class Library
{
public:
	Library();
	~Library();

	void addToLibary(GameObject*object);
	GameObject* createObject(int type, float x, float y);


	vector<GameObject*> inventory;
};


#endif
