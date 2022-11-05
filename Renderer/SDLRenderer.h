#pragma once
#include "Renderer.h"
#include "RendererCommon.h"
#include <SDL2/SDL.h>
#undef main
class SDLRenderer : public Renderer
{
private:
	SDL_bool done;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Uint64 mTicksCount=0;
public:
	void Init()override;
	void StartRender() override;
	void EndRender()override;
	void PollEvents()override;
	void Dispose()override;
	bool ShouldClose()override;
	glm::vec2 GetMousePos() override;
	int GetMouseState() override;
	glm::vec2 GetScreenSize() override;
	void DrawSpring(glm::vec2 p1, glm::vec2 p2,float width, int subdiv)override;
	float GetDeltaTime()override;

	SDL_Renderer* GetRenderer() { return renderer; }
};

