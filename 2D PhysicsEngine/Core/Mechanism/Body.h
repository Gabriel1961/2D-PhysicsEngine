#pragma once
#include "../EngineCommon.h"
#include "../Interfaces/ITransform.h"
class Body : public ITransform2D
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

	void Update(float deltaTime) override
	{
		if (isFixed)
		{
			velocity = { 0,0 };
			return;
		}
		velocity += glm::vec2(0,1) * gravity * deltaTime;
		position += velocity * deltaTime;
	}

	vec2 GetPos() override { return position; }
};