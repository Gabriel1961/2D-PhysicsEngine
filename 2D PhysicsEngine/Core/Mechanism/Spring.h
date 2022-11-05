#pragma once
#include "Body.h"
class Spring
{
public:

	float springConst = 5;
	float initialLength = 100;

	float length;

	Body* body1 = 0;
	Body* body2 = 0;

	int visualWidth = 30;
	int visualSubdiv = 10;
	float damp = .4;

	void Render()
	{
		PhysEngine::GetRenderer()->DrawSpring(body1->position, body2->position, visualWidth, visualSubdiv);
	}

	void Update()
	{
		vec2 dif = body1->position - body2->position;
		length = glm::length(dif);
		float springForce = (length - initialLength) * springConst;
		vec2 b2b1 = normalize(dif);

		float relv = glm::length(body1->velocity - body2->velocity);
		
		body1->velocity -= (b2b1 * springForce - relv*damp) * PhysEngine::GetDeltaTime();
		body2->velocity += (b2b1 * springForce - relv*damp) * PhysEngine::GetDeltaTime();


	}
};