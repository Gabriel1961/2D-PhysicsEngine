#pragma once
#include "Renderer.h"
#include "RendererCommon.h"

#include <SDL2/SDL.h>

#undef main
class SDLRenderer : public Renderer
{
private:
	SDL_bool mDone;
	SDL_Window* mWindow = NULL;
	SDL_Renderer* mRenderer = NULL;
	SDL_GLContext mGlContext;
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
	glm::ivec2 GetWindowSize() override;
	void DrawSpring(glm::vec2 p1, glm::vec2 p2,float width, int subdiv)override;
	float GetDeltaTime()override;
	float GetElapsedTime()override;
	void Draw(const PathRenderer& rend) override;
	SDL_Renderer* GetRenderer() { return mRenderer; }
};

