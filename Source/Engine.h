#ifndef ENGINE_H
#define ENGINE_H
#include "Timer.h"
#include "GraphicsDevice.h"
#include "ObjectFactory.h"
#include "TextureLibrary.h"
#include "InputHandler.h"
#include "Library.h"
#include "Battle.h"
#include"LevelEditor.h"
#include "PhysicsDevice.h"
#include "Overworld.h"
#include "tinyxml2.h"
#include "View.h"
#include <vector>
using namespace std;



class Engine
{

public:
	Engine(std::string path);
	~Engine();

	void loadLevel(std::string levelPath);
	void createBattleSpace();
	void createMovementSpace(int moveNum);
	void updateObjects();
	void update();
	void draw();
	bool run();


	int getScore() { return score; };


	bool detectCollision(GameObject* object1, GameObject* object2);// simple collistion detection

	shared_ptr<GameObject> getShip();
	void addToLibary(GameObject*object);
	void createObject(string type, float x, float y);
	void commandList(string command);
	void checkTime();

	

private:
	// get stuff
	vector<GameObject*> inventory;
	int time = 0;
	int timer = 0;
	int maxTime = 1800;
	int bTimer = 10;

	vector<GameObject*> objects;
	GameObject* player;
	unique_ptr <GraphicsDevice> gDevice=make_unique<GraphicsDevice>();

	// create input handler
	unique_ptr<InputHandler>input=make_unique <InputHandler>();

	// create library
	unique_ptr<TextureLibrary> library = make_unique<TextureLibrary>(gDevice.get());

	// create factory

	
	//Battle function
	unique_ptr <View> view = make_unique <View>();
	unique_ptr <Battle> battle = make_unique <Battle>();
	unique_ptr<LevelEditor> editor = make_unique<LevelEditor>(view.get());
	unique_ptr<PhysicsDevice> physics = make_unique<PhysicsDevice>(Vector2D{0.f,0.f});
	unique_ptr<Overworld> overworld = make_unique<Overworld>();
	unique_ptr<ObjectFactory> factory = make_unique<ObjectFactory>(input.get(), library.get(), battle.get(), editor.get(), physics.get(),overworld.get(),view.get());

	string imgPath = "./Assets/Images/";
	string xmlPath = "./Assets/Config/";

	// MiniMap


	///////////////

	bool paused{ 0 };
	bool isBattle = false;
	bool spaceCreated = false;
	bool gameOver;
	int score;
	bool freeCam = false;


	
	string current_map="";

};


#endif