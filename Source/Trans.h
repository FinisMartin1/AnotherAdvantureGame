#ifndef TRANS_H
#define TRANS_H
#include"Component.h"
#include "tinyxml2.h"

class Trans :public Component
{
public:
	Trans(GameObject* owner, tinyxml2::XMLElement* componentElement);
	~Trans();
	void start();
	GameObject* update();
	void finish();
private:
	int alpha;
};

#endif // !TRANS_H
