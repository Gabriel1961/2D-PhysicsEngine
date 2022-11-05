#pragma once
#include "Body.h"
class Spring
{
public:

	float springConst = 10;
	float initialLength = 100;

	float length;

	Body* body1 = 0;
	Body* body2 = 0;

	int visualWidth = 30;
	int visualSubdiv = 10;
	float damp = .1;

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

		
		body1->velocity -= (b2b1 * springForce) * PhysEngine::GetDeltaTime();
		body2->velocity += (b2b1 * springForce) * PhysEngine::GetDeltaTime();

		float relv = dot(body1->velocity,b2b1) + dot(body2->velocity,b2b1);

		body1->velocity -= b2b1 * relv * damp * PhysEngine::GetDeltaTime();
		body2->velocity -= b2b1 * relv * damp * PhysEngine::GetDeltaTime();
	}
};