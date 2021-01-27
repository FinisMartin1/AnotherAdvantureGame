#include "ContactListener.h"
#include "Component.h"
#include "GameObject.h"




ContactListener::ContactListener()
{
	
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	//Grab the two Physics Bodies involved in the Contact
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	// Don't do anything special with boundaries
	if (bodyA->GetType() == b2BodyType::b2_staticBody || bodyB->GetType() == b2BodyType::b2_staticBody)
		return;

	//Cast them to object pointers
GameObject* objectA = static_cast<Component*>(bodyA->GetUserData())->getOwner();
GameObject* objectB = static_cast<Component*>(bodyB->GetUserData())->getOwner();

	if (objectA == nullptr || objectB == nullptr)return;
	bool proceed{ true };

	// weed out ghost hulls

}

