#pragma once
#include "../EngineCommon.h"
class Body
{
public:

	float mass{};
	vec2 position{};
	vec2 velocity{};
	
	float gravity = 400;
	bool isFixed = false;

	ivec2 visualSize = {20,20};
	SDL_Rect visualRect;

	void Render()
	{
		visualRect = {
			(int)( position.x - visualSize.x/2),
			(int)( position.y - visualSize.y/2),
			visualSize.x,
			visualSize.y};
		
		SDL_RenderDrawRect(Core::PhysEngine::GetSDLRenderer(), &visualRect);
	}

	void Update()
	{
		if (isFixed)
		{
			velocity = { 0,0 };
			return;
		}
		velocity += glm::vec2(0,1) * gravity * PhysEngine::GetDeltaTime();
		position += velocity * PhysEngine::GetDeltaTime();
		//printf("%f\n", PhysEngine::GetDeltaTime());
	}
};