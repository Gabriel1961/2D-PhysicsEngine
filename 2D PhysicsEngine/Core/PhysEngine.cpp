#include "PhysEngine.h"
#include "Renderer.h"
#include "SDLRenderer.h"
#include <iostream>

Renderer* Core::PhysEngine::mRenderer = 0;
float Core::PhysEngine::mDeltaTime = 0;
float Core::PhysEngine::fixedDeltaTime = 1 / 60.f;
float Core::PhysEngine::mElapsedFixedTime = 0;
SDL_Renderer* Core::PhysEngine::GetSDLRenderer()
{
	return ((SDLRenderer*)mRenderer)->GetRenderer();
}

void Core::PhysEngine::LoadProject(Project& project)
{
	project.Load();
}

void Core::PhysEngine::RunProject(Project& project, Renderer& renderer)
{
	project.Start();
	renderer.Init();

	mRenderer = &renderer;
	
	while (!renderer.ShouldClose())
	{
		mDeltaTime = renderer.GetDeltaTime();
		
		for (; mElapsedFixedTime < GetElapsedTime(); mElapsedFixedTime += fixedDeltaTime)
			project.FixedUpdate();
		project.Update();
		renderer.StartRender();
		project.Render();
		renderer.EndRender();
		renderer.PollEvents();
	}

	project.Stop();
	renderer.Dispose();
}
