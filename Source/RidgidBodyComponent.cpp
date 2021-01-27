#include "GameObject.h"
#include "ObjectDefinitions.h"
#include "RidgidBodyComponent.h"
#include "View.h"
#include "PhysicsDevice.h"
#include <string>

RidgidBody::RidgidBody(GameObject* owner, tinyxml2::XMLElement* componentElement,PhysicsDevice* physics,View* view) : Component(owner)
{
	float x;
	float y;
	float cx;
	float cy;
	float vx;
	float vy;
	componentElement->QueryFloatAttribute("x", &x);
	componentElement->QueryFloatAttribute("y", &y);
	
	componentElement->QueryFloatAttribute("vx", &vx);
	componentElement->QueryFloatAttribute("vy", &vy);
	
	componentElement->QueryFloatAttribute("cx", &cx);
	componentElement->QueryFloatAttribute("cy", &cy);
	angle = 0;
	position->x = x;
	position->y = y;
	center->x = cx;
	center->y = cy;
	velocity->x = vx;
	velocity-> y = vy;
	this->physics = physics;
	this->view = view;


}

RidgidBody::~RidgidBody() {}


void RidgidBody::initialize(SDL_Renderer* renderer, ObjectTemplate* temp)
{
	// get rid of this 

}

void RidgidBody::start() {}

GameObject* RidgidBody::update() {

	if (getOwner()->id == "01")
	{
		view->velocity->x = physics->getPosition(this).x - position->x;
		view->velocity->y= physics->getPosition(this).y - position->y;
		position->x = physics->getPosition(this).x;
		position->y = physics->getPosition(this).y;
		velocity->x = physics->getVelocity(this).x;
		velocity->y = physics->getVelocity(this).y;

		
	}
	else
	{
		position->x = position->x - view->velocity->x- view->camera->x;
		position->y = position->y - view->velocity->y- view->camera->y;
	}

	return nullptr;
}

void RidgidBody::finish() {}

void RidgidBody::setLinearImpulse(Vector2D position)
{
	
	physics->setLinearImpulse(this, position, Vector2D{ 30,30 });
}

void RidgidBody::setLinearVelocity(Vector2D position)
{
	physics->setLinearVelocity(this, position);
}
void RidgidBody::setPhysicsBody()
{
	PhysicsStats phys;
	phys.spinSpeed = 0;
	phys.density = 0;
	phys.friction = 1;
	phys.restitution = 1;
	phys.filter = 1;
	phys.linearDamping = 11;
	phys.angularDamping = 1;
	phys.center.x = center->x;
	phys.center.y = center->y;
	phys.bodyShape = BodyShape::Rectangle;
	
	BodyPresets preset{ Vector2D{position->x,position->y},angle,phys };
	physics->createFixture(this, preset);
}
void RidgidBody::setWallBody()
{
	PhysicsStats phys;
	phys.spinSpeed = 0;
	phys.density = 9999;
	phys.friction = 0;
	phys.restitution = 1;
	phys.filter = 1;
	phys.linearDamping = 11;
	phys.angularDamping = 1;
	phys.center.x = center->x;
	phys.center.y = center->y;
	phys.bodyShape = BodyShape::Rectangle;
	phys.bodyType = BodyType::Static;
	BodyPresets preset{ Vector2D{position->x,position->y},angle,phys };
	physics->createFixture(this, preset);
}

void RidgidBody::setActive()
{
	physics->setActive(this, true);
}
void RidgidBody::removeBody()
{
	physics->removeObject(this);
}