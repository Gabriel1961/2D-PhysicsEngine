#pragma once
#include <glm/glm.hpp>
#include <functional>
#include "PathRenderer.h"
class Renderer
{
public:
	virtual void Init() = 0;
	virtual void StartRender() = 0;
	virtual void EndRender() = 0;
	virtual void PollEvents() = 0;
	virtual void Dispose() = 0;
	virtual bool ShouldClose() = 0;
	virtual float GetDeltaTime() = 0;
	virtual float GetElapsedTime() = 0;
	virtual glm::vec2 GetMousePos() = 0;
	virtual int GetMouseState() = 0;
	virtual glm::vec2 GetScreenSize() = 0;
	virtual void Draw(const PathRenderer&) = 0;
	virtual void DrawSpring(glm::vec2 p1, glm::vec2 p2,float width,int subdiv)=0;
};

